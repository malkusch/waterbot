/*
 * SensorLogger.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "SensorLogger.h"

#include <HardwareSerial.h>

SensorLogger::SensorLogger() {
	Serial.begin(9600);
}

void SensorLogger::log(SensorData data) {
	Serial.println(data.moisture);
}
