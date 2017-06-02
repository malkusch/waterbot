/*
 * CD74HC4067DigitalOutputPin.h
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../DigitalOutputPin.h"
#include "CD74HC4067Output.h"

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace cd74hc4067 {

class CD74HC4067DigitalOutputPin: public DigitalOutputPin {
public:
	CD74HC4067DigitalOutputPin(const byte channel,
			CD74HC4067Output* multiplexer);
	virtual void write(const State);

private:
	const byte channel;
	CD74HC4067Output* multiplexer;
};

} /* namespace cd74hc4067 */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

