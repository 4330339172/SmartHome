#ifndef _DTH22_H
#define _DTH22_H

#include "main.h"                  // Device header
#include "tim.h"

#define DTH22_PORT GPIOA
#define DTH22_PIN GPIO_PIN_0

void Set_Pin_Input_DTH22(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void Set_Pin_Input_DTH22(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin);

void DHT22_Start(void);

void Read_DHT22(float *temperature, float *humidity);

uint8_t DHT22_Check_Response(void);

//char* format_sensor_data(uint8_t data_int, uint8_t data_frac);

uint8_t DHT22_Read(void);
#endif
