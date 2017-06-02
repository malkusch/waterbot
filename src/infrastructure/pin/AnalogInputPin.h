/*
 * AnalogInputPin.h
 *
 *  Created on: 01.06.2017
 *      Author: malkusch
 */

#pragma once

#include <WString.h>

namespace waterbot {
namespace infrastructure {
namespace pin {

class AnalogInputPin {
public:
	virtual ~AnalogInputPin() {
	}
	;
	virtual int read() = 0;
	virtual String toString() = 0;
};

} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

