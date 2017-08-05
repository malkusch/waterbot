/*
 * BME280Sensor.cpp
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#include "BME280Sensor.h"

#include <Arduino.h>
#include <BME280/BME280_MOD-1022.h>
#include <Print.h>
#include <Wire.h>
#include <WString.h>

#include "../logger/Logger.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

bool BME280Sensor::isPluggedIn() {
	Wire.beginTransmission(addrBME280);
	return Wire.endTransmission() == 0;
}

void BME280Sensor::begin() {
	String debug = F("Initializing BME280 with id ");
	debug += String(BME280.readChipId(), HEX);
	Logger::getLogger()->debug(debug);

	BME280.writeOversamplingPressure(osSkipped);
	BME280.writeOversamplingTemperature(os16x);
	BME280.writeOversamplingHumidity(os16x);
	BME280.writeMode(smSleep);
	// TODO retry on bus failure
}

SensorData BME280Sensor::read() {
	BME280.writeMode(smForced);
	while (BME280.isMeasuring()) {
		delay(50);
	}
	BME280.readCompensationParams();
	BME280.readMeasurements();
	// TODO retry on bus failure

	SensorData data;
	data.moisture = BME280.getHumidity() / 100;
	data.temperature = BME280.getTemperature();
	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
