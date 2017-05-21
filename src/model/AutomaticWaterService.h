/*
 * AutomaticWaterService.h
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#ifndef MODEL_AUTOMATICWATERSERVICE_H_
#define MODEL_AUTOMATICWATERSERVICE_H_

#include <Arduino.h>

#include "SensorData.h"
#include "Pot.h"

class AutomaticWaterService {
public:
	AutomaticWaterService(byte waterSeconds, unsigned int coolDownSeconds, byte maxWaterlessDays);
	void waterIfNeeded(Pot *pot);

private:
	const byte waterSeconds;
	const unsigned int coolDownSeconds;
	const byte maxWaterlessDays;

	bool isHot(const Pot *pot);
	bool isTooLongWaterLess(const Pot *pot);
};

#endif /* MODEL_AUTOMATICWATERSERVICE_H_ */
