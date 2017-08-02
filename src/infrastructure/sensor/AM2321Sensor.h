/*
 * AM2321Sensor.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include "../../model/Sensor.h"
#include "../../model/SensorData.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

class AM2321Sensor: public Sensor {

public:
	static bool isPluggedIn();
	virtual SensorData read();
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

