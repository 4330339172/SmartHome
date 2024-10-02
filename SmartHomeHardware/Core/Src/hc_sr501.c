#include "hc_sr501.h"

//uint8_t Infrared_test_results用于存放结果，调取PIR_Read(void)；0为没人；1为有人

void PIR_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 配置 GPIO 引脚为输入模式
    GPIO_InitStruct.Pin = PIR_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(PIR_PORT, &GPIO_InitStruct);
}

uint8_t PIR_Read(void) {
    return HAL_GPIO_ReadPin(PIR_PORT, PIR_PIN);
}
