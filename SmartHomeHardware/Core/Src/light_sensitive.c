#include "light_sensitive.h"

uint16_t LightSensor_Read() {
    HAL_ADC_Start(&hadc1);
   // HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint16_t adc_value = HAL_ADC_GetValue(&hadc1);
  //  HAL_ADC_Stop(&hadc1);
    return adc_value;
}

uint16_t LightSensor_ReadAnalog(void) {
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint16_t adc_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);
    return adc_value;
}

uint8_t LightSensor_ReadDigital(void) {
return HAL_GPIO_ReadPin(LIGHT_SENSOR_DO_PORT, LIGHT_SENSOR_DO_PIN);
}

float LightSensor_GetIntensity() {
// 根据传感器的特性曲线，将 ADC 值转换为光线强度
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint16_t adc_value = HAL_ADC_GetValue(&hadc1);
    HAL_ADC_Stop(&hadc1);
    float intensity = (float)adc_value * (3.3 / 4096.0); // 假设 5V 参考电压和 12 位 ADC
    return intensity;
}
