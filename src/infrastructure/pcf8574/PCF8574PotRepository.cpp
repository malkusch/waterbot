/*
 * PCF8574PotRepository.cpp
 *
 *  Created on: 24.06.2017
 *      Author: malkusch
 */

#include "PCF8574PotRepository.h"

#include <Arduino-PCF8574/src/PCF8574.h>
#include <BME280/BME280_MOD-1022.h>
#include <binary.h>
#include <Print.h>
#include <Wire.h>
#include <WString.h>

#include "../../model/DryStrategy.h"
#include "../../model/Pot.h"
#include "../../model/Pump.h"
#include "../../model/Sensor.h"
#include "../../model/Valve.h"
#include "../logger/Logger.h"
#include "../LED.h"
#include "PCF8574Sensor.h"
#include "PCF8574SinkPin.h"

using waterbot::model::Valve;
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

void PCF8574PotRepository::begin(DryStrategyFactory* dryStrategyFactory,
		Pump* pump, const byte valvePin, const unsigned int valveDelayMillis,
		const byte sensorPin, const byte ledPin) {

	Wire.begin();
	byte addresses[16];

	for (byte addressPins = B000; addressPins <= B111; addressPins++) {
		byte address = B0100000 | addressPins;
		if (probeAddress(address)) {
			addresses[size] = address;
			size++;
		}

		address = B01110000 | (addressPins << 1);
		if (address == addrBME280) {
			continue;
		}
		if (probeAddress(address)) {
			addresses[size] = address;
			size++;
		}
	}

	pots = new Pot*[size];
	for (byte i = 0; i < size; i++) {
		const byte id = extractId(addresses[i]);
		PCF8574* expander = new PCF8574();
		expander->begin(addresses[i]);

		PCF8574SinkPin* _sensorPin = new PCF8574SinkPin(expander, sensorPin);
		_sensorPin->begin();
		BusSwitch* busSwitch = new BusSwitch(_sensorPin);
		Sensor* sensor = new PCF8574Sensor(busSwitch);
		sensor->begin();

		PCF8574SinkPin* _valvePin = new PCF8574SinkPin(expander, valvePin);
		_valvePin->begin();
		Valve* valve = new Valve(_valvePin, valveDelayMillis);

		DryStrategy* drystrategy = dryStrategyFactory->build();

		Pot* pot = new Pot(id, sensor, drystrategy, valve, pump);

		PCF8574SinkPin _ledPin(expander, ledPin);
		_ledPin.begin();
		LED led(&_ledPin);
		led.turnOn();

		pots[i] = pot;
	}
}

byte PCF8574PotRepository::extractId(const byte address) {
	if ((address & B1110000) == B0100000) {
		return address & B111;
	} else {
		return ((address & B1111) >> 1) + 8;
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
