/*
 * PCF8574DigitalOutputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "PCF8574SinkPin.h"

#include <Arduino.h>

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574SinkPin::PCF8574SinkPin(PCF8574* pcf8574,
		const byte pin) :
		pcf8574(pcf8574), pin(pin) {

}

void PCF8574SinkPin::begin() {
	pcf8574->pinMode(pin, OUTPUT, false);
	write(OFF);
}

void PCF8574SinkPin::write(const State state) {
	/**
	 * The PCF8574 is initially in a HIGH state. On powering up, I don't want
	 * all valves to draw current simultaneously. Therefore I define the initial
	 * state (HIGH) as OFF. Use a p-channel MOSFET, which is off when the gate is
	 * HIGH or use the pins to sink current (max. 10 mA).
	 */
	pcf8574->digitalWrite(pin, state == ON ? LOW : HIGH);
}

} /* namespace pcf8574 */
} /* namespace pin */
} /* namespace waterbot */
