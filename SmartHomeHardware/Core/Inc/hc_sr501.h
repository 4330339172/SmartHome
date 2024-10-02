#ifndef _HC_SR501_H
#define _HC_SR501_H

#include "main.h"

#define PIR_PORT GPIOA
#define PIR_PIN GPIO_PIN_1

void PIR_Init(void);
uint8_t PIR_Read(void);

#endif
