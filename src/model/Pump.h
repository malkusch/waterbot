/*
 * Pump.h
 *
 *  Created on: 13.05.2017
 *      Author: malkusch
 */

#ifndef PUMP_H_
#define PUMP_H_

#include <Arduino.h>

class Pump {

public:
	Pump(byte pin, byte pumpSeconds, unsigned int turnOffDelayMillis);
	void pump();

private:
	const byte pin;
	const byte pumpSeconds;
	const unsigned int turnOffDelayMillis;

	void turnOff();
	void turnOn();

};

#endif /* PUMP_H_ */
