/*
 * LED.h
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

namespace waterbot {
namespace infrastructure {

class LED {
public:
	LED(const byte pin);
	void turnOn();
	void turnOff();

private:
	const byte pin;
};

}
}
