/*
 * ThresholdDryStrategy.cpp
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#include "ThresholdDryStrategy.h"

#include "../../model/Sensor.h"

ThresholdDryStrategy::ThresholdDryStrategy(const float moistureThreshold) :
		moistureThreshold(moistureThreshold) {

}

bool ThresholdDryStrategy::isDry(SensorData data) {
	if (data == Sensor::ERROR) {
		return false;
	}
	return data.moisture < moistureThreshold;
}
