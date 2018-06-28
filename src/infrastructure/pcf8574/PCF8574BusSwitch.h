/*
 * PCF8574BusSwitch.h
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#pragma once

#include "../BusSwitch.h"

using waterbot::infrastructure::BusSwitch;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class PCF8574BusSwitch: public BusSwitch {

public:
	PCF8574BusSwitch(DigitalOutputPin*);
	virtual void turnOn();
	virtual void turnOff();

};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

