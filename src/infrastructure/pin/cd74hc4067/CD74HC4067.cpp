/*
 * CD74HC4067.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "CD74HC4067.h"

using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067;

CD74HC4067::CD74HC4067(const byte ioPin, const byte s0Pin, const byte s1Pin,
		const byte s2Pin, const byte s3Pin, const byte ePin) :
		ioPin(ioPin), s0Pin(s0Pin), s1Pin(s1Pin), s2Pin(s2Pin), s3Pin(s3Pin), ePin(
				ePin) {

	pinMode(s0Pin, OUTPUT);
	pinMode(s1Pin, OUTPUT);
	pinMode(s2Pin, OUTPUT);
	pinMode(s3Pin, OUTPUT);
	pinMode(ePin, OUTPUT);

	digitalWrite(ePin, HIGH);
	selectChannel(0);
}

void CD74HC4067::startSelectChannel() {
	digitalWrite(ePin, HIGH);
	delayMicroseconds(CD74HC4067_RISE_MICROSECONDS); // Wait until ePin is set
}

void CD74HC4067::selectChannel(const byte channel) {
	digitalWrite(s0Pin, channel & 0b0001 ? HIGH : LOW);
	digitalWrite(s1Pin, channel & 0b0010 ? HIGH : LOW);
	digitalWrite(s2Pin, channel & 0b0100 ? HIGH : LOW);
	digitalWrite(s3Pin, channel & 0b1000 ? HIGH : LOW);

	selectedChannel = channel;
}

void CD74HC4067::commitSelectChannel() {
	delayMicroseconds(CD74HC4067_RISE_MICROSECONDS); // Wait until all switches are set
	digitalWrite(ePin, LOW);
	delayMicroseconds(CD74HC4067_RISE_MICROSECONDS); // Wait again until ePin is set
}

bool CD74HC4067::isSelected(const byte channel) {
	return selectedChannel == channel;
}
