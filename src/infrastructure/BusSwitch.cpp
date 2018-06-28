/*
 * BusSwitch.cpp
 *
 *  Created on: 04.08.2017
 *      Author: malkusch
 */

#include "BusSwitch.h"

using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

namespace waterbot {
namespace infrastructure {

BusSwitch::BusSwitch(DigitalOutputPin* pin) :
		pin(pin) {

	turnOff();
}

void BusSwitch::turnOff() {
	pin->write(OFF);
}

void BusSwitch::turnOn() {
	pin->write(ON);
}

} /* namespace infrastructure */
} /* namespace waterbot */
