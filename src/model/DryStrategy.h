/*
 * DryStrategy.h
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#ifndef MODEL_DRYSTRATEGY_H_
#define MODEL_DRYSTRATEGY_H_

#include "SensorData.h"

class DryStrategy {
	friend class Pot;
public:
	virtual ~DryStrategy() {
	}
	;

protected:
	virtual bool isDry(SensorData) = 0;
};

#endif /* MODEL_DRYSTRATEGY_H_ */
