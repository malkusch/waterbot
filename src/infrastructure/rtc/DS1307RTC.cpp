/*
 * DS1307RTC.cpp
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#include "DS1307RTC.h"

#include <WString.h>

DS1307RTC::DS1307RTC(RTC_DS1307* ds1307) :
		ds1307(ds1307) {
}

void DS1307RTC::begin() {
	ds1307->begin();
	if (!ds1307->isrunning()) {
		ds1307->adjust(DateTime(F(__DATE__), F(__TIME__)));
	}
	RTC::setRTC(this);
}

uint32_t DS1307RTC::timestamp() const {
	return ds1307->now().unixtime();
}
