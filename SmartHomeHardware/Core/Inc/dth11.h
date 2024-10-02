#ifndef _DTH11_H
#define _DTH11_H

#include "main.h"                  // Device header
#include "tim.h"

#define DTH11_PORT GPIOA
#define DTH11_PIN GPIO_PIN_0

void Set_Pin_Input_DTH11(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void Set_Pin_Input_DTH11(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void DHT11_Start(void);

uint8_t DHT11_Check_Response(void);

char* format_sensor_data(uint8_t data_int, uint8_t data_frac);

void Read_DHT11(float *temperature, float *humidity);

uint8_t DHT11_Read(void);
#endif
