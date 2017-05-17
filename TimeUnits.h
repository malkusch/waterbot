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
	static unsigned long secondsToMillis(unsigned int seconds);
	static unsigned long minutesToMillis(unsigned int minutes);
	static unsigned long hoursToMillis(unsigned int hours);
	static unsigned long daysToMillis(unsigned int days);
};

#endif /* TIMEUNITS_H_ */
