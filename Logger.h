/*
 * SensorLogger.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <Arduino.h>

#include "LED.h"
#include "SensorData.h"

class String;

enum LogLevel {
	INFO, WARN
};

class Logger {
public:
	Logger(LED warnLED);
	void info(SensorData data, bool pumping);
	void warn(const String& message);

private:
	const LED warnLED;
	void log(LogLevel level, const String& message);
};

#endif /* LOGGER_H_ */
