/*
 * TimerDryStrategy.h
 *
 *  Created on: 17.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../../model/DryStrategy.h"
#include "../../model/SensorData.h"

using waterbot::model::DryStrategy;

namespace waterbot {
namespace infrastructure {
namespace drystrategy {

class TimerDryStrategy: public DryStrategy {
public:
	TimerDryStrategy(const byte timerHours);

protected:
	virtual bool isDry(SensorData);

private:
	const byte timerHours;
	unsigned long lastDryTime;
};

} /* namespace drystrategy */
} /* namespace infrastructure */
} /* namespace waterbot */
