/*
 * HT21DSensor.cpp
 *
 *  Created on: 05.08.2017
 *      Author: malkusch
 */

#include "HTU21DSensor.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

bool HTU21DSensor::isPluggedIn() {
	Adafruit_HTU21DF htu;
	return htu.begin();
}

bool HTU21DSensor::begin() {
	return htu.begin();
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
