/*
 * BusSwitch.cpp
 *
 *  Created on: 04.08.2017
 *      Author: malkusch
 */

#include "PCF8574BusSwitch.h"

#include <Wire.h>

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574BusSwitch::PCF8574BusSwitch(DigitalOutputPin* pin) :
		BusSwitch(pin) {
}

void PCF8574BusSwitch::turnOff() {
	BusSwitch::turnOff();
	Wire.endTransmission();
}

void PCF8574BusSwitch::turnOn() {
	BusSwitch::turnOn();
	Wire.endTransmission();
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
