/*
 * HT21DSensor.cpp
 *
 *  Created on: 05.08.2017
 *      Author: malkusch
 */

#include "HTU21DSensor.h"

#include <WString.h>

#include "../logger/Logger.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

bool HTU21DSensor::isPluggedIn() {
	Adafruit_HTU21DF htu;
	return htu.begin();
}

void HTU21DSensor::begin() {
	if (!htu.begin()) {
		Logger::getLogger()->error(F("Could not initialize HTU21D"));
	}
}

SensorData HTU21DSensor::read() {
	SensorData data;
	data.temperature = htu.readTemperature();
	data.moisture = htu.readHumidity() / 100;
	return data;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
