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
	Pot(byte maxWaterlessDays, unsigned int coolDownSeconds,
			MoistureSensor* moistureSensor, int moistureThreshold, Valve* valve,
			Pump* pump, byte waterSeconds);
	void waterIfNeeded();
	void water(byte seconds);

private:
	const byte id;
	const byte maxWaterlessDays;
	const unsigned int coolDownSeconds;
	MoistureSensor* moistureSensor;
	static byte nextId;
	const int moistureThreshold;
	Valve* valve;
	Pump* pump;
	const byte waterSeconds;
	unsigned long lastWaterTime;

	bool isHot();bool isDry(SensorData data);
	SensorData readSensors();
};

#endif /* POT_H_ */
