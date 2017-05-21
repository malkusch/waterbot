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

	friend class Pot;

public:
	Pump(byte pin, unsigned int turnOffDelayMillis);

protected:
	void pump(byte seconds);

private:
	const byte pin;
	const unsigned int turnOffDelayMillis;

	void turnOff();
	void turnOffWithoutDelay();
	void turnOn();

};

#endif /* PUMP_H_ */
