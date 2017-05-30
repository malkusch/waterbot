/*
 * MillisRTC.cpp
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#include "MillisRTC.h"

#include <Arduino.h>

uint32_t MillisRTC::timestamp() const {
	return millis();
}

