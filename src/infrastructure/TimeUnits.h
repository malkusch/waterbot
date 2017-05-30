/*
 * TimeUnits.h
 *
 *  Created on: 14.05.2017
 *      Author: malkusch
 */

#ifndef TIMEUNITS_H_
#define TIMEUNITS_H_

class TimeUnits {
public:
	static unsigned long secondsToMillis(const unsigned long seconds);
	static unsigned long minutesToMillis(const unsigned long minutes);
	static unsigned long hoursToMillis(const unsigned int hours);
	static unsigned long daysToMillis(const unsigned int days);
	static unsigned long millisSince(const unsigned long millis);
};

#endif /* TIMEUNITS_H_ */
