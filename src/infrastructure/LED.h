/*
 * LED.h
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>
#include "pin/DigitalOutputPin.h"

namespace waterbot {
namespace infrastructure {

using pin::DigitalOutputPin;

class LED {
public:
	LED(DigitalOutputPin* pin);
	void turnOn();
	void turnOff();
	void change();

private:
	DigitalOutputPin* pin;bool on;
};

}
}
