/*
 * OnewireTemperatureSensor.h
 *
 *  Created on: 27.05.2017
 *      Author: malkusch
 */

#ifndef SRC_INFRASTRUCTURE_ONEWIRE_DALLASTEMPERATURESENSOR_H_
#define SRC_INFRASTRUCTURE_ONEWIRE_DALLASTEMPERATURESENSOR_H_

#include "../../model/TemperatureSensor.h"
#include <Arduino-Temperature-Control-Library/DallasTemperature.h>

#define DALLAS_RETRIES 3

class DallasTemperatureSensor: public TemperatureSensor {
public:
	DallasTemperatureSensor(DallasTemperature*, const uint8_t* address);
	virtual float readTemperature();

private:
	DallasTemperature* dallasTemperature;
	const uint8_t* address;
};

#endif /* SRC_INFRASTRUCTURE_ONEWIRE_DALLASTEMPERATURESENSOR_H_ */
