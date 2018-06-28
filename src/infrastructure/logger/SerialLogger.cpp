/*
 * SerialLogger.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "SerialLogger.h"

#include <HardwareSerial.h>

SerialLogger::SerialLogger(LED warnLED, LED errorLED) :
		warnLED(warnLED), errorLED(errorLED) {
}

void SerialLogger::begin() {
	Serial.begin(9600);
	Logger::setLogger(this);
}

void SerialLogger::warn(const String& message) {
	warnLED.turnOn();
	Logger::warn(message);
}

void SerialLogger::error(const String& message) {
	errorLED.turnOn();
	Logger::error(message);
}

void SerialLogger::flush() {
	Serial.flush();
}

void SerialLogger::write(const String& message) {
	Serial.print(message);
}

void SerialLogger::writeln(const String& message) {
	Serial.println(message);
}
