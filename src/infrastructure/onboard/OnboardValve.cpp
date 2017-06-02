/*
 * OnboardValve.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "OnboardValve.h"

using waterbot::infrastructure::onboard::OnboardValve;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

OnboardValve::OnboardValve(DigitalOutputPin* pin, unsigned int delayMillis) :
		pin(pin), delayMillis(delayMillis) {

	closeWithoutDelay(); // You can't delay within a constructor
}

void OnboardValve::open() {
	pin->write(ON);
	delay(delayMillis);
}

void OnboardValve::close() {
	closeWithoutDelay();
	delay(delayMillis);
}

void OnboardValve::closeWithoutDelay() {
	pin->write(OFF);
}
