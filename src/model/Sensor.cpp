#include "Sensor.h"

const SensorData Sensor::ERROR = SensorData();

Sensor::~Sensor() {
}

bool Sensor::begin() {
	return true;
}
