/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef ONBOARD_MOISTURESENSOR_H_
#define ONBOARD_MOISTURESENSOR_H_

#include <Arduino.h>

#include "AnalogMoistureSensor.h"

class OnboardACMoistureSensor: public AnalogMoistureSensor {

public:
	OnboardACMoistureSensor(byte voltagePin1, byte voltagePin2, byte sensorPin,
			byte readCount, unsigned int voltageDelayMillis);

protected:
	virtual int singleReadMoisture();
	virtual void readRawMoisture(float data[], const byte readCount);

private:
	const byte voltagePin1;
	const byte voltagePin2;
	const unsigned int voltageDelayMillis;bool pin1ToPin2;

	void turnOnVoltage();
	void switchPolarity();
	void turnOffVoltage();
	void turnOffVoltageWithoutDelay();
};

#endif /* ONBOARD_MOISTURESENSOR_H_ */
