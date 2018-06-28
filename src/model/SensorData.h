#ifndef SENSORDATA_H_
#define SENSORDATA_H_

typedef struct {
	float moisture;
	float temperature;
} SensorData;


inline bool operator==(const SensorData& obj1, const SensorData& obj2) {
	return obj1.moisture == obj2.moisture
			&& obj1.temperature == obj2.temperature;
}

inline bool operator!=(const SensorData& obj1, const SensorData& obj2) {
	return !(obj1 == obj2);
}


#endif
