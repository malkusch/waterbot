/*
 * CD74HC4067Output.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "CD74HC4067Output.h"

using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067Output;

CD74HC4067Output::CD74HC4067Output(const byte ioPin, const byte s0Pin,
		const byte s1Pin, const byte s2Pin, const byte s3Pin, const byte ePin) :
		CD74HC4067(ioPin, s0Pin, s1Pin, s2Pin, s3Pin, ePin) {

	pinMode(ioPin, OUTPUT);
	digitalWrite(ioPin, LOW);
}

void CD74HC4067Output::write(const byte channel, const State state) {
	if (!isSelected(channel)) {
		startSelectChannel();
		selectChannel(channel);
		digitalWrite(ioPin, state == ON ? HIGH : LOW);
		commitSelectChannel();

	} else {
		digitalWrite(ioPin, state == ON ? HIGH : LOW);
	}
}
