/*
 * AutomaticWaterService.h
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "SensorData.h"
#include "Pot.h"

namespace waterbot {
namespace model {

class AutomaticWaterService {
public:
	AutomaticWaterService(byte waterSeconds, unsigned int coolDownSeconds,
			byte maxWaterlessDays);
	void waterIfNeeded(Pot *pot);

private:
	const byte waterSeconds;
	const unsigned int coolDownSeconds;
	const byte maxWaterlessDays;

	bool isHot(const Pot *pot);bool isTooLongWaterLess(const Pot *pot);
};

}
}
