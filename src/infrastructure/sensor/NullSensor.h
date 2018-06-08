/*
 * NullSensor.h
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

class NullSensor: public Sensor {

public:
	virtual SensorData read();
};

}
}
}
