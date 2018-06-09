/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <AM2321/AM2321.h>
#include <Arduino.h>
#include <WString.h>

#include "../logger/Logger.h"

#define AM2321_SENSOR_RETRY_COUNT 10
#define AM2321_SENSOR_RETRY_DELAY_MS 300

namespace waterbot {
namespace infrastructure {
namespace sensor {

bool AM2321Sensor::isPluggedIn() {
	AM2321 am2321;
	return am2321.read();
}

SensorData AM2321Sensor::read() {
	AM2321 am2321;
	for (byte i = 0; i < AM2321_SENSOR_RETRY_COUNT; i++) {
		if (am2321.read()) {
			break;

		} else {
			Logger::getLogger()->warn(F("Failed reading sensor"));
			delay(AM2321_SENSOR_RETRY_DELAY_MS);
			continue;
		}
	}
	SensorData data;
	data.moisture = am2321.humidity / 1000.0;
	data.temperature = am2321.temperature / 10.0;
	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
