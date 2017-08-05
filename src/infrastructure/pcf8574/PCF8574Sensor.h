/*
 * PCF8574Sensor.h
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#pragma once

#include "BusSwitch.h"
#include "../../model/Sensor.h"

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class PCF8574Sensor: public Sensor {
public:
	PCF8574Sensor(BusSwitch*);
	virtual SensorData read();
	virtual void begin();

private:
	BusSwitch* busSwitch;
	Sensor* sensor;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

