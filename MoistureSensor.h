/*
 * MoistureSensor.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_

#include <Arduino.h>

class MoistureSensor {

public:
	MoistureSensor(byte voltagePin1, byte voltagePin2, byte sensorPin,
			byte readCount, unsigned int readMillis);
	int readMoisture();

private:
	const byte voltagePin1;
	const byte voltagePin2;
	const byte sensorPin;
	const byte readCount;
	const unsigned int readMillis;
	bool pin1ToPin2;

	int singleReadMoisture();
	void standby();
	void switchPolarity();
};

#endif /* MOISTURESENSOR_H_ */
