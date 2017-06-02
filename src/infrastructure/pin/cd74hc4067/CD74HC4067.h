/*
 * CD74HC4067.h
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#pragma once

#include <Arduino.h>

namespace waterbot {
namespace infrastructure {
namespace pin {
namespace cd74hc4067 {

#define CD74HC4067_RISE_MICROSECONDS 1

class CD74HC4067 {
public:
	CD74HC4067(const byte ioPin, const byte s0Pin, const byte s1Pin,
			const byte s2Pin, const byte s3Pin, const byte ePin);

public:
	void startSelectChannel();
	void selectChannel(const byte channel);
	void commitSelectChannel();
	bool isSelected(const byte channel);
	const byte ioPin;

private:
	byte selectedChannel;
	const byte s0Pin;
	const byte s1Pin;
	const byte s2Pin;
	const byte s3Pin;
	const byte ePin;
};

} /* namespace cd74hc4067 */
} /* namespace pin */
} /* namespace infrastructure */
} /* namespace waterbot */

