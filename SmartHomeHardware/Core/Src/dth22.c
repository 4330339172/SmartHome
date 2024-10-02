#include "dth22.h"

//main.c中的全局变量
//uint8_t Humi_H,Humi_L,Temp_H,Temp_L;
//uint8_t Temperature_integerPart = 0;
//uint8_t Humidity_integerPart = 0;
//uint8_t Presence = 0;

void Set_Pin_Output_DTH22(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_IninStruct ={0};
    GPIO_IninStruct.Pin=GPIO_Pin;
    GPIO_IninStruct.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_IninStruct.Speed=GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx,&GPIO_IninStruct);
}

void Set_Pin_Input_DTH22(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
     GPIO_InitTypeDef GPIO_IninStruct ={0};
    GPIO_IninStruct.Pin=GPIO_Pin;
    GPIO_IninStruct.Mode=GPIO_MODE_INPUT;
    GPIO_IninStruct.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(GPIOx,&GPIO_IninStruct);
}

void DHT22_Start(void)
{
    Set_Pin_Output_DTH22(DTH22_PORT,DTH22_PIN);
    HAL_GPIO_WritePin(DTH22_PORT,DTH22_PIN,GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(DTH22_PORT,DTH22_PIN,GPIO_PIN_SET);
    delay_us(30);
    Set_Pin_Input_DTH22(DTH22_PORT,DTH22_PIN);
}

uint8_t DHT22_Check_Response(void)
{
    int8_t Response=0;
    delay_us(40);
    if(HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN)==GPIO_PIN_RESET)
    {
        delay_us(80);
        if((HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN)))
            Response=1;
        else 
            Response=-1;
    }
    while ((HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN))) 
        {;}//等待数据传输完成
    return Response;
    
}

uint8_t DHT22_Read(void)
{
    uint8_t data,i;
    for(i=0;i<8;i++)
    {
        while (!(HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN)))  
            {;}
        delay_us(40);
        if(HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN)==GPIO_PIN_RESET)
            data&=~(1<<(7-i)); //置0
        else
            data|=(1<<(7-i));//置1
        while((HAL_GPIO_ReadPin(DTH22_PORT,DTH22_PIN)))
            {;}
    }
    return data;
}

void Read_DHT22(float *temperature, float *humidity) {
	uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
	uint16_t sum;
	int16_t Temp;
	uint8_t Presence = 0;

	DHT22_Start();
	Presence = DHT22_Check_Response();
	Rh_byte1 = DHT22_Read();
	Rh_byte2 = DHT22_Read();
	Temp_byte1 = DHT22_Read();
	Temp_byte2 = DHT22_Read();
	sum = DHT22_Read();

	if (Presence) {
	*humidity = (Rh_byte1 << 8 | Rh_byte2) / 10.0;
	Temp = (Temp_byte1 << 8 | Temp_byte2);
	if (Temp > 0x8000) {
	Temp = -((Temp & 0x7FFF));
	}
	*temperature = Temp / 10.0;
	}
}

//char* format_sensor_data(uint8_t data_int, uint8_t data_frac) {
//	// 分配足够的内存来存储格式化后的字符串
//	char* result = (char*)malloc(10 * sizeof(char));
//	if (result != NULL) {
//	// 使用 sprintf 函数格式化数据
//	sprintf(result, "%d.%d", data_int, data_frac);
//	}
//	return result;
//}

