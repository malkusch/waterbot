/*
 * OnboardAnalogInputPin.cpp
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#include "OnboardAnalogInputPin.h"

using waterbot::infrastructure::pin::onboard::OnboardAnalogInputPin;

OnboardAnalogInputPin::OnboardAnalogInputPin(const byte pin) :
		pin(pin) {

	pinMode(pin, INPUT);
}

int OnboardAnalogInputPin::read() {
	return analogRead(pin);
}

String OnboardAnalogInputPin::toString() {
	return String(pin);
}
