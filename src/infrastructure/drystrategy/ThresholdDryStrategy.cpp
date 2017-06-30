/*
 * ThresholdDryStrategy.cpp
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#include "ThresholdDryStrategy.h"

ThresholdDryStrategy::ThresholdDryStrategy(const float moistureThreshold) :
		moistureThreshold(moistureThreshold) {

}

bool ThresholdDryStrategy::isDry(SensorData data) {
	return data.moisture < moistureThreshold;
}
