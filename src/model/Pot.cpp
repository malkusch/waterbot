/*
 * Pot.cpp
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#include "Pot.h"

#include <WString.h>

#include "../infrastructure/logger/Logger.h"
#include "../infrastructure/TimeUnits.h"

byte Pot::nextId = 1;

Pot::Pot(MoistureSensor* moistureSensor, int moistureThreshold, Valve* valve,
		Pump* pump) :
		id(nextId++), moistureSensor(moistureSensor), moistureThreshold(
				moistureThreshold), valve(valve), pump(pump) {

	lastWaterTime = millis();
}

void Pot::water(byte seconds) {
	valve->open();
	pump->pump(seconds);
	valve->close();
	lastWaterTime = millis();
}

byte Pot::getId() {
	return id;
}

unsigned long Pot::getLastWaterTime() const {
	return lastWaterTime;
}

bool Pot::isDry() {
	SensorData data = readSensors();
	return data.moisture < moistureThreshold;
}

SensorData Pot::readSensors() {
	SensorData data;
	data.moisture = moistureSensor->readMoisture();
	return data;
}
