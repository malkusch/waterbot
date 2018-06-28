/*
 * BusSwitch.h
 *
 *  Created on: 04.08.2017
 *      Author: malkusch
 */

#pragma once

#include "pin/DigitalOutputPin.h"

using waterbot::infrastructure::pin::DigitalOutputPin;

namespace waterbot {
namespace infrastructure {

class BusSwitch {

public:

	BusSwitch(DigitalOutputPin*);
	virtual void turnOn();
	virtual void turnOff();

private:

	DigitalOutputPin* pin;

};

} /* namespace infrastructure */
} /* namespace waterbot */

