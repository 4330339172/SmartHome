#include "buzzer.h"


void Buzzer_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    // 配置 GPIO 引脚为输出模式
    GPIO_InitStruct.Pin = BUZZER_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(BUZZER_PORT, &GPIO_InitStruct);
}

void Buzzer_On(void) {
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}

void Buzzer_Off(void) {
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
}
