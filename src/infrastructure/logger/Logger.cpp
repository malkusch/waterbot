/*
 * SensorLogger.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "Logger.h"
#include <Arduino.h>

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

void Logger::log(LogLevel level, const String& message) {
	String logMessage = String(millis());
	logMessage += ",";

	const char* printableLevel;
	switch (level) {
	case DEBUG:
		printableLevel = "DEBUG";
		break;
	case INFO:
		printableLevel = "INFO";
		break;
	case WARN:
		printableLevel = "WARN";
		break;
	}
	logMessage += printableLevel;

	logMessage += "," + message;
	write(logMessage);
}
