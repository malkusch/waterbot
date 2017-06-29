/*
 * OnboardValve.h
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../infrastructure/pin/DigitalOutputPin.h"

namespace waterbot {
namespace model {

using infrastructure::pin::DigitalOutputPin;

class Valve {

	friend class Pot;

public:
	Valve(DigitalOutputPin* pin, const unsigned int delayMillis);

protected:
	void open();
	void close();

private:
	DigitalOutputPin* pin;
	const unsigned int delayMillis;
	void closeWithoutDelay();
};

}
}
