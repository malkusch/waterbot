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
	String logMessage = String(RTC::getRTC()->timestamp());
	logMessage += F(",");

	String printableLevel;
	switch (level) {
	case DEBUG:
		printableLevel = F("DEBUG");
		break;
	case INFO:
		printableLevel = F("INFO");
		break;
	case WARN:
		printableLevel = F("WARN");
		break;
	case ERROR:
		printableLevel = F("ERROR");
		break;
	}
	logMessage += printableLevel;

	logMessage += F(",");
	logMessage += message;
	write(logMessage);
}
