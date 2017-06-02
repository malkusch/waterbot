/*
 * CD74HC4067Output.h
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../DigitalOutputPin.h"
#include "CD74HC4067.h"

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace cd74hc4067 {

class CD74HC4067Output: public CD74HC4067 {
public:
	CD74HC4067Output(const byte ioPin, const byte s0Pin, const byte s1Pin,
			const byte s2Pin, const byte s3Pin, const byte ePin);

	void write(const byte channel, const State);
};

} /* namespace cd74hc4067 */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

