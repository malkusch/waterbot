/*
 * CD74HC4067Input.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "CD74HC4067Input.h"

using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067Input;

CD74HC4067Input::CD74HC4067Input(const byte ioPin, const byte s0Pin,
		const byte s1Pin, const byte s2Pin, const byte s3Pin, const byte ePin) :
		CD74HC4067(ioPin, s0Pin, s1Pin, s2Pin, s3Pin, ePin) {

	pinMode(ioPin, INPUT);
}

int CD74HC4067Input::analogRead(const byte channel) {
	if (!isSelected(channel)) {
		startSelectChannel();
		selectChannel(channel);
		commitSelectChannel();
	}
	return ::analogRead(ioPin);
}
