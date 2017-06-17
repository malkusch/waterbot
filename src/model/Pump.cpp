/*
 * Pump.cpp
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#include "Pump.h"

#include "../infrastructure/TimeUnits.h"

using waterbot::model::Pump;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

Pump::Pump(DigitalOutputPin* pin, unsigned int turnOffDelayMillis) :
		pin(pin), turnOffDelayMillis(turnOffDelayMillis) {

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
	pin->write(OFF);
}

void Pump::turnOn() {
	pin->write(ON);
}
