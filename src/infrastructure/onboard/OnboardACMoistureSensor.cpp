/*
 * MoistureSensor.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "OnboardACMoistureSensor.h"

using waterbot::infrastructure::onboard::OnboardACMoistureSensor;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

OnboardACMoistureSensor::OnboardACMoistureSensor(DigitalOutputPin* voltagePin1,
		DigitalOutputPin* voltagePin2, AnalogInputPin* sensorPin,
		byte readCount, unsigned int voltageDelayMillis) :
		AnalogMoistureSensor(sensorPin, readCount), voltagePin1(voltagePin1), voltagePin2(
				voltagePin2), voltageDelayMillis(voltageDelayMillis) {

	pin1ToPin2 = true;
	turnOffVoltageWithoutDelay();
}

void OnboardACMoistureSensor::readRawMoisture(float data[],
		const byte readCount) {

	turnOnVoltage();

	byte i;
	for (i = 0; i < readCount / 2; i++) {
		data[i] = singleReadMoisture();
	}

	switchPolarity();

	for (i++; i < readCount; i++) {
		data[i] = singleReadMoisture();
	}

	turnOffVoltage();
}

int OnboardACMoistureSensor::singleReadMoisture() {
	int moisture = AnalogMoistureSensor::singleReadMoisture();
	return pin1ToPin2 ? moisture : (1023 - moisture);
}

void OnboardACMoistureSensor::turnOnVoltage() {
	if (pin1ToPin2) {
		voltagePin2->write(OFF);
		voltagePin1->write(ON);
	} else {
		voltagePin1->write(OFF);
		voltagePin2->write(ON);
	}

	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardACMoistureSensor::switchPolarity() {
	turnOffVoltage();
	pin1ToPin2 = !pin1ToPin2;
	turnOnVoltage();
}

void OnboardACMoistureSensor::turnOffVoltage() {
	turnOffVoltageWithoutDelay();
	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardACMoistureSensor::turnOffVoltageWithoutDelay() {
	voltagePin1->write(OFF);
	voltagePin2->write(OFF);
}
