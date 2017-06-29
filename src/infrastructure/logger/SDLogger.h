/*
 * SDLogger.h
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_LOGGER_SDLOGGER_H_
#define SRC_INFRASTRUCTURE_LOGGER_SDLOGGER_H_

#include <Arduino.h>
#include <pins_arduino.h>
#include <SdFat.h>
#include <WString.h>

#include "Logger.h"

class SDLogger: public Logger {
public:
	SDLogger(const char* filenameFormat, const byte chipSelectPin = SS);
	~SDLogger();

	void begin();
	virtual void flush();

protected:
	virtual void write(const String& message);
	virtual void writeln(const String& message);

private:
	SdFat* fs;
	SdFile file;bool openNewLogFile();
	bool initCard();
	const char* filenameFormat;
	const byte chipSelectPin;
};

#endif /* SRC_INFRASTRUCTURE_LOGGER_SDLOGGER_H_ */
