/*
 * Pot.cpp
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#include "Pot.h"

#include <stdio.h>
#include <stdlib.h>
#include <WString.h>

#include "../infrastructure/logger/Logger.h"

using waterbot::model::Pot;

Pot::Pot(const byte id, Sensor* moistureSensor, DryStrategy* dryStrategy,
		Valve* valve, Pump* pump) :
		id(id), sensor(moistureSensor), dryStrategy(dryStrategy), valve(valve), pump(
				pump) {

	lastWaterTime = millis();
}

void Pot::water(byte seconds) {
	{
		String message = F("Watering pot ");
		message += id;
		Logger::getLogger()->info(message);
	}

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
	SensorData data = readSensor();
	return dryStrategy->isDry(data);
}

SensorData Pot::readSensor() {
	SensorData data = sensor->read();

	char message[20];
	char temperature[8];
	dtostrf(data.temperature, 7, 2, temperature);
	sprintf(message, "%d, %d, %s", data.moisture, id, temperature);
	Logger::getLogger()->info(message);

	return data;
}

