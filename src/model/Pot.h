/*
 * Pot.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#ifndef MODEL_POT_H_
#define MODEL_POT_H_

#include <Arduino.h>

#include "SensorData.h"
#include "Pump.h"
#include "Valve.h"
#include "MoistureSensor.h"
#include  "DryStrategy.h"

class Pot {
public:
	Pot(MoistureSensor* moistureSensor, DryStrategy* dryStrategy, Valve* valve,
			Pump* pump);
	void water(byte seconds);
	unsigned long getLastWaterTime() const;
	byte getId();bool isDry();

private:
	const byte id;
	MoistureSensor* moistureSensor;
	static byte nextId;
	DryStrategy* dryStrategy;
	Valve* valve;
	Pump* pump;
	unsigned long lastWaterTime;

	SensorData readSensors();
};

#endif /* POT_H_ */
