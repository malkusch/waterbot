/*
 * LED.cpp
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#include "LED.h"

using waterbot::infrastructure::LED;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

LED::LED(DigitalOutputPin* pin) :
		pin(pin) {

	turnOff();
}

void LED::turnOn() {
	pin->write(ON);
}

void LED::turnOff() {
	pin->write(OFF);
}

