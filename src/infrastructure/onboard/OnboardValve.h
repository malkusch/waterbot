/*
 * OnboardValve.h
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../../model/Valve.h"
#include "../pin/DigitalOutputPin.h"

namespace waterbot {
namespace infrastructure {
namespace onboard {

using waterbot::model::Valve;
using pin::DigitalOutputPin;

class OnboardValve: public Valve {
public:
	OnboardValve(DigitalOutputPin* pin, unsigned int delayMillis);

protected:
	virtual void open();
	virtual void close();

private:
	DigitalOutputPin* pin;
	const unsigned int delayMillis;
	void closeWithoutDelay();
};

}
}
}
