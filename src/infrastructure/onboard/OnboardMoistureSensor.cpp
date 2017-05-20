/*
 * MoistureSensor.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "OnboardMoistureSensor.h"

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
	unsigned long sum = 0;
	for (byte i = 0; i < readCount; i++) {
		switchPolarity();
		delay(readMillis);
		sum += singleReadMoisture();
	}
	standby();
	int moisture = sum / readCount;
	return moisture;
}

int OnboardMoistureSensor::singleReadMoisture() {
	int moisture = analogRead(sensorPin);
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
