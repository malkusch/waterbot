/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <Arduino.h>
#include <WString.h>

#include "../logger/Logger.h"
#include "../TimeUnits.h"

using waterbot::infrastructure::pin::State;
using waterbot::infrastructure::pin::State;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

AM2321Sensor::AM2321Sensor(DigitalOutputPin* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->write(State::OFF);
	lastReadTime = millis();
}

int AM2321Sensor::readMoisture() {
	readIfStale();
	return am2321.humidity;
}

void AM2321Sensor::readIfStale() {
	if (!TimeUnits::millisSince(lastReadTime) > AM2321_STALE_MILLIS) {
		return;
	}
	lastReadTime = millis();

	busSwitch->write(State::ON);
	if (!am2321.read()) {
		Logger::getLogger()->warn(F("Failed reading sensor"));
	}
	busSwitch->write(State::OFF);
}

float AM2321Sensor::readTemperature() {
	readIfStale();
	return am2321.temperature / 10.0;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
