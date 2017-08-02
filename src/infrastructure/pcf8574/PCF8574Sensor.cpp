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

using waterbot::infrastructure::sensor::AM2321Sensor;
using waterbot::infrastructure::sensor::BME280Sensor;
using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574Sensor::PCF8574Sensor(DigitalOutputPin* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->write(ON);
	sensor = NULL;
	if (AM2321Sensor::isPluggedIn()) {
		Logger::getLogger()->info(F("Found AM2321 sensor"));
		sensor = new AM2321Sensor();

	} else if (BME280Sensor::isPluggedIn()) {
		Logger::getLogger()->info(F("Found BME280 sensor"));
		sensor = new BME280Sensor();

	} else {
		Logger::getLogger()->error(F("Could not probe sensor"));
	}
	busSwitch->write(OFF);
}

void PCF8574Sensor::begin() {
	busSwitch->write(ON);
	sensor->begin();
	busSwitch->write(OFF);
}

SensorData PCF8574Sensor::read() {
	busSwitch->write(ON);
	SensorData data = sensor->read();
	busSwitch->write(OFF);
	return data;
}

/* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
}
