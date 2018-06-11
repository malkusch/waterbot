/*
 * HT21DSensor.h
 *
 *  Created on: 05.08.2017
 *      Author: malkusch
 */

#pragma once

#include <Adafruit_HTU21DF_Library/Adafruit_HTU21DF.h>

#include "../../model/Sensor.h"
#include "../../model/SensorData.h"

namespace waterbot {
namespace infrastructure {
namespace sensor {

class HTU21DSensor: public Sensor {
public:
	virtual SensorData read();
	virtual bool begin();
	static bool isPluggedIn();

private:
	Adafruit_HTU21DF htu;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
