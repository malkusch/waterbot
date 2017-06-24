/*
 * AM2321Sensor.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include "../../model/MoistureSensor.h"
#include "../../model/TemperatureSensor.h"
#include "../pin/DigitalOutputPin.h"

using waterbot::infrastructure::pin::DigitalOutputPin;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class AM2321Sensor: public MoistureSensor, public TemperatureSensor {
public:
	AM2321Sensor(DigitalOutputPin*);
	virtual int readMoisture();
	virtual float readTemperature();

private:
	DigitalOutputPin* powerPin;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

