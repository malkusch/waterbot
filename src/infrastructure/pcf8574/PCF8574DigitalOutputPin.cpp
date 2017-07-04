/*
 * PCF8574DigitalOutputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "PCF8574DigitalOutputPin.h"

#include <Arduino.h>
#include <WString.h>

#include "../logger/Logger.h"

#define PCF8574_DIGITAL_RETRY 3

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574DigitalOutputPin::PCF8574DigitalOutputPin(PCF8574* pcf8574,
		const byte pin) :
		pcf8574(pcf8574), pin(pin) {

}

void PCF8574DigitalOutputPin::begin() {
	pcf8574->pinMode(pin, OUTPUT);
	write(OFF);
}

void PCF8574DigitalOutputPin::write(const State state) {
	for (byte i = 0; i < PCF8574_DIGITAL_RETRY; i++) {
		uint8_t error = pcf8574->digitalWrite(pin, state == ON ? HIGH : LOW);
		if (error == 0) {
			return;

		} else {
			String warning = F("Failed to write pin ");
			warning += pin;
			warning += F(". Error code: ");
			warning += error;
			Logger::getLogger()->warn(warning);
			continue;
		}
	}
}

} /* namespace pcf8574 */
} /* namespace pin */
} /* namespace waterbot */
