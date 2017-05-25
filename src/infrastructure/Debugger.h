/*
 * Debugger.h
 *
 *  Created on: 25.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_DEBUGGER_H_
#define SRC_INFRASTRUCTURE_DEBUGGER_H_

class Debugger {
public:
	static void logMemory();
	static void logAndClearResetReason();
};

#endif /* SRC_INFRASTRUCTURE_DEBUGGER_H_ */
