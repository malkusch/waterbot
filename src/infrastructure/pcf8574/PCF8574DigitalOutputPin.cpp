/*
 * PCF8574DigitalOutputPin.cpp
 *
 *  Created on: 02.06.2017
 *      Author: malkusch
 */

#include "PCF8574DigitalOutputPin.h"

#include <Arduino.h>

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
	pcf8574->digitalWrite(pin, state == ON ? HIGH : LOW);
}

} /* namespace pcf8574 */
} /* namespace pin */
} /* namespace waterbot */
