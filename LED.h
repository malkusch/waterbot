/*
 * LED.h
 *
 *  Created on: 15.05.2017
 *      Author: malkusch
 */

#ifndef LED_H_
#define LED_H_

#include <Arduino.h>

class LED {
public:
	LED(byte pin);
	void turnOn() const;
	void turnOff() const;

private:
	const byte pin;
};

#endif /* LED_H_ */
