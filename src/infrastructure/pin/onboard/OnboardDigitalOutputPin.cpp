/*
 * OnboardDigitalOutputPin.cpp
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#include "OnboardDigitalOutputPin.h"

using waterbot::infrastructure::pin::onboard::OnboardDigitalOutputPin;

OnboardDigitalOutputPin::OnboardDigitalOutputPin(const byte pin) :
		pin(pin) {

	pinMode(pin, OUTPUT);
}

void OnboardDigitalOutputPin::write(const State state) {
	digitalWrite(pin, state == ON ? HIGH : LOW);
}
