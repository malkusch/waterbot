/*
 * ArrayPotRepository.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

#include "../model/PotRepository.h"

using waterbot::model::PotRepository;
using waterbot::model::Pot;

namespace waterbot {
namespace infrastructure {

class ArrayPotRepository: public PotRepository {
public:
	ArrayPotRepository(Pot** pots, const byte size);

	virtual byte count();
	virtual Pot** findAll();

private:
	Pot** pots;
	const byte size;

};

} /* namespace drystrategy */
} /* namespace infrastructure */

