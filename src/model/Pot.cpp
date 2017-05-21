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
		Pump* pump) :
		id(nextId++), maxWaterlessDays(maxWaterlessDays), coolDownSeconds(
				coolDownSeconds), moistureSensor(moistureSensor), moistureThreshold(
				moistureThreshold), valve(valve), pump(pump) {

	lastWaterTime = millis();
}

void Pot::waterIfNeeded() {
	const SensorData data = readSensors();
	bool pumping = false;

	if (isDry(data) && !isHot()) {
		pumping = true;
		valve->open();
		pump->pump();
		valve->close();
	}
	Logger::getLogger()->info(id, data, pumping);
}

bool Pot::isDry(SensorData data) {
	unsigned long maxWaterlessTime = lastWaterTime
			+ TimeUnits::daysToMillis(maxWaterlessDays);
	if (millis() > maxWaterlessTime) {
		Logger::getLogger()->warn(
				"Sensors didn't report 'dry' for " + String(maxWaterlessDays)
						+ " days in pot" + id);
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
