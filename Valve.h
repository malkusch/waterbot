/*
 * Valve.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#ifndef VALVE_H_
#define VALVE_H_

#include <Arduino.h>

class Valve {
public:
	Valve(byte pin);
	void open() const;
	void close() const;

private:
	const byte pin;
};

#endif /* VALVE_H_ */
