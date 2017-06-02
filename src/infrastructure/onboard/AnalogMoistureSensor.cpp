/*
 * AnalogMoistureSensor.cpp
 *
 *  Created on: 31.05.2017
 *      Author: malkusch
 */

#include "AnalogMoistureSensor.h"

#include <QuickStats/QuickStats.h>
#include <WString.h>

#include "../logger/Logger.h"

using waterbot::infrastructure::onboard::AnalogMoistureSensor;

AnalogMoistureSensor::AnalogMoistureSensor(AnalogInputPin* sensorPin,
		const byte readCount) :
		sensorPin(sensorPin), readCount(readCount) {

}

int AnalogMoistureSensor::singleReadMoisture() {
	return sensorPin->read();
}

int AnalogMoistureSensor::readMoisture() {
	float data[readCount];
	readRawMoisture(data, readCount);

	QuickStats stats;
	float median = stats.median(data, readCount);
	float error = stats.stderror(data, readCount);

	String debugError = F("Sensor at pin ");
	debugError += sensorPin->toString() + F(" has ") + error + F(" error");
	Logger::getLogger()->debug(debugError);

	if (median < 10) {
		String warning = F("Sensor at pin ");
		warning += sensorPin->toString() + F(" reads too low: ") + median;
		Logger::getLogger()->warn(warning);
	}
	if (median > 1023 - 10) {
		String warning = F("Sensor at pin ");
		warning += sensorPin->toString() + F(" reads too high: ") + median;
		Logger::getLogger()->warn(warning);
	}
	if (error > 50) {
		String warning = F("Sensor at pin ");
		warning += sensorPin->toString() + F(" has too much error: ") + error;
		Logger::getLogger()->warn(warning);
	}

	return median;
}
