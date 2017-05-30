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

byte Pot::nextId = 1;

Pot::Pot(MoistureSensor* moistureSensor, TemperatureSensor* temperatureSensor,
		DryStrategy* dryStrategy, Valve* valve, Pump* pump) :
		id(nextId++), moistureSensor(moistureSensor), temperatureSensor(
				temperatureSensor), dryStrategy(dryStrategy), valve(valve), pump(
				pump) {

	lastWaterTime = millis();
}

void Pot::water(byte seconds) {
	String message = F("Watering pot ");
	message += id;
	Logger::getLogger()->info(message);

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
	if (temperatureSensor != NULL) {
		data.temperature = temperatureSensor->readTemperature();
	}

	char message[20];
	char temperature[8];
	dtostrf(data.temperature, 7, 2, temperature);
	sprintf(message, "%d, %d, %s", data.moisture, id, temperature);
	Logger::getLogger()->info(message);

	return data;
}
