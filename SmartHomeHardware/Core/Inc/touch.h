#ifndef _TOUCH_H
#define _TOUCH_H

#include "main.h"

#define TOUCH_PIN GPIO_PIN_5 // 触摸模块连接的引脚
#define TOUCH_PORT GPIOA     // 触摸模块连接的端口

uint8_t Touch_Read(void);

#endif
