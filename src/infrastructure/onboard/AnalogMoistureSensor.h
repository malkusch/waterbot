/*
 * AnalogMoistureSensor.h
 *
 *  Created on: 31.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../../model/MoistureSensor.h"
#include "../pin/AnalogInputPin.h"

using waterbot::infrastructure::pin::AnalogInputPin;

namespace waterbot {
namespace infrastructure {
namespace onboard {

class AnalogMoistureSensor: public MoistureSensor {
public:
	AnalogMoistureSensor(AnalogInputPin* sensorPin, const byte readCount);
	virtual ~AnalogMoistureSensor() {
	}
	;

	int readMoisture();

protected:
	virtual int singleReadMoisture();
	virtual void readRawMoisture(float data[], const byte readCount) = 0;

private:
	AnalogInputPin* sensorPin;
	const byte readCount;
};

}
}
}
