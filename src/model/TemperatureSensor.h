/*
 * TemperatureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef TEMPERATURESENSOR_H_
#define TEMPERATURESENSOR_H_

class TemperatureSensor {

public:
	virtual ~TemperatureSensor() {
	}
	;
	virtual float readTemperature() = 0;
};

#endif /* TEMPERATURESENSOR_H_ */
