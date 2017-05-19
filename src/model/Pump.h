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
	Pump(byte pin, byte pumpSeconds);
	void pump();

private:
	const byte pin;
	const byte pumpSeconds;

	void turnOff();
	void turnOn();

};

#endif /* PUMP_H_ */
