/*
 * PauseApplicationService.cpp
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#include "PauseApplicationService.h"
#include "../model/Pot.h"

using waterbot::application::PauseApplicationService;
using waterbot::model::Pot;

PauseApplicationService::PauseApplicationService(PotRepository* potRepository,
		PauseService pauseService) :
		potRepository(potRepository), pauseService(pauseService) {
}

void PauseApplicationService::pause(unsigned long seconds) {
	Pot** pots = potRepository->findAll();
	for (unsigned long second = 0; second < seconds; second++) {
		for (byte i = 0; i < potRepository->count(); i++) {
			Pot* pot = pots[i];
			pot->blink();
		}
		pauseService.pause(1);
	}
}
