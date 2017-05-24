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
		byte sensorPin, byte readCount, unsigned int readMillis) :
		voltagePin1(voltagePin1), voltagePin2(voltagePin2), sensorPin(
				sensorPin), readCount(readCount), readMillis(readMillis) {

	pin1ToPin2 = true;

	pinMode(sensorPin, INPUT);
	pinMode(voltagePin1, OUTPUT);
	pinMode(voltagePin2, OUTPUT);
	standby();
}

int OnboardMoistureSensor::readMoisture() {
	float data[readCount];
	for (byte i = 0; i < readCount; i++) {
		data[i] = singleReadMoisture();
	}
	standby();

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
	switchPolarity();
	delay(readMillis);
	int moisture = analogRead(sensorPin);

	/*
	 *  It turns out the wires save some energy which affects the next
	 *  reading. A short delay should remove that energy to ground.
	 */
	standby();
	delay(readMillis * 5);

	return pin1ToPin2 ? (1023 - moisture) : moisture;
}

void OnboardMoistureSensor::switchPolarity() {
	if (pin1ToPin2) {
		digitalWrite(voltagePin2, LOW);
		digitalWrite(voltagePin1, HIGH);
	} else {
		digitalWrite(voltagePin1, LOW);
		digitalWrite(voltagePin2, HIGH);
	}
	pin1ToPin2 = !pin1ToPin2;
}

void OnboardMoistureSensor::standby() {
	digitalWrite(voltagePin1, LOW);
	digitalWrite(voltagePin2, LOW);
}
