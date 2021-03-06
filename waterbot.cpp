// Do not remove the include below

#include "waterbot.h"

#include <Arduino.h>

#include <pins_arduino.h>
#include <stddef.h>

#include "src/infrastructure/Debugger.h"
#include "src/infrastructure/PauseService.h"
#include "src/infrastructure/pin/onboard/OnboardDigitalOutputPin.h"
#include "src/infrastructure/drystrategy/TimerDryStrategyFactory.h"
#include "src/infrastructure/pcf8574/PCF8574PotRepository.h"
#include "src/model/AutomaticWaterService.h"
#include "src/model/Pump.h"
#include "src/application/AutomaticWaterApplicationService.h"
#include "src/application/PauseApplicationService.h"

using waterbot::infrastructure::pin::onboard::OnboardDigitalOutputPin;
using waterbot::infrastructure::drystrategy::TimerDryStrategyFactory;
using waterbot::model::Pump;
using waterbot::model::AutomaticWaterService;
using waterbot::model::Pot;
using waterbot::application::AutomaticWaterApplicationService;
using waterbot::application::PauseApplicationService;
using waterbot::infrastructure::pcf8574::PCF8574PotRepository;
using waterbot::infrastructure::PauseService;

#if LOGGER == LOGGER_SD
#include "src/infrastructure/logger/SDLogger.h"
SDLogger logger(LOG_FILE);

#else
#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"
using waterbot::infrastructure::LED;
OnboardDigitalOutputPin builtinLEDPin(LED_BUILTIN);
LED loggerLEDs(&builtinLEDPin);
SerialLogger logger(loggerLEDs, loggerLEDs);
#endif

#if PROFILE == PROFILE_DEV
#include "src/infrastructure/rtc/MillisRTC.h"
MillisRTC rtc;

#elif PROFILE == PROFILE_PRODUCTION
#include "src/infrastructure/rtc/DS1307RTC.h"
DS1307RTC rtc;
#endif

OnboardDigitalOutputPin pumpPin(PIN_PUMP);
Pump pump(&pumpPin, PUMP_TURN_OFF_DELAY_MILLIS);

AutomaticWaterService automaticWaterService(WATER_SECONDS, COOL_DOWN_SECONDS,
MAX_WATERLESS_DAYS);

TimerDryStrategyFactory dryTimerFactory(DRY_TIMER_HOURS);

PCF8574PotRepository potRepository;

AutomaticWaterApplicationService automaticWaterApplicationService(
		&potRepository, &automaticWaterService);

PauseService pause;
PauseApplicationService pauseApplicationService(&potRepository, pause);

void setup() {
	rtc.begin();
	logger.begin();
	Debugger::logAndClearResetReason();

	potRepository.begin(&dryTimerFactory, &pump,
	PIN_PCF8574_VALVE, VALVE_DELAY_MILLIS,
	PIN_PCF8574_SENSOR, PIN_PCF8574_LED, PIN_PCF8574_ERROR_LED);

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
	pauseApplicationService.pause(PAUSE_SECONDS);
}

