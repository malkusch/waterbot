/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef ONBOARD_DCMOISTURESENSOR_H_
#define ONBOARD_DCMOISTURESENSOR_H_

#include <Arduino.h>

#include "AnalogMoistureSensor.h"

class OnboardDCMoistureSensor: public AnalogMoistureSensor {

public:
	OnboardDCMoistureSensor(byte voltagePin, byte sensorPin, byte readCount,
			unsigned int voltageDelayMillis);

protected:
	virtual void readRawMoisture(float data[], const byte readCount);

private:
	const byte voltagePin;
	const unsigned int voltageDelayMillis;

	void turnOnVoltage();
	void turnOffVoltage();
	void turnOffVoltageWithoutDelay();
};

#endif /* ONBOARD_MOISTURESENSOR_H_ */
