/*
 * SensorLogger.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "Logger.h"

#include <Arduino.h>

Logger::Logger(LED warnLED) :
		warnLED(warnLED) {
	Serial.begin(9600);
}

void Logger::info(SensorData data, bool pumping) {
	String message = String(data.moisture);
	message += ",";
	message += pumping;
	log(INFO, message);
}

void Logger::warn(const String& message) {
	warnLED.turnOn();
	log(WARN, message);
}

void Logger::log(LogLevel level, const String& message) {
	String logMessage = String(millis());
	logMessage += ",";
	switch (level) {
	case WARN:
		logMessage += "WARN";
		break;
	case INFO:
		logMessage += "INFO";
		break;
	default:
		logMessage += level;
		break;
	}
	logMessage += "," + message;
	Serial.println(logMessage);
}
