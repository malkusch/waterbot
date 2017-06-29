/*
 * SensorLogger.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "Logger.h"

#include <WString.h>

#include "../rtc/RTC.h"

Logger* Logger::logger;

Logger* Logger::getLogger() {
	return logger;
}

void Logger::setLogger(Logger* logger) {
	Logger::logger = logger;
}

void Logger::info(const String& message) {
	log(INFO, message);
}

void Logger::debug(const String& message) {
	log(DEBUG, message);
}

void Logger::warn(const String& message) {
	log(WARN, message);
}

void Logger::error(const String& message) {
	log(ERROR, message);
}

void Logger::log(const LogLevel level, const String& message) {
	write(String(RTC::getRTC()->timestamp()));
	write(F(","));

	switch (level) {
	case DEBUG:
		write(F("DEBUG"));
		break;
	case INFO:
		write(F("INFO"));
		break;
	case WARN:
		write(F("WARN"));
		break;
	case ERROR:
		write(F("ERROR"));
		break;
	}

	write(F(","));
	writeln(message);
}
