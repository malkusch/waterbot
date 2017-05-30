// Do not remove the include below

#include "waterbot.h"

#include <Arduino.h>
#include <Arduino-Temperature-Control-Library/DallasTemperature.h>
#include <OneWire/OneWire.h>
#include <pins_arduino.h>
#include <RTClib/RTClib.h>
#include <stddef.h>
#include <Sleep_n0m1/Sleep_n0m1.h>

#include "src/infrastructure/drystrategy/ThresholdDryStrategy.h"
#include "src/infrastructure/Debugger.h"
#include "src/infrastructure/logger/SDLogger.h"
#include "src/infrastructure/onboard/OnboardMoistureSensor.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/onewire/DallasTemperatureSensor.h"
#include "src/infrastructure/rtc/DS1307RTC.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

#define PIN_MOISTURE1_SENSOR 0
#define PIN_MOISTURE2_SENSOR 1
#define PIN_MOISTURE3_SENSOR 2

#define PIN_ONEWIRE 			2
#define PIN_PUMP 				3
#define PIN_VALVE1 				4
#define PIN_MOISTURE1_VOLTAGE1 	5
#define PIN_MOISTURE1_VOLTAGE2 	6
#define PIN_VALVE2				7
#define PIN_MOISTURE2_VOLTAGE1 	8
#define PIN_MOISTURE2_VOLTAGE2 	9
#define PIN_SDLOG_CHIPSELECT	SS

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
#define LOG_FILE "waterbot-%d.log"

SDLogger logger(PIN_SDLOG_CHIPSELECT);
Pump pump(PIN_PUMP, PUMP_TURN_OFF_DELAY_MILLIS);

// MillisRTC rtc;
RTC_DS1307 ds1307;
DS1307RTC rtc(&ds1307);

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

Pot pots[] = { pot1, pot2 };

Sleep sleep;

void setup() {
	rtc.begin();
	logger.begin(LOG_FILE);
	dallasTemperature.begin();
	dallasTemperature.setResolution(TEMPERATURE_RESOLUTION);
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
	logger.flush();
	byte delaySleepMillis = 100;
	delay(delaySleepMillis); // Give serial data some time to print
	sleep.pwrDownMode();
	sleep.sleepDelay(TimeUnits::secondsToMillis(seconds) - delaySleepMillis);
}

