/*
 * Pot.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#ifndef POT_H_
#define POT_H_

#include <Arduino.h>

#include "SensorData.h"
#include "Pump.h"
#include "Valve.h"
#include "MoistureSensor.h"

class Pot {
public:
	Pot(MoistureSensor* moistureSensor, int moistureThreshold, Valve* valve,
			Pump* pump);
	void water(byte seconds);
	unsigned long getLastWaterTime() const;bool isDry();
	byte getId();

private:
	const byte id;
	MoistureSensor* moistureSensor;
	static byte nextId;
	const int moistureThreshold;
	Valve* valve;
	Pump* pump;
	unsigned long lastWaterTime;

	SensorData readSensors();
};

#endif /* POT_H_ */
