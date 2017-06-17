// Do not remove the include below

#include "waterbot.h"

#include <Arduino.h>

#include "src/infrastructure/drystrategy/TimerDryStrategy.h"

#define REQUIRESALARMS false
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
#include "src/infrastructure/pin/onboard/OnboardAnalogInputPin.h"
#include "src/infrastructure/pin/onboard/OnboardDigitalOutputPin.h"
#include "src/infrastructure/rtc/DS1307RTC.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

using waterbot::infrastructure::pin::onboard::OnboardDigitalOutputPin;
using waterbot::infrastructure::pin::onboard::OnboardAnalogInputPin;
using waterbot::infrastructure::onboard::OnboardValve;
using waterbot::infrastructure::onboard::OnboardDCMoistureSensor;
using waterbot::infrastructure::drystrategy::TimerDryStrategy;
using waterbot::model::Pump;
using waterbot::model::AutomaticWaterService;
using waterbot::model::Pot;

#if LOGGER == LOGGER_SD

#include "src/infrastructure/logger/SDLogger.h"
SDLogger logger(LOG_FILE);

#else

#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"

using waterbot::infrastructure::LED;

OnboardDigitalOutputPin builtinLEDPin(LED_BUILTIN);
LED warnLED(&builtinLEDPin);
LED errorLED(&builtinLEDPin);
SerialLogger logger(warnLED, errorLED);

#endif

OnboardDigitalOutputPin pumpPin(PIN_PUMP);
Pump pump(&pumpPin, PUMP_TURN_OFF_DELAY_MILLIS);

// MillisRTC rtc;
RTC_DS1307 ds1307;
DS1307RTC rtc(&ds1307);

OneWire onewire(PIN_ONEWIRE);
DallasTemperature dallasTemperature(&onewire);
DallasTemperatureSensor temperatureSensor(&dallasTemperature, NULL);

AutomaticWaterService automaticWaterService(WATER_SECONDS, COOL_DOWN_SECONDS,
MAX_WATERLESS_DAYS);

TimerDryStrategy dryTimer1(DRY_TIMER_HOURS);
OnboardAnalogInputPin moistureSensor1SensorPin(PIN_POT1_MOISTURE_SENSOR);
OnboardDigitalOutputPin moistureSensor1VoltagePin(PIN_POT1_MOISTURE_VOLTAGE);
OnboardDCMoistureSensor moistureSensor1(&moistureSensor1VoltagePin,
		&moistureSensor1SensorPin, MOISTURE_READ_COUNT,
		MOISTURE_VOLTAGE_DELAY_MILLIS);
OnboardDigitalOutputPin valve1Pin(PIN_POT1_VALVE);
OnboardValve valve1(&valve1Pin, VALVE_DELAY_MILLIS);
Pot pot1 = Pot(&moistureSensor1, &temperatureSensor, &dryTimer1, &valve1,
		&pump);

TimerDryStrategy dryTimer2(DRY_TIMER_HOURS);
OnboardAnalogInputPin moistureSensor2SensorPin(PIN_POT2_MOISTURE_SENSOR);
OnboardDigitalOutputPin moistureSensor2VoltagePin(PIN_POT2_MOISTURE_VOLTAGE);
OnboardDCMoistureSensor moistureSensor2(&moistureSensor2VoltagePin,
		&moistureSensor2SensorPin, MOISTURE_READ_COUNT,
		MOISTURE_VOLTAGE_DELAY_MILLIS);
OnboardDigitalOutputPin valve2Pin(PIN_POT2_VALVE);
OnboardValve valve2(&valve2Pin, VALVE_DELAY_MILLIS);
Pot pot2 = Pot(&moistureSensor2, &temperatureSensor, &dryTimer2, &valve2,
		&pump);

TimerDryStrategy dryTimer3(DRY_TIMER_HOURS);
OnboardAnalogInputPin moistureSensor3SensorPin(PIN_POT3_MOISTURE_SENSOR);
OnboardDigitalOutputPin moistureSensor3VoltagePin(PIN_POT3_MOISTURE_VOLTAGE);
OnboardDCMoistureSensor moistureSensor3(&moistureSensor3VoltagePin,
		&moistureSensor3SensorPin, MOISTURE_READ_COUNT,
		MOISTURE_VOLTAGE_DELAY_MILLIS);
OnboardDigitalOutputPin valve3Pin(PIN_POT3_VALVE);
OnboardValve valve3(&valve3Pin, VALVE_DELAY_MILLIS);
Pot pot3 = Pot(&moistureSensor3, &temperatureSensor, &dryTimer3, &valve3,
		&pump);

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

