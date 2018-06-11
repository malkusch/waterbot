/*
 * BME280Sensor.h
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#pragma once

#include "../../model/Sensor.h"
#include "../../model/SensorData.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

class BME280Sensor: public Sensor {
public:
	virtual SensorData read();
	virtual bool begin();
	static bool isPluggedIn();
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

