/*
 * PCF8574Sensor.cpp
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#include <WString.h>

#include "../../model/SensorData.h"
#include "../logger/Logger.h"
#include "AM2321Sensor.h"
#include "BME280Sensor.h"
#include "HTU21DSensor.h"
#include "NullSensor.h"
#include "RetryingSensor.h"
#include "ProbedSensor.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

ProbedSensor::ProbedSensor(BusSwitch* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->turnOff();
}

bool ProbedSensor::begin() {
	busSwitch->turnOn();
	bool probed = true;
	if (AM2321Sensor::isPluggedIn()) {
		Logger::getLogger()->info(F("Found AM2321 sensor"));
		sensor = new AM2321Sensor();

	} else if (HTU21DSensor::isPluggedIn()) {
		Logger::getLogger()->info(F("Found HTU21D sensor"));
		sensor = new HTU21DSensor();

	} else if (BME280Sensor::isPluggedIn()) {
		Logger::getLogger()->info(F("Found BME280 sensor"));
		sensor = new BME280Sensor();

	} else {
		Logger::getLogger()->error(F("Could not probe sensor"));
		sensor = new NullSensor();
		probed = false;
	}
	const bool initialized = sensor->begin();
	busSwitch->turnOff();

	return probed && initialized;
}

SensorData ProbedSensor::read() {
	busSwitch->turnOn();
	RetryingSensor retryable = RetryingSensor(sensor);
	SensorData data = retryable.read();
	busSwitch->turnOff();
	return data;
}

/* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
}
