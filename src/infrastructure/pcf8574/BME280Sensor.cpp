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
#include <WString.h>

#include "../../model/SensorData.h"
#include "../logger/Logger.h"

using waterbot::infrastructure::pin::ON;
using waterbot::infrastructure::pin::OFF;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

BME280Sensor::BME280Sensor(DigitalOutputPin* busSwitch) :
		busSwitch(busSwitch) {
}

void BME280Sensor::init() {
	busSwitch->write(ON);

	String debug = F("Initializing BME280 with id ");
	debug += String(BME280.readChipId(), HEX);
	Logger::getLogger()->debug(debug);

	BME280.writeOversamplingPressure(osSkipped);
	BME280.writeOversamplingTemperature(os16x);
	BME280.writeOversamplingHumidity(os16x);
	BME280.writeMode(smSleep);
	// TODO retry on bus failure

	busSwitch->write(OFF);
}

SensorData BME280Sensor::read() {
	busSwitch->write(ON);

	BME280.writeMode(smForced);
	while (BME280.isMeasuring()) {
		delay(50);
	}
	BME280.readCompensationParams();
	BME280.readMeasurements();
	// TODO retry on bus failure

	busSwitch->write(OFF);

	SensorData data;
	data.moisture = BME280.getHumidity();
	data.temperature = BME280.getTemperature();
	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
