#ifndef _BUZZER_H
#define _BUZZER_H

#include "main.h"

#define BUZZER_PORT GPIOA
#define BUZZER_PIN GPIO_PIN_2

void Buzzer_On(void);
void Buzzer_Off(void);

#endif
