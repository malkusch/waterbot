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
#include "../infrastructure/LED.h"

using waterbot::infrastructure::LED;

namespace waterbot {
namespace model {

class Pot {
public:
	Pot(const byte id, Sensor*, DryStrategy*, Valve, Pump*, LED, LED);
	void water(byte seconds);
	unsigned long getLastWaterTime() const;
	byte getId();
	void blink();bool isDry();

private:
	const byte id;
	Sensor* sensor;
	DryStrategy* dryStrategy;
	Valve valve;
	Pump* pump;
	LED led;
	LED errorLed;
	unsigned long lastWaterTime;

	SensorData readSensor();
	void clearError();
	void setError();
};

}
}
