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
#include "Pump.h"
#include "Sensor.h"
#include "SensorData.h"
#include "Valve.h"

namespace waterbot {
namespace model {

class Pot {
public:
	Pot(const byte id, Sensor*, DryStrategy*, Valve*, Pump*);
	void water(byte seconds);
	unsigned long getLastWaterTime() const;
	byte getId();bool isDry();

private:
	const byte id;
	Sensor* sensor;
	DryStrategy* dryStrategy;
	Valve* valve;
	Pump* pump;
	unsigned long lastWaterTime;

	SensorData readSensor();
};

}
}
