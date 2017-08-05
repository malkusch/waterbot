/*
 * BusSwitch.h
 *
 *  Created on: 04.08.2017
 *      Author: malkusch
 */

#pragma once

#include "../pin/DigitalOutputPin.h"

using waterbot::infrastructure::pin::DigitalOutputPin;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class BusSwitch {

public:

	BusSwitch(DigitalOutputPin*);
	void turnOn();
	void turnOff();

private:

	DigitalOutputPin* pin;

};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

