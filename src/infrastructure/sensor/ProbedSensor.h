/*
 * PCF8574Sensor.h
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#pragma once

#include "../BusSwitch.h"
#include "../../model/Sensor.h"

using waterbot::infrastructure::BusSwitch;

namespace waterbot {
namespace infrastructure {
namespace sensor {

class ProbedSensor: public Sensor {
public:
	ProbedSensor(BusSwitch*);
	virtual SensorData read();
	virtual bool begin();

private:
	BusSwitch* busSwitch;
	Sensor* sensor;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

