/*
 * OnboardValve.h
 *
 *  Created on: 19.05.2017
 *      Author: malkusch
 */

#ifndef INFRASTRUCTURE_ONBOARD_ONBOARDVALVE_H_
#define INFRASTRUCTURE_ONBOARD_ONBOARDVALVE_H_

#include <Arduino.h>

#include "../../model/Valve.h"

class OnboardValve: public Valve {
public:
	OnboardValve(byte pin);

protected:
	virtual void open();
	virtual void close();

private:
	const byte pin;
};

#endif /* INFRASTRUCTURE_ONBOARD_ONBOARDVALVE_H_ */
