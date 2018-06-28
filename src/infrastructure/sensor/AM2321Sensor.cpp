/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <AM2321/AM2321.h>

namespace waterbot {
namespace infrastructure {
namespace sensor {

bool AM2321Sensor::isPluggedIn() {
	AM2321 am2321;
	return am2321.read();
}

SensorData AM2321Sensor::read() {
	AM2321 am2321;
	if (!am2321.read()) {
		return Sensor::ERROR;
	}
	SensorData data;
	data.moisture = am2321.humidity / 1000.0;
	data.temperature = am2321.temperature / 10.0;
	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
