/*
 * Pump.cpp
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#include "Pump.h"

#include "../infrastructure/TimeUnits.h"

Pump::Pump(byte pin, byte pumpSeconds, unsigned int turnOffDelayMillis) :
		pin(pin), pumpSeconds(pumpSeconds), turnOffDelayMillis(
				turnOffDelayMillis) {

	pinMode(pin, OUTPUT);
	turnOffWithoutDelay(); // You can't delay within a constructor
}

void Pump::pump() {
	turnOn();
	delay(TimeUnits::secondsToMillis(pumpSeconds));
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

