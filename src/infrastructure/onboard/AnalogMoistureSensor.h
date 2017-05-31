/*
 * AnalogMoistureSensor.h
 *
 *  Created on: 31.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_ONBOARD_ANALOGMOISTURESENSOR_H_
#define SRC_INFRASTRUCTURE_ONBOARD_ANALOGMOISTURESENSOR_H_

#include <Arduino.h>

#include "../../model/MoistureSensor.h"

class AnalogMoistureSensor: public MoistureSensor {
public:
	AnalogMoistureSensor(const byte sensorPin, const byte readCount);
	virtual ~AnalogMoistureSensor() {
	}
	;

	int readMoisture();

protected:
	virtual int singleReadMoisture();
	virtual void readRawMoisture(float data[], const byte readCount) = 0;

private:
	const byte sensorPin;
	const byte readCount;
};

#endif /* SRC_INFRASTRUCTURE_ONBOARD_ANALOGMOISTURESENSOR_H_ */
