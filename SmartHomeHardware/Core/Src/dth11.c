#include "dth11.h"

//main.c中的全局变量
//float temperature, humidity
//调用Read_DHT11（）获取数据

void Set_Pin_Output_DTH11(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
    GPIO_InitTypeDef GPIO_IninStruct ={0};
    GPIO_IninStruct.Pin=GPIO_Pin;
    GPIO_IninStruct.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_IninStruct.Speed=GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOx,&GPIO_IninStruct);
}

void Set_Pin_Input_DTH11(GPIO_TypeDef *GPIOx,uint16_t GPIO_Pin)
{
     GPIO_InitTypeDef GPIO_IninStruct ={0};
    GPIO_IninStruct.Pin=GPIO_Pin;
    GPIO_IninStruct.Mode=GPIO_MODE_INPUT;
    GPIO_IninStruct.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(GPIOx,&GPIO_IninStruct);
}

void DHT11_Start(void)
{
    Set_Pin_Output_DTH11(DTH11_PORT,DTH11_PIN);
    HAL_GPIO_WritePin(DTH11_PORT,DTH11_PIN,GPIO_PIN_RESET);
    delay_us(18000);
    HAL_GPIO_WritePin(DTH11_PORT,DTH11_PIN,GPIO_PIN_SET);
    delay_us(20);
    Set_Pin_Input_DTH11(DTH11_PORT,DTH11_PIN);
}

uint8_t DHT11_Check_Response(void)
{
    int8_t Response=0;
    delay_us(40);
    if(HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN)==GPIO_PIN_RESET)
    {
        delay_us(80);
        if((HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN)))
            Response=1;
        else 
            Response=-1;
    }
    while ((HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN))) 
        {;}//等待数据传输完成
    return Response;
    
}

uint8_t DHT11_Read(void)
{
    uint8_t data,i;
    for(i=0;i<8;i++)
    {
        while (!(HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN)))  
            {;}
        delay_us(40);
        if(HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN)==GPIO_PIN_RESET)
            data&=~(1<<(7-i)); //置0
        else
            data|=(1<<(7-i));//置1
        while((HAL_GPIO_ReadPin(DTH11_PORT,DTH11_PIN)))
            {;}
    }
    return data;
}

void Read_DHT11(float *temperature, float *humidity) {
    uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
    uint16_t sum;
    int16_t Temp;
    uint8_t Presence = 0;

    DHT11_Start();
    Presence = DHT11_Check_Response();
    Rh_byte1 = DHT11_Read();
    Rh_byte2 = DHT11_Read();
    Temp_byte1 = DHT11_Read();
    Temp_byte2 = DHT11_Read();
    sum = DHT11_Read();
    if (Presence) {
        *humidity = Rh_byte1 + Rh_byte2 / 10.0;
        Temp = (Temp_byte1 << 8) | Temp_byte2;
        if (Temp & 0x8000) {
         Temp = -(Temp & 0x7FFF);
        }
        *temperature = Temp / 10.0;
    }
}

