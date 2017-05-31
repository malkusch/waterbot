/*
 * OnboardDCMoistureSensor.cpp
 *
 *  Created on: 31.05.2017
 *      Author: malkusch
 */

#include "OnboardDCMoistureSensor.h"

OnboardDCMoistureSensor::OnboardDCMoistureSensor(byte voltagePin,
		byte sensorPin, byte readCount, unsigned int voltageDelayMillis) :
		AnalogMoistureSensor(sensorPin, readCount), voltagePin(voltagePin), voltageDelayMillis(
				voltageDelayMillis) {

	pinMode(voltagePin, OUTPUT);
	turnOffVoltageWithoutDelay();
}

void OnboardDCMoistureSensor::readRawMoisture(float data[],
		const byte readCount) {

	turnOnVoltage();
	for (byte i = 0; i < readCount; i++) {
		data[i] = singleReadMoisture();
	}
	turnOffVoltage();
}

void OnboardDCMoistureSensor::turnOnVoltage() {
	digitalWrite(voltagePin, HIGH);

	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardDCMoistureSensor::turnOffVoltage() {
	turnOffVoltageWithoutDelay();
	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardDCMoistureSensor::turnOffVoltageWithoutDelay() {
	digitalWrite(voltagePin, LOW);
}

