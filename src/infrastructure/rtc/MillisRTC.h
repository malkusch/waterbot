/*
 * MillisRTC.h
 *
 *  Created on: 30.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_RTC_MILLISRTC_H_
#define SRC_INFRASTRUCTURE_RTC_MILLISRTC_H_

#include <stdint.h>

#include "RTC.h"

class MillisRTC: public RTC {
public:

	virtual uint32_t timestamp() const;

};

#endif /* SRC_INFRASTRUCTURE_RTC_MILLISRTC_H_ */
