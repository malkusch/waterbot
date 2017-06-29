/*
 * OnboardValve.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "Valve.h"

using waterbot::model::Valve;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

Valve::Valve(DigitalOutputPin* pin, const unsigned int delayMillis) :
		pin(pin), delayMillis(delayMillis) {

	closeWithoutDelay(); // You can't delay within a constructor
}

void Valve::open() {
	pin->write(ON);
	delay(delayMillis);
}

void Valve::close() {
	closeWithoutDelay();
	delay(delayMillis);
}

void Valve::closeWithoutDelay() {
	pin->write(OFF);
}
