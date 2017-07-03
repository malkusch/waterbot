/*
 * TimerDryStrategyFactory.cpp
 *
 *  Created on: 03.07.2017
 *      Author: malkusch
 */

#include "TimerDryStrategyFactory.h"

#include <Arduino.h>

#include "TimerDryStrategy.h"

using waterbot::infrastructure::drystrategy::TimerDryStrategy;

namespace waterbot {
namespace infrastructure {
namespace drystrategy {

TimerDryStrategyFactory::TimerDryStrategyFactory(const byte timerHours) :
		timerHours(timerHours) {

}

DryStrategy* TimerDryStrategyFactory::build() {
	return new TimerDryStrategy(timerHours);
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
