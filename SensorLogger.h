/*
 * SensorLogger.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef SENSORLOGGER_H_
#define SENSORLOGGER_H_

#include "SensorData.h"

class SensorLogger {
public:
	SensorLogger();
	void log(SensorData data);
};

#endif /* SENSORLOGGER_H_ */
