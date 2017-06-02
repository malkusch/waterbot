/*
 * CD74HC4067AnalogInputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "CD74HC4067AnalogInputPin.h"

using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067AnalogInputPin;

CD74HC4067AnalogInputPin::CD74HC4067AnalogInputPin(const byte channel,
		CD74HC4067Input* multiplexer) :
		channel(channel), multiplexer(multiplexer) {

}

int CD74HC4067AnalogInputPin::read() {
	return multiplexer->analogRead(channel);
}

String CD74HC4067AnalogInputPin::toString() {
	return String(channel);
}
