/*
 * CD74HC4067DigitalOutputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "CD74HC4067DigitalOutputPin.h"

using waterbot::infrastructure::pin::cd74hc4067::CD74HC4067DigitalOutputPin;

CD74HC4067DigitalOutputPin::CD74HC4067DigitalOutputPin(const byte channel,
		CD74HC4067Output* multiplexer) :
		channel(channel), multiplexer(multiplexer) {

}

void CD74HC4067DigitalOutputPin::write(State state) {
	multiplexer->write(channel, state);
}
