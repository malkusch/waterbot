/*
 * PauseService.cpp
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#include "PauseService.h"
#include <Sleep_n0m1/Sleep_n0m1.h>
#include "logger/Logger.h"
#include "TimeUnits.h"

using waterbot::infrastructure::PauseService;

PauseService::PauseService() {
}

void PauseService::pause(unsigned long seconds) {
	Logger::getLogger()->flush();
	const byte delaySleepMillis = 100;
	delay(delaySleepMillis); // Give serial data some time to print
	Sleep sleep;
	sleep.idleMode();
	sleep.sleepDelay(TimeUnits::secondsToMillis(seconds) - delaySleepMillis);
}
