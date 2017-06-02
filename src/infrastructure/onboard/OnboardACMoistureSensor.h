/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "AnalogMoistureSensor.h"
#include "../pin/DigitalOutputPin.h"

namespace waterbot {
namespace infrastructure {
namespace onboard {

using pin::DigitalOutputPin;

class OnboardACMoistureSensor: public AnalogMoistureSensor {

public:
	OnboardACMoistureSensor(DigitalOutputPin* voltagePin1,
			DigitalOutputPin* voltagePin2, AnalogInputPin* sensorPin,
			byte readCount, unsigned int voltageDelayMillis);

protected:
	virtual int singleReadMoisture();
	virtual void readRawMoisture(float data[], const byte readCount);

private:
	DigitalOutputPin* voltagePin1;
	DigitalOutputPin* voltagePin2;
	const unsigned int voltageDelayMillis;bool pin1ToPin2;

	void turnOnVoltage();
	void switchPolarity();
	void turnOffVoltage();
	void turnOffVoltageWithoutDelay();
};

}
}
}
