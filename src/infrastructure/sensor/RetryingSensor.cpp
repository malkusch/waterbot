/*
 * RetryingSensor.cpp
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#include "RetryingSensor.h"
#include <Arduino.h>

#include "../../model/SensorData.h"
#include "../../model/Sensor.h"

using waterbot::infrastructure::sensor::RetryingSensor;

RetryingSensor::RetryingSensor(Sensor* sensor) :
		sensor(sensor) {
}

#define SENSOR_RETRY_COUNT 10
#define SENSOR_RETRY_DELAY_MS 300

SensorData RetryingSensor::read() {
	for (byte i = 0; i < SENSOR_RETRY_COUNT; i++) {
		SensorData data = sensor->read();
		if (data != Sensor::ERROR) {
			return data;
		}
	}
	return Sensor::ERROR;
}

