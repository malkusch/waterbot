/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <WString.h>
#include <AM2321/AM2321.h>

#include "../logger/Logger.h"

using waterbot::infrastructure::pin::State;
using waterbot::infrastructure::pin::State;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

AM2321Sensor::AM2321Sensor(DigitalOutputPin* busSwitch) :
		busSwitch(busSwitch) {

	busSwitch->write(State::OFF);
}

SensorData AM2321Sensor::read() {
	busSwitch->write(State::ON);
	AM2321 am2321;
	if (!am2321.read()) {
		Logger::getLogger()->warn(F("Failed reading sensor"));
	}
	busSwitch->write(State::OFF);

	SensorData data;
	data.moisture = am2321.humidity;
	data.temperature = am2321.temperature / 10.0;

	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
