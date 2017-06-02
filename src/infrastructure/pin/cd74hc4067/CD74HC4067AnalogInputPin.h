/*
 * CD74HC4067AnalogInputPin.h
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../AnalogInputPin.h"
#include "CD74HC4067Input.h"

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace cd74hc4067 {

class CD74HC4067AnalogInputPin: public AnalogInputPin {
public:
	CD74HC4067AnalogInputPin(const byte channel, CD74HC4067Input* multiplexer);
	virtual int read() = 0;
	virtual String toString() = 0;

private:
	const byte channel;
	CD74HC4067Input* multiplexer;
};

} /* namespace cd74hc4067 */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */
