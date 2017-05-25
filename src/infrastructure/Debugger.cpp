/*
 * Debugger.cpp
 *
 *  Created on: 25.05.2017
 *      Author: malkusch
 */

#include "Debugger.h"

#include <avr/io.h>

#include "../../libraries/MemoryFree/MemoryFree.h"
#include "logger/Logger.h"

void Debugger::logMemory() {
	char message[25];
	sprintf(message, "Free memory: %d", freeMemory());
	Logger::getLogger()->debug(message);
}

void Debugger::logAndClearResetReason() {
	const char* reason;

	if (MCUSR & (1 << PORF))
		reason = "Power-on";
	else if (MCUSR & (1 << EXTRF))
		reason = "External";
	else if (MCUSR & (1 << BORF))
		reason = "Brownout";
	else if (MCUSR & (1 << WDRF))
		reason = "Watchdog";
	else
		reason = "no reason";

	char message[50];
	sprintf(message, "Reset reason: %s (%d)", reason, MCUSR);
	Logger::getLogger()->info(message);

	MCUSR = 0;
}

