/*
 * AutomaticWaterService.cpp
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#include "AutomaticWaterService.h"

#include <stdio.h>

#include "../infrastructure/logger/Logger.h"
#include "../infrastructure/TimeUnits.h"

AutomaticWaterService::AutomaticWaterService(byte waterSeconds,
		unsigned int coolDownSeconds, byte maxWaterlessDays) :
		waterSeconds(waterSeconds), coolDownSeconds(coolDownSeconds), maxWaterlessDays(
				maxWaterlessDays) {

}

void AutomaticWaterService::waterIfNeeded(Pot *pot) {
	if (isHot(pot)) {
		char message[30];
		sprintf(message, "Pot %d is still hot", pot->getId());
		Logger::getLogger()->debug(message);
		return;
	}

	if (isTooLongWaterLess(pot)) {
		char warning[50];
		sprintf(warning, "Pot %d wasn't watered too long. Check sensors!",
				pot->getId());
		Logger::getLogger()->warn(warning);
		pot->water(waterSeconds);
		return;
	}

	if (pot->isDry()) {
		char info[35];
		sprintf(info, "Automatically watering pot %d", pot->getId());
		Logger::getLogger()->info(info);
		pot->water(waterSeconds);
	}
}

bool AutomaticWaterService::isHot(const Pot *pot) {
	unsigned long earliestWaterTime = pot->getLastWaterTime()
			+ TimeUnits::secondsToMillis(coolDownSeconds);
	return earliestWaterTime > millis();
}

bool AutomaticWaterService::isTooLongWaterLess(const Pot *pot) {
	unsigned long maxWaterlessTime = pot->getLastWaterTime()
			+ TimeUnits::daysToMillis(maxWaterlessDays);
	return millis() > maxWaterlessTime;
}
