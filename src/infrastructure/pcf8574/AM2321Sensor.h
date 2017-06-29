/*
 * AM2321Sensor.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include "../pin/DigitalOutputPin.h"
#include "../../model/Sensor.h"

using waterbot::infrastructure::pin::DigitalOutputPin;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class AM2321Sensor: public Sensor {
public:
	AM2321Sensor(DigitalOutputPin*);
	virtual SensorData read();

private:
	DigitalOutputPin* busSwitch;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

