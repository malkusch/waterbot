/*
 * Pin.h
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

namespace waterbot {
namespace infrastructure {
namespace pin {

enum State {
	ON, OFF
};

class DigitalOutputPin {
public:
	virtual ~DigitalOutputPin() {
	}
	;
	virtual void write(const State) = 0;
};

}
} /* namespace infrastructure */
} /* namespace waterbot */

