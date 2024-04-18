#ifndef PH_Sensor_h
#define PH_Sensor_h
#include <Arduino.h>

extern float pHValue,voltage;

extern void PH_initialize();
extern void PH_valuecalc();

#endif