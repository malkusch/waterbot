// Do not remove the include below

#include "waterbot.h"

#include <Arduino.h>

#include "src/infrastructure/drystrategy/TimerDryStrategy.h"

#define REQUIRESALARMS false
#include <pins_arduino.h>
#include <RTClib/RTClib.h>
#include <stddef.h>
#include <Sleep_n0m1/Sleep_n0m1.h>

#include "src/infrastructure/drystrategy/ThresholdDryStrategy.h"
#include "src/infrastructure/Debugger.h"
#include "src/infrastructure/pin/onboard/OnboardDigitalOutputPin.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/rtc/DS1307RTC.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/infrastructure/ArrayPotRepository.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"
#include "src/application/AutomaticWaterApplicationService.h"
#include  "src/infrastructure/pcf8574/PCF8574PotRepository.h"

using waterbot::infrastructure::pin::onboard::OnboardDigitalOutputPin;
using waterbot::infrastructure::onboard::OnboardValve;
using waterbot::infrastructure::drystrategy::TimerDryStrategy;
using waterbot::model::Pump;
using waterbot::model::AutomaticWaterService;
using waterbot::model::Pot;
using waterbot::application::AutomaticWaterApplicationService;
using waterbot::infrastructure::pcf8574::PCF8574PotRepository;

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

AutomaticWaterService automaticWaterService(WATER_SECONDS, COOL_DOWN_SECONDS,
MAX_WATERLESS_DAYS);

TimerDryStrategy dryTimer(DRY_TIMER_HOURS);

PCF8574PotRepository potRepository;

Sleep sleep;

AutomaticWaterApplicationService automaticWaterApplicationService(
		&potRepository, &automaticWaterService);

void setup() {
	rtc.begin();
	logger.begin();
	Debugger::logAndClearResetReason();

	potRepository.begin(&dryTimer, &pump,
	PIN_PCF8574_VALVE, VALVE_DELAY_MILLIS,
	PIN_PCF8574_SENSOR, PIN_PCF8574_LED);

	// Water all pots, as a visual self test
	Pot** pots = potRepository.findAll();
	for (int i = 0; i < potRepository.count(); i++) {
		Pot* pot = pots[i];
		pot->water(BOOT_WATER_SECONDS);
	}
}

void loop() {
	Debugger::logMemory();
	automaticWaterApplicationService.waterAllPotsIfNeeded();
	pause(PAUSE_SECONDS);
}

void pause(unsigned long seconds) {
	logger.flush();
	byte delaySleepMillis = 100;
	delay(delaySleepMillis); // Give serial data some time to print
	sleep.pwrDownMode();
	sleep.sleepDelay(TimeUnits::secondsToMillis(seconds) - delaySleepMillis);
}

