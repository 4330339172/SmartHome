#include "hc_sr501.h"

//uint8_t Infrared_test_results用于存放结果，调取PIR_Read(void)；0为没人；1为有人


uint8_t PIR_Read(void) {
    return HAL_GPIO_ReadPin(PIR_PORT, PIR_PIN);
}
