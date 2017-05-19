/*
 * SensorLogger.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "../../model/SensorData.h"
#include <Arduino.h>

enum LogLevel {
	INFO, WARN
};

class Logger {
public:
	virtual ~Logger() {};
	virtual void info(int potId, SensorData, bool pumping);
	virtual void warn(String const& message);
	virtual void log(LogLevel, const String& message);
	static Logger* getLogger();
	static void setLogger(Logger*);

protected:
	virtual void write(const String& message) = 0;

private:
	static Logger* logger;
};

#endif /* LOGGER_H_ */
