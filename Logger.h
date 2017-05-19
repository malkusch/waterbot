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
	Logger(LED);
	void info(int potId, SensorData, bool pumping);
	void warn(String const& message);
	static Logger* getLogger();
	static void setLogger(Logger*);

private:
	static Logger* logger;
	const LED warnLED;
	void log(LogLevel level, const String& message);
};

#endif /* LOGGER_H_ */
