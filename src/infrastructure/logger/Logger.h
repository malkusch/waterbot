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
	DEBUG, INFO, WARN
};

class Logger {
public:
	virtual ~Logger() {
	}
	;
	virtual void info(const String& message);
	virtual void warn(const String& message);
	virtual void debug(const String& message);
	virtual void log(LogLevel, const String& message);
	static Logger* getLogger();
	static void setLogger(Logger*);

protected:
	virtual void write(const String& message) = 0;

private:
	static Logger* logger;
};

#endif /* LOGGER_H_ */
