/*
 * TimerDryStrategy.cpp
 *
 *  Created on: 17.06.2017
 *      Author: malkusch
 */

#include "TimerDryStrategy.h"

#include "../TimeUnits.h"

using waterbot::infrastructure::drystrategy::TimerDryStrategy;

TimerDryStrategy::TimerDryStrategy(const byte timerHours) :
		timerHours(timerHours) {

	lastDryTime = millis();
}

bool TimerDryStrategy::isDry(SensorData) {
	const bool dry = TimeUnits::millisSince(lastDryTime)
			> TimeUnits::hoursToMillis(timerHours);
	if (dry) {
		lastDryTime = millis();
	}
	return dry;
}
