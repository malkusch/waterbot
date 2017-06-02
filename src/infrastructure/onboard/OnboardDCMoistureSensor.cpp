/*
 * OnboardDCMoistureSensor.cpp
 *
 *  Created on: 31.05.2017
 *      Author: malkusch
 */

#include "OnboardDCMoistureSensor.h"

using waterbot::infrastructure::onboard::OnboardDCMoistureSensor;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

OnboardDCMoistureSensor::OnboardDCMoistureSensor(DigitalOutputPin* voltagePin,
		AnalogInputPin* sensorPin, byte readCount,
		unsigned int voltageDelayMillis) :
		AnalogMoistureSensor(sensorPin, readCount), voltagePin(voltagePin), voltageDelayMillis(
				voltageDelayMillis) {

	turnOffVoltage();
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
	voltagePin->write(ON);

	/*
	 * Wait until any capacitive or inductive effects of the wire
	 * are eliminated.
	 */
	delay(voltageDelayMillis);
}

void OnboardDCMoistureSensor::turnOffVoltage() {
	voltagePin->write(OFF);
}
