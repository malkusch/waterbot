/*
 * AM2321Sensor.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AM2321Sensor.h"

#include <AM2321/AM2321.h>

using waterbot::infrastructure::pin::State;
using waterbot::infrastructure::pin::State;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

AM2321Sensor::AM2321Sensor(DigitalOutputPin* powerPin) :
		powerPin(powerPin) {

	powerPin->write(State::OFF);
}

int AM2321Sensor::readMoisture() {
	powerPin->write(State::ON);

	AM2321 am2321;
	am2321.read();
	const int moisture = am2321.humidity;

	powerPin->write(State::OFF);
	return moisture;
}

float AM2321Sensor::readTemperature() {
	powerPin->write(State::ON);

	AM2321 am2321;
	am2321.read();
	const float temperature = am2321.temperature / 10;

	powerPin->write(State::OFF);
	return temperature;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
