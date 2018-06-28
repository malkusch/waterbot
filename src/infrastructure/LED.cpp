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
		pin(pin), on(false) {

	turnOff();
}

void LED::change() {
	on ? turnOff() : turnOn();
}

void LED::turnOn() {
	pin->write(ON);
	on = true;
}

void LED::turnOff() {
	pin->write(OFF);
	on = false;
}

