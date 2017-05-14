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
	Pump(byte pin, unsigned int coolDownSeconds, byte pumpSeconds);

	bool isHot();
	void pump();

private:
	unsigned long lastPumpTime;
	const byte pin;
	const unsigned int coolDownSeconds;
	const byte pumpSeconds;

	void turnOff();
	void turnOn();

};

#endif /* PUMP_H_ */
