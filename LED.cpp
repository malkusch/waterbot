/*
 * LED.cpp
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#include "LED.h"

#include <Arduino.h>

LED::LED(byte pin) :
		pin(pin) {

	pinMode(pin, OUTPUT);
	turnOff();
}

void LED::turnOn() const {
	digitalWrite(pin, HIGH);
}

void LED::turnOff() const {
	digitalWrite(pin, LOW);
}

