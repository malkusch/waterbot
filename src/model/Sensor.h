#pragma once

#include "SensorData.h"

class Sensor {

public:
	const static SensorData ERROR;
	virtual ~Sensor();
	virtual SensorData read() = 0;
	virtual bool begin();

};
