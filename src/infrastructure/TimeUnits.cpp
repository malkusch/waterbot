/*
 * TimeUnits.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "TimeUnits.h"
#include "Arduino.h"

unsigned long TimeUnits::secondsToMillis(const unsigned long seconds) {
	return (long) seconds * 1000;
}

unsigned long TimeUnits::minutesToMillis(const unsigned long minutes) {
	return secondsToMillis(minutes * 60);
}

unsigned long TimeUnits::hoursToMillis(const unsigned int hours) {
	return minutesToMillis(hours * 60);
}

unsigned long TimeUnits::daysToMillis(const unsigned int days) {
	return hoursToMillis(days * 24);
}

unsigned long TimeUnits::millisSince(const unsigned long ms) {
	return millis() - ms;
}
