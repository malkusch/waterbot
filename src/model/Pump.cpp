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
	turnOff();
}

void Pump::pump() {
	turnOn();
	delay(TimeUnits::secondsToMillis(pumpSeconds));
	turnOff();
}

void Pump::turnOff() {
	digitalWrite(pin, HIGH);
	delay(turnOffDelayMillis);
}

void Pump::turnOn() {
	digitalWrite(pin, LOW);
}

