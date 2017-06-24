/*
 * PCF8574PotRepository.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../../model/PotRepository.h"

using waterbot::model::PotRepository;
using waterbot::model::Pot;
using waterbot::model::DryStrategy;
using waterbot::model::Pump;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

class PCF8574PotRepository: public PotRepository {
public:
	PCF8574PotRepository();
	~PCF8574PotRepository();
	void begin(DryStrategy*, Pump*, const byte valvePin, unsigned int valveDelayMillis, const byte am2321Pin);
	virtual byte count();
	virtual Pot** findAll();

private:
	bool probeAddress(const byte address);
	Pot** pots;
	byte size;
};

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */

