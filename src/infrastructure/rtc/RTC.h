/*
 * RTC.h
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_RTC_RTC_H_
#define SRC_INFRASTRUCTURE_RTC_RTC_H_

#include <stdint.h>

class RTC {
public:
	virtual ~RTC() {
	}
	;
	virtual uint32_t timestamp() const = 0;
	static RTC* getRTC();
	static void setRTC(RTC*);

private:
	static RTC* rtc;
};

#endif /* SRC_INFRASTRUCTURE_RTC_RTC_H_ */
