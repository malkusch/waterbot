/*
 * PotRepository.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>
#include "Pot.h"

namespace waterbot {
namespace model {

class PotRepository {
public:
	virtual ~PotRepository() {
	}
	;

	virtual byte count() = 0;
	virtual Pot* findAll() = 0;
};

} /* namespace drystrategy */
} /* namespace infrastructure */

