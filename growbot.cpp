// Do not remove the include below

#include "growbot.h"

#include <Arduino.h>
#include <WString.h>

#include "Logger.h"
#include "MoistureSensor.h"
#include "Pump.h"
#include "TimeUnits.h"

#define moistureVoltagePin1 6
#define moistureVoltagePin2 7
#define sensorPin 0
#define moistureReadCount 10
#define moistureReadMillis 100
#define moistureThreshold 200
MoistureSensor moistureSensor(moistureVoltagePin1, moistureVoltagePin2,
sensorPin, moistureReadCount, moistureReadMillis);

#define pumpPin 5
#define pumpSeconds 30
#define pumpCoolDownSeconds 21600 // 6h
#define maxPumplessDays 5
Pump pump(pumpPin, pumpCoolDownSeconds, pumpSeconds);

#define pauseSeconds 1200

#define warnLED LED_BUILTIN
Logger logger(LED(warnLED));

void setup() {
	Serial.begin(9600); // XXX Somehow the constructor of Logger doesn't work.
}

void loop() {
	const SensorData data = readSensors();
	bool pumping = false;

	if (isDry(data) && !pump.isHot()) {
		pumping = true;
		pump.pump();
	}
	logger.info(data, pumping);
	pause();
}

bool isDry(SensorData data) {
	unsigned long maxPumplessTime = pump.getLastPumpTime()
			+ TimeUnits::daysToMillis(maxPumplessDays);
	if (millis() > maxPumplessTime) {
		logger.warn(
				"Sensors didn't report 'dry' for " + String(maxPumplessDays)
						+ "days");
		return true;
	}

	return data.moisture < moistureThreshold;
}

void pause() {
	delay(TimeUnits::secondsToMillis(pauseSeconds));
}

SensorData readSensors() {
	SensorData data;
	data.moisture = moistureSensor.readMoisture();
	return data;
}

