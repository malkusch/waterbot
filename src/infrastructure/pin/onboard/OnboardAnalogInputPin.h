/*
 * OnboardAnalogInputPin.h
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../AnalogInputPin.h"

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace onboard {

class OnboardAnalogInputPin: public AnalogInputPin {
public:
	OnboardAnalogInputPin(const byte pin);
	virtual int read();
	virtual String toString();
private:
	const byte pin;
};

} /* namespace onboard */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

