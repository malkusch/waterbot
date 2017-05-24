/*
 * MoistureSensor.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "OnboardMoistureSensor.h"

#include "../../../libraries/QuickStats/QuickStats.h"
#include "../logger/Logger.h"

OnboardMoistureSensor::OnboardMoistureSensor(byte voltagePin1, byte voltagePin2,
		byte sensorPin, byte halfReadCount, unsigned int voltageDelayMillis) :
		voltagePin1(voltagePin1), voltagePin2(voltagePin2), sensorPin(
				sensorPin), halfReadCount(halfReadCount), voltageDelayMillis(
				voltageDelayMillis) {

	pin1ToPin2 = true;

	pinMode(sensorPin, INPUT);
	pinMode(voltagePin1, OUTPUT);
	pinMode(voltagePin2, OUTPUT);
	turnOffVoltageWithoutDelay();
}

int OnboardMoistureSensor::readMoisture() {
	const byte readCount = halfReadCount * 2;
	float data[readCount];

	turnOnVoltage();

	for (byte i = 0; i < halfReadCount; i++) {
		data[i] = singleReadMoisture();
	}

	switchPolarity();

	for (byte i = halfReadCount; i < readCount; i++) {
		data[i] = singleReadMoisture();
	}

	turnOffVoltage();

	QuickStats stats;
	float median = stats.median(data, readCount);
	float error = stats.stderror(data, readCount);

	String debugError;
	debugError += "Sensor at pin " + String(sensorPin) + " has " + error
			+ " error";
	Logger::getLogger()->debug(debugError);

	if (median < 10) {
		String warning;
		warning += "Sensor " + String(sensorPin) + " reads too low: " + median;
		Logger::getLogger()->warn(warning);
	}
	if (median > 1023 - 10) {
		String warning;
		warning += "Sensor " + String(sensorPin) + " reads too high: " + median;
		Logger::getLogger()->warn(warning);
	}
	if (error > 50) {
		String warning;
		warning += "Sensor " + String(sensorPin) + " has too much error: "
				+ error;
		Logger::getLogger()->warn(warning);
	}

	return median;
}

int OnboardMoistureSensor::singleReadMoisture() {
	int moisture = analogRead(sensorPin);
	return pin1ToPin2 ? (1023 - moisture) : moisture;
}

void OnboardMoistureSensor::turnOnVoltage() {
	if (pin1ToPin2) {
		digitalWrite(voltagePin2, LOW);
		digitalWrite(voltagePin1, HIGH);
	} else {
		digitalWrite(voltagePin1, LOW);
		digitalWrite(voltagePin2, HIGH);
	}

	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardMoistureSensor::switchPolarity() {
	turnOffVoltage();
	pin1ToPin2 = !pin1ToPin2;
	turnOnVoltage();
}

void OnboardMoistureSensor::turnOffVoltage() {
	turnOffVoltageWithoutDelay();
	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardMoistureSensor::turnOffVoltageWithoutDelay() {
	digitalWrite(voltagePin1, LOW);
	digitalWrite(voltagePin2, LOW);
}
