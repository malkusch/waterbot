/*
 * PCF8574Sensor.h
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#pragma once

#include "../pin/DigitalOutputPin.h"
#include "../../model/Sensor.h"

using waterbot::infrastructure::pin::DigitalOutputPin;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class PCF8574Sensor: public Sensor {
public:
	PCF8574Sensor(DigitalOutputPin* busSwitch);
	virtual SensorData read();
	virtual void begin();

private:
	DigitalOutputPin* busSwitch;
	Sensor* sensor;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

