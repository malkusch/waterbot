/*
 * DS1307RTC.h
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_RTC_DS1307RTC_H_
#define SRC_INFRASTRUCTURE_RTC_DS1307RTC_H_

#include <stdint.h>

#include "RTC.h"
#include "RTClib/RTClib.h"

class DS1307RTC: public RTC {
public:
	DS1307RTC(const RTC_DS1307* ds1307);
	void begin();
	virtual uint32_t timestamp() const;

private:
	const RTC_DS1307* ds1307;

};

#endif /* SRC_INFRASTRUCTURE_RTC_DS1307RTC_H_ */
