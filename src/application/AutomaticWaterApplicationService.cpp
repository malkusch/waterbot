/*
 * AutomaticWaterApplicationService.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "AutomaticWaterApplicationService.h"

#include "../model/Pot.h"

using waterbot::model::Pot;

namespace waterbot {
namespace application {

AutomaticWaterApplicationService::AutomaticWaterApplicationService(
		PotRepository* potRepository, AutomaticWaterService* waterService) :
		potRepository(potRepository), waterService(waterService) {

}

void AutomaticWaterApplicationService::waterAllPotsIfNeeded() {
	Pot* pots = potRepository->findAll();
	for (int i = 0; i < potRepository->count(); i++) {
		Pot pot = pots[i];

		waterService->waterIfNeeded(&pot);
	}
}

} /* namespace drystrategy */
} /* namespace infrastructure */
