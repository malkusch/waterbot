/*
 * ThresholdDryStrategy.h
 *
 *  Created on: 21.05.2017
 *      Author: malkusch
 */

#ifndef INFRASTRUCTURE_DRYSTRATEGY_THRESHOLDDRYSTRATEGY_H_
#define INFRASTRUCTURE_DRYSTRATEGY_THRESHOLDDRYSTRATEGY_H_

#include "../../model/DryStrategy.h"
#include "../../model/SensorData.h"

using waterbot::model::DryStrategy;

class ThresholdDryStrategy: public DryStrategy {
public:
	ThresholdDryStrategy(const float moistureThreshold);

protected:
	virtual bool isDry(SensorData);

private:
	const float moistureThreshold;
};

#endif /* INFRASTRUCTURE_DRYSTRATEGY_THRESHOLDDRYSTRATEGY_H_ */
