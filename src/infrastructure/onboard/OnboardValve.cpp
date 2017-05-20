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
	close();
}

void OnboardValve::open() {
	digitalWrite(pin, HIGH);
	delay(delayMillis);
}

void OnboardValve::close() {
	digitalWrite(pin, LOW);
	delay(delayMillis);
}
