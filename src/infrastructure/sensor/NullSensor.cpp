/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "NullSensor.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

SensorData NullSensor::read() {
	SensorData data;
	data.moisture = 0;
	data.temperature = 0;
	return data;
}

}
}
}
