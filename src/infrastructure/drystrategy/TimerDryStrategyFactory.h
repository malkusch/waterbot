/*
 * TimerDryStrategyFactory.h
 *
 *  Created on: 03.07.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../../model/DryStrategyFactory.h"

using waterbot::model::DryStrategyFactory;
using waterbot::model::DryStrategy;

namespace waterbot {
namespace infrastructure {
namespace drystrategy {

class TimerDryStrategyFactory: public DryStrategyFactory {
public:
	TimerDryStrategyFactory(const byte timerHours);
	virtual DryStrategy* build();

private:
	const byte timerHours;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

