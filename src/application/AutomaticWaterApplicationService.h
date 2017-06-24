/*
 * AutomaticWaterApplicationService.h
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#pragma once

#include "../model/PotRepository.h"
#include "../model/AutomaticWaterService.h"

using waterbot::model::PotRepository;
using waterbot::model::AutomaticWaterService;

namespace waterbot {
namespace application {

class AutomaticWaterApplicationService {
public:
	AutomaticWaterApplicationService(PotRepository*, AutomaticWaterService*);
	void waterAllPotsIfNeeded();

private:
	PotRepository* potRepository;
	AutomaticWaterService* waterService;
};

} /* namespace infrastructure */
} /* namespace waterbot */

