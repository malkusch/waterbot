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

class OnboardDCMoistureSensor: public AnalogMoistureSensor {

public:
	OnboardDCMoistureSensor(DigitalOutputPin* voltagePin,
			AnalogInputPin* sensorPin, byte readCount,
			unsigned int voltageDelayMillis);

protected:
	virtual void readRawMoisture(float data[], const byte readCount);

private:
	DigitalOutputPin* voltagePin;
	const unsigned int voltageDelayMillis;

	void turnOnVoltage();
	void turnOffVoltage();
};

}
}
}
