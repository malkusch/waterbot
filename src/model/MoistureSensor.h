/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

class MoistureSensor {

public:
	virtual ~MoistureSensor() {
	}
	;
	virtual int readMoisture() = 0;
};

#endif /* MOISTURESENSOR_H_ */
