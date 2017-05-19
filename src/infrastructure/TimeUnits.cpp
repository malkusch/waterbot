/*
 * TimeUnits.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "TimeUnits.h"

unsigned long TimeUnits::secondsToMillis(unsigned long seconds) {
	return (long) seconds * 1000;
}

unsigned long TimeUnits::minutesToMillis(unsigned long minutes) {
	return secondsToMillis(minutes * 60);
}

unsigned long TimeUnits::hoursToMillis(unsigned int hours) {
	return minutesToMillis(hours * 60);
}

unsigned long TimeUnits::daysToMillis(unsigned int days) {
	return hoursToMillis(days * 24);
}
