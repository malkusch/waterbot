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
#include "src/infrastructure/onboard/OnboardDCMoistureSensor.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/onewire/DallasTemperatureSensor.h"
#include "src/infrastructure/rtc/DS1307RTC.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

#if LOGGER == LOGGER_SD
#include "src/infrastructure/logger/SDLogger.h"
SDLogger logger(LOG_FILE);
#else
#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"
SerialLogger logger(LED(LED_BUILTIN), LED(LED_BUILTIN));
#endif

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

OnboardDCMoistureSensor moistureSensor1(PIN_POT1_MOISTURE_VOLTAGE,
PIN_POT1_MOISTURE_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve1(PIN_POT1_VALVE, VALVE_DELAY_MILLIS);

Pot pot1 = Pot(&moistureSensor1, &temperatureSensor, &thresholdDryStrategy,
		&valve1, &pump);

OnboardDCMoistureSensor moistureSensor2(PIN_POT2_MOISTURE_VOLTAGE,
PIN_POT2_MOISTURE_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve2(PIN_POT2_VALVE, VALVE_DELAY_MILLIS);

Pot pot2 = Pot(&moistureSensor2, &temperatureSensor, &thresholdDryStrategy,
		&valve2, &pump);

OnboardDCMoistureSensor moistureSensor3(PIN_POT3_MOISTURE_VOLTAGE,
PIN_POT3_MOISTURE_SENSOR, MOISTURE_READ_COUNT, MOISTURE_VOLTAGE_DELAY_MILLIS);

OnboardValve valve3(PIN_POT3_VALVE, VALVE_DELAY_MILLIS);

Pot pot3 = Pot(&moistureSensor3, &temperatureSensor, &thresholdDryStrategy,
		&valve3, &pump);

Pot pots[] = { pot1, pot2, pot3 };

Sleep sleep;

void setup() {
	rtc.begin();
	logger.begin();
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

