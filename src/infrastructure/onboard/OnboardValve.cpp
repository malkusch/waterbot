/*
 * OnboardValve.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "OnboardValve.h"

OnboardValve::OnboardValve(byte pin) :
		pin(pin) {

	pinMode(pin, OUTPUT);
	close();
}

void OnboardValve::open() {
	digitalWrite(pin, HIGH);
}

void OnboardValve::close() {
	digitalWrite(pin, LOW);
}
