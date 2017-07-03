/*
 * DryStrategyFactory.h
 *
 *  Created on: 03.07.2017
 *      Author: malkusch
 */

#pragma once

#include "DryStrategy.h"

namespace waterbot {
namespace model {

class DryStrategyFactory {
public:
	virtual ~DryStrategyFactory() {
	}
	;

	virtual DryStrategy* build() = 0;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */

