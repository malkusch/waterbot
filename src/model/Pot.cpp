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
		Valve valve, Pump* pump, LED led) :
		id(id), sensor(moistureSensor), dryStrategy(dryStrategy), valve(valve), pump(
				pump), led(led) {

	lastWaterTime = millis();
}

void Pot::water(byte seconds) {
	{
		String message = F("Watering pot ");
		message += id;
		Logger::getLogger()->info(message);
	}

	valve.open();
	pump->pump(seconds);
	valve.close();
	lastWaterTime = millis();
}

void Pot::blink() {
	led.change();
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

	if (data == Sensor::ERROR) {
		Logger::getLogger()->warn(F("Failed reading sensor"));
		return Sensor::ERROR;
	}

	char message[20];
	char temperature[8];
	dtostrf(data.temperature, 7, 2, temperature);
	char moisture[6];
	dtostrf(data.moisture, 5, 3, moisture);
	sprintf(message, "%d, %s, %s", id, moisture, temperature);
	Logger::getLogger()->info(message);

	return data;
}

