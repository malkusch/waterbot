/*
 * PCF8574DigitalOutputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "PCF8574SinkPin.h"

#include <Arduino.h>
#include <WString.h>

#include "../logger/Logger.h"

#define PCF8574_SINK_RETRY 3

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574SinkPin::PCF8574SinkPin(PCF8574* pcf8574, const byte pin) :
		pcf8574(pcf8574), pin(pin) {

}

void PCF8574SinkPin::begin() {
	pcf8574->pinMode(pin, OUTPUT, false);
	write(OFF);
}

void PCF8574SinkPin::write(const State state) {
	for (byte i = 0; i < PCF8574_SINK_RETRY; i++) {
		/**
		 * The PCF8574 is initially in a HIGH state. On powering up, I don't want
		 * all valves to draw current simultaneously. Therefore I define the initial
		 * state (HIGH) as OFF. Use a p-channel MOSFET, which is off when the gate is
		 * HIGH or use the pins to sink current (max. 10 mA).
		 */
		uint8_t error = pcf8574->digitalWrite(pin, state == ON ? LOW : HIGH);
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
