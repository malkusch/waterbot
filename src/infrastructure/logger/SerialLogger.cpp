/*
 * SerialLogger.cpp
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#include "SerialLogger.h"

SerialLogger::SerialLogger(LED warnLED) :
		warnLED(warnLED) {
	Serial.begin(9600);
}

void SerialLogger::warn(const String& message) {
	warnLED.turnOn();
	Logger::warn(message);
}

void SerialLogger::write(const String& message) {
	Serial.println(message);
}
