/*
 * Pot.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "SensorData.h"
#include "DryStrategy.h"
#include "MoistureSensor.h"
#include "Pump.h"
#include "SensorData.h"
#include "TemperatureSensor.h"
#include "Valve.h"

namespace waterbot {
namespace model {

class Pot {
public:
	Pot(MoistureSensor*, TemperatureSensor*, DryStrategy*, Valve*, Pump*);
	void water(byte seconds);
	unsigned long getLastWaterTime() const;
	byte getId();bool isDry();

private:
	const byte id;
	MoistureSensor* moistureSensor;
	TemperatureSensor* temperatureSensor;
	static byte nextId;
	DryStrategy* dryStrategy;
	Valve* valve;
	Pump* pump;
	unsigned long lastWaterTime;

	SensorData readSensors();
};

}
}
