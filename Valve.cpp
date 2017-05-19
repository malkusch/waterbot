/*
 * Valve.cpp
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#include "Valve.h"

Valve::Valve(byte pin) :
		pin(pin) {

	pinMode(pin, OUTPUT);
	close();
}

void Valve::open() const {
	digitalWrite(pin, HIGH);
}

void Valve::close() const {
	digitalWrite(pin, LOW);
}
