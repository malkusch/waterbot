/*
 * RetryingSensor.h
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#pragma once

#include "../../model/Sensor.h"
#include "../../model/SensorData.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

class RetryingSensor: public Sensor {
private:
	Sensor* sensor;
public:
	RetryingSensor(Sensor*);
	virtual SensorData read();
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

