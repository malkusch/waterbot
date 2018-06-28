/*
 * PauseService.h
 *
 *  Created on: 28.06.2018
 *      Author: malkusch
 */

#pragma once

namespace waterbot {
namespace infrastructure {

class PauseService {
public:
	PauseService();
	void pause(unsigned long seconds);
};

} /* namespace infrastructure */
} /* namespace waterbot */
