/*
 * Pump.h
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>
#include "../infrastructure/pin/DigitalOutputPin.h"

namespace waterbot {
namespace model {

using waterbot::infrastructure::pin::DigitalOutputPin;

class Pump {

	friend class Pot;

public:
	Pump(DigitalOutputPin* pin, unsigned int turnOffDelayMillis);

protected:
	void pump(byte seconds);

private:
	DigitalOutputPin* pin;
	const unsigned int turnOffDelayMillis;

	void turnOff();
	void turnOffWithoutDelay();
	void turnOn();

};

}
}
