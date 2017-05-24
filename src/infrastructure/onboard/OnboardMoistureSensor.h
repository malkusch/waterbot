/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef ONBOARD_MOISTURESENSOR_H_
#define ONBOARD_MOISTURESENSOR_H_

#include <Arduino.h>
#include "../../model/MoistureSensor.h"
class OnboardMoistureSensor: public MoistureSensor {

public:
	OnboardMoistureSensor(byte voltagePin1, byte voltagePin2, byte sensorPin,
			byte halfReadCount, unsigned int voltageDelayMillis);
	virtual int readMoisture();

private:
	const byte voltagePin1;
	const byte voltagePin2;
	const byte sensorPin;
	const byte halfReadCount;
	const unsigned int voltageDelayMillis;bool pin1ToPin2;

	int singleReadMoisture();
	void turnOnVoltage();
	void switchPolarity();
	void turnOffVoltage();
	void turnOffVoltageWithoutDelay();
};

#endif /* ONBOARD_MOISTURESENSOR_H_ */
