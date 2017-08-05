/*
 * BusSwitch.cpp
 *
 *  Created on: 04.08.2017
 *      Author: malkusch
 */

#include "BusSwitch.h"

#include <Wire.h>

using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

BusSwitch::BusSwitch(DigitalOutputPin* pin) :
		pin(pin) {

	turnOff();
}

void BusSwitch::turnOff() {
	pin->write(OFF);
	Wire.endTransmission();
}

void BusSwitch::turnOn() {
	pin->write(ON);
	Wire.endTransmission();
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
