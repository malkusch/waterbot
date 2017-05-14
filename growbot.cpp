// Do not remove the include below

#include "growbot.h"

#include <Arduino.h>

#include "MoistureSensor.h"
#include "Pump.h"
#include "SensorLogger.h"
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
#define pumpCoolDownSeconds 21600 //6h
Pump pump(pumpPin, pumpCoolDownSeconds, pumpSeconds);

#define pauseSeconds 60

SensorLogger sensorLogger;

void setup() {
}

void loop() {
	const SensorData data = readSensors();
	sensorLogger.log(data);
	if (data.moisture < moistureThreshold && !pump.isHot()) {
		pump.pump();
	}
	pause();
}

void pause() {
	delay(TimeUnits::secondsToMillis(pauseSeconds));
}

SensorData readSensors() {
	SensorData data;
	data.moisture = moistureSensor.readMoisture();
	return data;
}

