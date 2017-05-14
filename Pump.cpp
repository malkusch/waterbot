/*
 * Pump.cpp
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#include "Pump.h"

#include "TimeUnits.h"

Pump::Pump(byte pin, unsigned int coolDownSeconds, byte pumpSeconds) :
		pin(pin), coolDownSeconds(coolDownSeconds), pumpSeconds(pumpSeconds) {

	pinMode(pin, OUTPUT);
	turnOff();
	lastPumpTime = millis();
}

void Pump::pump() {
	lastPumpTime = millis();
	turnOn();
	delay(TimeUnits::secondsToMillis(pumpSeconds));
	turnOff();
}

bool Pump::isHot() {
	unsigned long earliestPumpTime = lastPumpTime
			+ TimeUnits::secondsToMillis(coolDownSeconds);
	return earliestPumpTime > millis();
}

void Pump::turnOff() {
	digitalWrite(pin, HIGH);
}

void Pump::turnOn() {
	digitalWrite(pin, LOW);
}

