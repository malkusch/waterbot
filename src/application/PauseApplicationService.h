/*
 * PauseApplicationService.h
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#pragma once

#include "../infrastructure/PauseService.h"
#include "../model/PotRepository.h"

using waterbot::infrastructure::PauseService;
using waterbot::model::PotRepository;

namespace waterbot {
namespace application {

class PauseApplicationService {
public:
	PauseApplicationService(PotRepository*, PauseService);
	void pause(unsigned long seconds);

private:
	PotRepository* potRepository;
	PauseService pauseService;
};

}
} /* namespace infrastructure */
