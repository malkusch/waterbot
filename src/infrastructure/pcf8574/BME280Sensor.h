/*
 * BME280Sensor.h
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

class BME280Sensor: public Sensor {
public:
	BME280Sensor(DigitalOutputPin* busSwitch);
	virtual SensorData read();
	void init();

private:
	DigitalOutputPin* busSwitch;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

