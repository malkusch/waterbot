/*
 * PCF8574DigitalOutputPin.h
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#pragma once

#include "../pin/DigitalOutputPin.h"
#include "Arduino-PCF8574/src/PCF8574.h"

using waterbot::infrastructure::pin::DigitalOutputPin;
using waterbot::infrastructure::pin::State;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class PCF8574DigitalOutputPin: public DigitalOutputPin {
public:
	PCF8574DigitalOutputPin(PCF8574* pcf8574, const byte pin);
	virtual void write(const State);
	void begin();

private:
	PCF8574* pcf8574;
	const byte pin;

};

} /* namespace pcf8574 */
} /* namespace pin */
} /* namespace waterbot */

