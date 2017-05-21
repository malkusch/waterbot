// Do not remove the include below

#include "growbot.h"

#include <Arduino.h>

#include "libraries/MemoryFree/MemoryFree.h"
#include "src/infrastructure/logger/SerialLogger.h"
#include "src/infrastructure/LED.h"
#include "src/infrastructure/onboard/OnboardMoistureSensor.h"
#include "src/infrastructure/onboard/OnboardValve.h"
#include "src/infrastructure/TimeUnits.h"
#include "src/model/Pot.h"
#include "src/model/Pump.h"

#define moistureReadCount 10
#define moistureReadMillis 100
#define moistureThreshold 200
#define valveDelayMillis 500
#define coolDownSeconds 21600 // 6h
#define maxWaterlessDays 5
#define waterSeconds 10
#define bootPauseSeconds 10
#define pauseSeconds 1200

#define warnLED LED_BUILTIN
SerialLogger logger(LED(warnLED));

#define pumpPin 12
#define pumpTurnOffDelayMillis 500
Pump pump(pumpPin, pumpTurnOffDelayMillis);

#define moisture1VoltagePin1 4
#define moisture1VoltagePin2 5
#define moistureSensor1Pin 0
OnboardMoistureSensor moistureSensor1(moisture1VoltagePin1,
moisture1VoltagePin2,
moistureSensor1Pin, moistureReadCount, moistureReadMillis);

#define valve1Pin 3
OnboardValve valve1(valve1Pin, valveDelayMillis);

Pot pot1 = Pot(maxWaterlessDays, coolDownSeconds, &moistureSensor1,
moistureThreshold, &valve1, &pump, waterSeconds);

#define moisture2VoltagePin1 6
#define moisture2VoltagePin2 7
#define moistureSensor2Pin 1
OnboardMoistureSensor moistureSensor2(moisture2VoltagePin1,
moisture2VoltagePin2,
moistureSensor2Pin, moistureReadCount, moistureReadMillis);

#define valve2Pin 8
OnboardValve valve2(valve2Pin, valveDelayMillis);

Pot pot2 = Pot(maxWaterlessDays, coolDownSeconds, &moistureSensor2,
moistureThreshold, &valve2, &pump, waterSeconds);

#define moisture3VoltagePin1 9
#define moisture3VoltagePin2 10
#define moistureSensor3Pin 2
OnboardMoistureSensor moistureSensor3(moisture3VoltagePin1,
moisture3VoltagePin2,
moistureSensor3Pin, moistureReadCount, moistureReadMillis);

#define valve3Pin 11
OnboardValve valve3(valve3Pin, valveDelayMillis);

Pot pot3 = Pot(maxWaterlessDays, coolDownSeconds, &moistureSensor3,
moistureThreshold, &valve3, &pump, waterSeconds);

Pot pots[] = { pot1, pot2, pot3 };

void setup() {
	Serial.begin(9600); // XXX Somehow the constructor of Logger doesn't work.
	Logger::setLogger(&logger);
	delay(TimeUnits::secondsToMillis(bootPauseSeconds)); // Reading the sensor instantly, reads a too low voltage
}

void loop() {
	String message = "Free memory: ";
	message += freeMemory();
	Logger::getLogger()->debug(message);

	for (auto & pot : pots) {
		pot.waterIfNeeded();
	}
	pause();
}

void pause() {
	delay(TimeUnits::secondsToMillis(pauseSeconds));
}

