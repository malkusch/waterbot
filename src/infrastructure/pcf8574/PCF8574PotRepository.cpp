/*
 * PCF8574PotRepository.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "PCF8574PotRepository.h"

#include <Arduino-PCF8574/src/PCF8574.h>
#include <binary.h>
#include <Print.h>
#include <Wire.h>
#include <WString.h>

#include "../../model/DryStrategy.h"
#include "../../model/Pot.h"
#include "../../model/Pump.h"
#include "../logger/Logger.h"
#include "../LED.h"
#include "../onboard/OnboardValve.h"
#include "AM2321Sensor.h"
#include "PCF8574DigitalOutputPin.h"
#include "PCF8574SinkPin.h"

using waterbot::model::Valve;
using waterbot::infrastructure::onboard::OnboardValve;
using waterbot::infrastructure::LED;

namespace waterbot {
namespace infrastructure {
namespace pcf8574 {

PCF8574PotRepository::PCF8574PotRepository() {
	size = 0;
	pots = 0;
}

PCF8574PotRepository::~PCF8574PotRepository() {
	for (byte i = 0; i < size; i++) {
		delete pots[i];
	}
	delete pots;
}

void PCF8574PotRepository::begin(DryStrategy* dryStrategy, Pump* pump,
		const byte valvePin, unsigned int valveDelayMillis,
		const byte am2321Pin, const byte ledPin) {

	Wire.begin();
	byte addresses[16];

	for (byte addressPins = B000; addressPins <= B111; addressPins++) {
		byte address = B0100000 | addressPins;
		if (probeAddress(address)) {
			addresses[size] = address;
			size++;
		}

		address = B01110000 | (addressPins << 1);
		if (probeAddress(address)) {
			addresses[size] = address;
			size++;
		}
	}

	pots = new Pot*[size];
	for (byte i = 0; i < size; i++) {
		PCF8574* expander = new PCF8574();
		expander->begin(addresses[i]);

		PCF8574DigitalOutputPin* _am2321Pin = new PCF8574DigitalOutputPin(
				expander, am2321Pin);
		_am2321Pin->begin();
		AM2321Sensor* aM2321 = new AM2321Sensor(_am2321Pin);
		MoistureSensor* moistureSensor = aM2321;
		TemperatureSensor* temperatureSensor = aM2321;

		PCF8574SinkPin* _valvePin = new PCF8574SinkPin(expander, valvePin);
		_valvePin->begin();
		Valve* valve = new OnboardValve(_valvePin, valveDelayMillis);

		Pot* pot = new Pot(moistureSensor, temperatureSensor, dryStrategy,
				valve, pump);

		PCF8574SinkPin _ledPin = PCF8574SinkPin(expander, ledPin);
		_ledPin.begin();
		LED led(&_ledPin);
		led.turnOn();

		pots[i] = pot;
	}
}

bool PCF8574PotRepository::probeAddress(const byte address) {
	Wire.beginTransmission(address);
	bool probed = Wire.endTransmission() == 0;
	if (probed) {
		String message = F("Found PCF8574 at address B");
		message += String(address, BIN);
		Logger::getLogger()->info(message);
	}
	return probed;
}

Pot** PCF8574PotRepository::findAll() {
	return pots;
}

byte PCF8574PotRepository::count() {
	return size;
}

} /* namespace pcf8574 */
} /* namespace infrastructure */
} /* namespace waterbot */
