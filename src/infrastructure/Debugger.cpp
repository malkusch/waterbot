/*
 * Debugger.cpp
 *
 *  Created on: 25.05.2017
 *      Author: malkusch
 */

#include "Debugger.h"

#include <avr/io.h>
#include <MemoryFree/MemoryFree.h>
#include <stdio.h>
#include <WString.h>

#include "logger/Logger.h"

void Debugger::logMemory() {
	char message[25];
	sprintf(message, "Free memory: %d", freeMemory());
	Logger::getLogger()->debug(message);
}

void Debugger::logAndClearResetReason() {
	String reason;

	if (MCUSR & (1 << PORF))
		reason = F("Power-on");
	else if (MCUSR & (1 << EXTRF))
		reason = F("External");
	else if (MCUSR & (1 << BORF))
		reason = F("Brownout");
	else if (MCUSR & (1 << WDRF))
		reason = F("Watchdog");
	else
		reason = F("no reason");

	String message = F("Reset reason: ");
	message += reason + F(" (") + String(MCUCR) + F(")");
	Logger::getLogger()->info(message);

	MCUSR = 0;
}

