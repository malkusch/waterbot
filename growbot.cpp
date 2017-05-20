// Do not remove the include below

#include "growbot.h"

#include <Arduino.h>

#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"
#include "src/infrastructure/onboard/OnboardMoistureSensor.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

#define pumpPin 5
#define pumpSeconds 30
#define pumpTurnOffDelayMillis 500
Pump pump(pumpPin, pumpSeconds, pumpTurnOffDelayMillis);

#define moistureReadCount 10
#define moistureReadMillis 100
#define moistureThreshold 200

#define valveDelayMillis 500

#define moisture1VoltagePin1 6
#define moisture1VoltagePin2 7
#define moistureSensor1Pin 0
OnboardMoistureSensor moistureSensor1(moisture1VoltagePin1,
moisture1VoltagePin2,
moistureSensor1Pin, moistureReadCount, moistureReadMillis);

#define valve1Pin 8
OnboardValve valve1(valve1Pin, valveDelayMillis);

#define coolDownSeconds 21600 // 6h
#define maxWaterlessDays 5

Pot pot1 = Pot(maxWaterlessDays, coolDownSeconds, &moistureSensor1,
moistureThreshold, &valve1, pump);

Pot pots[] = { pot1 };

#define bootPauseSeconds 10
#define pauseSeconds 1200

#define warnLED LED_BUILTIN
SerialLogger logger(LED(warnLED));

void setup() {
	Serial.begin(9600); // XXX Somehow the constructor of Logger doesn't work.
	Logger::setLogger(&logger);
	delay(TimeUnits::secondsToMillis(bootPauseSeconds)); // Reading the sensor instantly, reads a too low voltage
}

void loop() {
	for (auto & pot : pots) {
		pot.waterIfNeeded();
	}
	pause();
}

void pause() {
	delay(TimeUnits::secondsToMillis(pauseSeconds));
}

