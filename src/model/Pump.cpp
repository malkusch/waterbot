/*
 * Pump.cpp
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#include "Pump.h"

#include "../infrastructure/TimeUnits.h"

Pump::Pump(byte pin, unsigned int turnOffDelayMillis) :
		pin(pin), turnOffDelayMillis(turnOffDelayMillis) {

	pinMode(pin, OUTPUT);
	turnOffWithoutDelay(); // You can't delay within a constructor
}

void Pump::pump(byte seconds) {
	turnOn();
	delay(TimeUnits::secondsToMillis(seconds));
	turnOff();
}

void Pump::turnOff() {
	turnOffWithoutDelay();
	delay(turnOffDelayMillis);
}

void Pump::turnOffWithoutDelay() {
	digitalWrite(pin, HIGH);
}

void Pump::turnOn() {
	digitalWrite(pin, LOW);
}

