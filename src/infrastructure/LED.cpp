/*
 * LED.cpp
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#include "LED.h"

LED::LED(const byte pin) :
		pin(pin) {

	pinMode(pin, OUTPUT);
	turnOff();
}

void LED::turnOn() {
	digitalWrite(pin, HIGH);
}

void LED::turnOff() {
	digitalWrite(pin, LOW);
}

