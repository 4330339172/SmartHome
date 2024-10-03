#ifndef _LIGHT_SENSITIVTE_H
#define _LIGHT_SENSITIVTE_H

#include "main.h"
#include "adc.h"

#include <stdio.h>

#define LIGHT_SENSOR_AO_PORT GPIOA
#define LIGHT_SENSOR_AO_PIN GPIO_PIN_3
#define LIGHT_SENSOR_DO_PORT GPIOA
#define LIGHT_SENSOR_DO_PIN GPIO_PIN_4

uint16_t LightSensor_ReadAnalog(void);
uint8_t LightSensor_ReadDigital(void);
float LightSensor_GetIntensity(void);

#endif
