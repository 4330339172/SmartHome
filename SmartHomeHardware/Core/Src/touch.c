#include "touch.h"

uint8_t Touch_Read(void)
{
return HAL_GPIO_ReadPin(TOUCH_PORT, TOUCH_PIN);
}
