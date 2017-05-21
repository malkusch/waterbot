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

Pot::Pot(MoistureSensor* moistureSensor, DryStrategy* dryStrategy, Valve* valve,
		Pump* pump) :
		id(nextId++), moistureSensor(moistureSensor), dryStrategy(dryStrategy), valve(
				valve), pump(pump) {

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
	return dryStrategy->isDry(data);
}

SensorData Pot::readSensors() {
	SensorData data;
	data.moisture = moistureSensor->readMoisture();

	char message[10];
	sprintf(message, "%d, %d", data.moisture, id);
	Logger::getLogger()->info(message);

	return data;
}
