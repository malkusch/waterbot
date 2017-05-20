/*
 * OnboardValve.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "OnboardValve.h"

OnboardValve::OnboardValve(byte pin, unsigned int delayMillis) :
		pin(pin), delayMillis(delayMillis) {

	pinMode(pin, OUTPUT);
	closeWithoutDelay(); // You can't delay within a constructor
}

void OnboardValve::open() {
	digitalWrite(pin, HIGH);
	delay(delayMillis);
}

void OnboardValve::close() {
	closeWithoutDelay();
	delay(delayMillis);
}

void OnboardValve::closeWithoutDelay() {
	digitalWrite(pin, LOW);
}
