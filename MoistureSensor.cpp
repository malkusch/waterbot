/*
 * MoistureSensor.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "MoistureSensor.h"

#include <Arduino.h>

MoistureSensor::MoistureSensor(byte voltagePin1, byte voltagePin2, byte sensorPin,
		byte readCount, unsigned int readMillis) :
		voltagePin1(voltagePin1), voltagePin2(voltagePin2), sensorPin(
				sensorPin), readCount(readCount), readMillis(readMillis) {

	pin1ToPin2 = true;
	standby();
}

int MoistureSensor::readMoisture() {
	unsigned int sum = 0;
	for (byte i = 0; i < readCount; i++) {
		switchPolarity();
		delay(readMillis);
		sum += singleReadMoisture();
	}
	standby();
	int moisture = sum / readCount;
	return moisture;
}

int MoistureSensor::singleReadMoisture() {
	int moisture = analogRead(sensorPin);
	return pin1ToPin2 ? moisture : (1023 - moisture);
}

void MoistureSensor::switchPolarity() {
	if (pin1ToPin2) {
		digitalWrite(voltagePin2, LOW);
		digitalWrite(voltagePin1, HIGH);
	} else {
		digitalWrite(voltagePin1, LOW);
		digitalWrite(voltagePin2, HIGH);
	}
	pin1ToPin2 = !pin1ToPin2;
}

void MoistureSensor::standby() {
	digitalWrite(voltagePin1, LOW);
	digitalWrite(voltagePin2, LOW);
}
