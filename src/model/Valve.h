/*
 * Valve.h
 *
 *  Created on: 18.05.2017
 *      Author: malkusch
 */

#ifndef VALVE_H_
#define VALVE_H_

class Valve {
public:
	virtual ~Valve() {
	}
	;
	virtual void open() = 0;
	virtual void close() = 0;

};

#endif /* VALVE_H_ */
