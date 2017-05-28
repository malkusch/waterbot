// Do not remove the include below

#include "waterbot.h"

#include <Arduino.h>
#include <Arduino-Temperature-Control-Library/DallasTemperature.h>
#include <HardwareSerial.h>
#include <OneWire/OneWire.h>
#include <stddef.h>
#include <Sleep_n0m1/Sleep_n0m1.h>

#include "src/infrastructure/drystrategy/ThresholdDryStrategy.h"
#include "src/infrastructure/Debugger.h"
#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"
#include "src/infrastructure/onboard/OnboardMoistureSensor.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/onewire/DallasTemperatureSensor.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

#define PIN_MOISTURE1_SENSOR 0
#define PIN_MOISTURE2_SENSOR 1
#define PIN_MOISTURE3_SENSOR 2

#define PIN_ONEWIRE 			2
#define PIN_VALVE1 				3
#define PIN_MOISTURE1_VOLTAGE1 	4
#define PIN_MOISTURE1_VOLTAGE2 	5
#define PIN_MOISTURE2_VOLTAGE1 	6
#define PIN_MOISTURE2_VOLTAGE2 	7
#define PIN_VALVE2 				8
#define PIN_MOISTURE3_VOLTAGE1 	9
#define PIN_MOISTURE3_VOLTAGE2 	10
#define PIN_VALVE3 				11
#define PIN_PUMP 				12
#define PIN_WARNLED 			LED_BUILTIN
#define PIN_ERRORLED 			LED_BUILTIN

#define MOISTURE_READ_COUNT 10
#define MOISTURE_VOLTAGE_DELAY_MILLIS 1000
#define MOISTURE_THRESHOLD 200
#define VALVE_DELAY_MILLIS 500
#define COOL_DOWN_SECONDS 21600 // 6h
#define MAX_WATERLESS_DAYS 5
#define WATER_SECONDS 10
#define BOOT_WATER_SECONDS 3
#define PAUSE_SECONDS 1200
#define PUMP_TURN_OFF_DELAY_MILLIS 500
#define TEMPERATURE_RESOLUTION 9

SerialLogger logger(LED(PIN_WARNLED), LED(PIN_ERRORLED));
Pump pump(PIN_PUMP, PUMP_TURN_OFF_DELAY_MILLIS);

OneWire onewire(PIN_ONEWIRE);
DallasTemperature dallasTemperature(&onewire);
DallasTemperatureSensor temperatureSensor(&dallasTemperature, NULL);

AutomaticWaterService automaticWaterService(WATER_SECONDS, COOL_DOWN_SECONDS,
MAX_WATERLESS_DAYS);

ThresholdDryStrategy thresholdDryStrategy(MOISTURE_THRESHOLD);

OnboardMoistureSensor moistureSensor1(PIN_MOISTURE1_VOLTAGE1,
PIN_MOISTURE1_VOLTAGE2,
PIN_MOISTURE1_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve1(PIN_VALVE1, VALVE_DELAY_MILLIS);

Pot pot1 = Pot(&moistureSensor1, &temperatureSensor, &thresholdDryStrategy,
		&valve1, &pump);

OnboardMoistureSensor moistureSensor2(PIN_MOISTURE2_VOLTAGE1,
PIN_MOISTURE2_VOLTAGE2,
PIN_MOISTURE2_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve2(PIN_VALVE2, VALVE_DELAY_MILLIS);

Pot pot2 = Pot(&moistureSensor2, &temperatureSensor, &thresholdDryStrategy,
		&valve2, &pump);

OnboardMoistureSensor moistureSensor3(PIN_MOISTURE3_VOLTAGE1,
PIN_MOISTURE3_VOLTAGE2,
PIN_MOISTURE3_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve3(PIN_VALVE3, VALVE_DELAY_MILLIS);

Pot pot3 = Pot(&moistureSensor3, &temperatureSensor, &thresholdDryStrategy,
		&valve3, &pump);

Pot pots[] = { pot1, pot2, pot3 };

Sleep sleep;

void setup() {
	Serial.begin(9600); // XXX Somehow the constructor of Logger doesn't work.
	dallasTemperature.begin();
	dallasTemperature.setResolution(TEMPERATURE_RESOLUTION);

	Logger::setLogger(&logger);
	Debugger::logAndClearResetReason();

	// Water all pots, as a visual self test
	for (auto & pot : pots) {
		pot.water(BOOT_WATER_SECONDS);
	}
}

void loop() {
	Debugger::logMemory();

	for (auto & pot : pots) {
		automaticWaterService.waterIfNeeded(&pot);
	}
	pause(PAUSE_SECONDS);
}

void pause(unsigned long seconds) {
	byte delaySleepMillis = 100;
	delay(delaySleepMillis); // Give serial data some time to print
	sleep.pwrDownMode();
	sleep.sleepDelay(TimeUnits::secondsToMillis(seconds) - delaySleepMillis);
}

