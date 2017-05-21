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

void Logger::info(String const& message) {
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
	switch (level) {
	case DEBUG:
		logMessage += "DEBUG";
		break;
	case INFO:
		logMessage += "INFO";
		break;
	case WARN:
		logMessage += "WARN";
		break;
	}
	logMessage += "," + message;
	write(logMessage);
}
