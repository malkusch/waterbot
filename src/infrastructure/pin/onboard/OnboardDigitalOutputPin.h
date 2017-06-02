/*
 * OnboardDigitalOutputPin.h
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../DigitalOutputPin.h"

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace onboard {

class OnboardDigitalOutputPin: public DigitalOutputPin {
public:
	OnboardDigitalOutputPin(const byte pin);
	virtual void write(const State);

private:
	const byte pin;
};

}
/* namespace onboard */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

