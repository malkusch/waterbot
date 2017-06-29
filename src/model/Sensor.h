/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

#include "SensorData.h"

class Sensor {

public:
	virtual ~Sensor() {
	}
	;
	virtual SensorData read() = 0;
};

#endif /* MOISTURESENSOR_H_ */
