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

Pot::Pot(byte maxWaterlessDays, unsigned int coolDownSeconds,
		MoistureSensor* moistureSensor, int moistureThreshold, Valve* valve,
		Pump* pump, byte waterSeconds) :
		id(nextId++), maxWaterlessDays(maxWaterlessDays), coolDownSeconds(
				coolDownSeconds), moistureSensor(moistureSensor), moistureThreshold(
				moistureThreshold), valve(valve), pump(pump), waterSeconds(
				waterSeconds) {

	lastWaterTime = millis();
}

void Pot::waterIfNeeded() {
	if (isHot()) {
		char message[30];
		sprintf(message, "Pot %d is still hot", id);
		Logger::getLogger()->debug(message);
		return;
	}

	const SensorData data = readSensors();
	bool pumping = false;

	if (isDry(data)) {
		pumping = true;
		water(waterSeconds);
	}
	Logger::getLogger()->info(id, data, pumping);
}

void Pot::water(byte seconds) {
	lastWaterTime = millis();
	valve->open();
	pump->pump(seconds);
	valve->close();
}

bool Pot::isDry(SensorData data) {
	unsigned long maxWaterlessTime = lastWaterTime
			+ TimeUnits::daysToMillis(maxWaterlessDays);
	if (millis() > maxWaterlessTime) {
		String warning = "Sensors didn't report 'dry' for ";
		warning += String(maxWaterlessDays) + " days in pot" + String(id);
		Logger::getLogger()->warn(warning);
		return true;
	}
	return data.moisture < moistureThreshold;
}

bool Pot::isHot() {
	unsigned long earliestWaterTime = lastWaterTime
			+ TimeUnits::secondsToMillis(coolDownSeconds);
	return earliestWaterTime > millis();
}

SensorData Pot::readSensors() {
	SensorData data;
	data.moisture = moistureSensor->readMoisture();
	return data;
}
