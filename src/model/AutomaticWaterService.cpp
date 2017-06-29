/*
 * AutomaticWaterService.cpp
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#include "AutomaticWaterService.h"

#include <WString.h>

#include "../infrastructure/logger/Logger.h"
#include "../infrastructure/TimeUnits.h"

using waterbot::model::AutomaticWaterService;

AutomaticWaterService::AutomaticWaterService(byte waterSeconds,
		unsigned int coolDownSeconds, byte maxWaterlessDays) :
		waterSeconds(waterSeconds), coolDownSeconds(coolDownSeconds), maxWaterlessDays(
				maxWaterlessDays) {

}

void AutomaticWaterService::waterIfNeeded(Pot *pot) {
	if (isHot(pot)) {
		String message = F("Pot ");
		message += pot->getId();
		message += F(" is still hot");
		Logger::getLogger()->debug(message);
		return;
	}

	if (isTooLongWaterLess(pot)) {
		{
			String warning = F("Pot ");
			warning += pot->getId();
			warning += F(" wasn't watered too long. Check sensors!");
			Logger::getLogger()->warn(warning);
		}
		pot->water(waterSeconds);
		return;
	}

	if (pot->isDry()) {
		{
			String info = F("Automatically watering pot ");
			info += pot->getId();
			Logger::getLogger()->info(info);
		}
		pot->water(waterSeconds);
	}
}

bool AutomaticWaterService::isHot(const Pot *pot) {
	return TimeUnits::millisSince(pot->getLastWaterTime())
			< TimeUnits::secondsToMillis(coolDownSeconds);
}

bool AutomaticWaterService::isTooLongWaterLess(const Pot *pot) {
	return TimeUnits::millisSince(pot->getLastWaterTime())
			> TimeUnits::daysToMillis(maxWaterlessDays);
}
