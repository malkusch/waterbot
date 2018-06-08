/*
 * PCF8574Sensor.cpp
 *
 *  Created on: 02.08.2017
 *      Author: malkusch
 */

#include "PCF8574Sensor.h"

#include <stddef.h>
#include <WString.h>

#include "../../model/SensorData.h"
#include "../logger/Logger.h"
#include "../sensor/AM2321Sensor.h"
#include "../sensor/BME280Sensor.h"
#include "../sensor/HTU21DSensor.h"
#include "../sensor/NullSensor.h"

using waterbot::infrastructure::sensor::AM2321Sensor;
using waterbot::infrastructure::sensor::BME280Sensor;
using waterbot::infrastructure::sensor::HTU21DSensor;
using waterbot::infrastructure::sensor::NullSensor;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574Sensor::PCF8574Sensor(BusSwitch* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->turnOff();
}

void PCF8574Sensor::begin() {
	busSwitch->turnOn();
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
	}
	sensor->begin();
	busSwitch->turnOff();
}

SensorData PCF8574Sensor::read() {
	busSwitch->turnOn();
	SensorData data = sensor->read();
	busSwitch->turnOff();
	return data;
}

/* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
}
