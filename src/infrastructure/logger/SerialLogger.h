/*
 * SerialLogger.h
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#ifndef INFRASTRUCTURE_LOGGER_SERIALLOGGER_H_
#define INFRASTRUCTURE_LOGGER_SERIALLOGGER_H_

#include "../LED.h"
#include "Logger.h"

class SerialLogger: public Logger {
public:
	SerialLogger(LED);
	virtual void warn(const String& message);

protected:
	virtual void write(const String& message);

private:
	LED warnLED;
};

#endif /* INFRASTRUCTURE_LOGGER_SERIALLOGGER_H_ */
