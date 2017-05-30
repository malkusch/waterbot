#include "RTC.h"
#include "MillisRTC.h"

RTC* RTC::rtc;

RTC* RTC::getRTC() {
	return rtc;
}

void RTC::setRTC(RTC* rtc) {
	RTC::rtc = rtc;
}
