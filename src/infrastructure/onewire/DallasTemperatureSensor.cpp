/*
 * OnewireTemperatureSensor.cpp
 *
 *  Created on: 27.05.2017
 *      Author: malkusch
 */

#include "DallasTemperatureSensor.h"

#include <Arduino.h>
#include <stdint.h>

#include "../logger/Logger.h"

DallasTemperatureSensor::DallasTemperatureSensor(
		DallasTemperature* dallasTemperature, const uint8_t* address) :
		dallasTemperature(dallasTemperature), address(address) {
}

float DallasTemperatureSensor::readTemperature() {
	for (byte i = 0; i < DALLAS_RETRIES; i++) {
		if (!dallasTemperature->requestTemperaturesByAddress(address)) {
			Logger::getLogger()->warn("Retry reading temperature");
			continue;
		}

		float temperature = dallasTemperature->getTempC(address);
		if (temperature == DEVICE_DISCONNECTED_C) {
			Logger::getLogger()->warn("Retry reading temperature");
			continue;
		}
		return temperature;
	}

	Logger::getLogger()->error("Failed reading temperature");
	return -1;
}
