/*
 * ArrayPotRepository.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "ArrayPotRepository.h"

namespace waterbot {
namespace infrastructure {

ArrayPotRepository::ArrayPotRepository(Pot pots[], const byte size) :
		pots(pots), size(size) {

}

Pot* ArrayPotRepository::findAll() {
	return pots;
}

byte ArrayPotRepository::count() {
	return size;
}

} /* namespace infrastructure */
} /* namespace waterbot */
