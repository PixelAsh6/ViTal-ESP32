/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 ******************************************************************************/

#include "BSW/HAL/Temp_Sensor/temp_sensor.h"

#include "BSW/MCAL/GPIO/gpio.h"

#include "BSW/HAL/Com/com.h"

#define DHT11 7

extern COM_GET_struct g_GET_DataStructure;

static const char *TAG = "HAL TEMP SENSOR";

void DHT11_vRequest()
{
    GPIO_vSetDirection(DHT11,DIR_OUTPUT);
    GPIO_vSetLevel(DHT11,1);
    GPIO_vSetLevel(DHT11,0);
    ets_delay_us(20000);
    GPIO_vSetLevel(DHT11,1);
    GPIO_vSetDirection(DHT11,DIR_INPUT);
}

uint8_t DHT11_vResponse()
{  
    int pullup=0;

    while(GPIO_iGetLevel(DHT11)==0)
    {
        pullup++;
        ets_delay_us(1);
        if(pullup>40)
            return -1;
        ets_delay_us(1);
    }
    int time_counter=0;
    
    while(GPIO_iGetLevel(DHT11)==0)
    {
        time_counter++;
        ets_delay_us(1);
        if(time_counter>54)
            return -1;
    }

    time_counter=0;
    
    while(GPIO_iGetLevel(DHT11)==1)
    {
        time_counter++;
        ets_delay_us(1);
        if(time_counter>80)
            return -1;
    }

    return 0;
}

uint8_t DHT11_u8Receive()
{
    uint8_t u8Index = 0;
    uint8_t u8Data=0;
    for(u8Index=0; u8Index<8; u8Index++)
    {
        int counter1=0;

        while(GPIO_iGetLevel(DHT11)==0)
        {   
            if(counter1>54)
                return -1;
            counter1++;
            ets_delay_us(1);
            return 0;
        }
        int counter2=0;
        while(GPIO_iGetLevel(DHT11)==1)
        {   
            if(counter2>70)
                return -1;
            counter2++;
            ets_delay_us(1);
            return 0;
        }
        if(counter2>24)
            u8Data=(u8Data<<1)+1;
        else
            u8Data=u8Data<<1;
    }
    return u8Data;
}