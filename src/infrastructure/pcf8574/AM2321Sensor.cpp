/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <AM2321/AM2321.h>
#include <WString.h>

#include "../../model/SensorData.h"
#include "../logger/Logger.h"

using waterbot::infrastructure::pin::State;
using waterbot::infrastructure::pin::State;

#define AM2321_SENSOR_RETRY_COUNT 3

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

AM2321Sensor::AM2321Sensor(DigitalOutputPin* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->write(State::OFF);
}

SensorData AM2321Sensor::read() {
	AM2321 am2321;

	for (byte i = 0; i < AM2321_SENSOR_RETRY_COUNT; i++) {
		busSwitch->write(State::ON);

		String debug = F("Reading sensor ");
		debug += String(am2321.uid());
		Logger::getLogger()->debug(debug);

		if (!am2321.read()) {
			Logger::getLogger()->warn(F("Failed reading sensor"));
			continue;
		}
		break;
	}
	busSwitch->write(State::OFF);

	SensorData data;
	data.moisture = am2321.humidity / 1000.0;
	data.temperature = am2321.temperature / 10.0;

	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
