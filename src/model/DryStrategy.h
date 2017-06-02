/*
 * DryStrategy.h
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#pragma once

#include "SensorData.h"

namespace waterbot {
namespace model {

class DryStrategy {
	friend class Pot;
public:
	virtual ~DryStrategy() {
	}
	;

protected:
	virtual bool isDry(SensorData) = 0;
};

}
}
