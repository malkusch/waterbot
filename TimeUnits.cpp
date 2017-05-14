/*
 * TimeUnits.cpp
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#include "TimeUnits.h"

unsigned long TimeUnits::secondsToMillis(unsigned int seconds) {
	return (long) seconds * 1000;
}
