/*
 * SerialLogger.h
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#pragma once

#include <WString.h>

#include "../LED.h"
#include "Logger.h"

using waterbot::infrastructure::LED;

class SerialLogger: public Logger {
public:
	SerialLogger(LED* warnLED, LED* errorLED);
	void begin();
	virtual void warn(const String& message);
	virtual void error(const String& message);
	virtual void flush();

protected:
	virtual void write(const String& message);
	virtual void writeln(const String& message);

private:
	LED* warnLED;
	LED* errorLED;
};

