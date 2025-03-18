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

#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"

#include "BSW/MCAL/GPIO/gpio.h"

#include "BSW/HAL/Com/com.h"

#include "global.h"

#define HC_SR04_TRIGGER_PIN 5
#define HC_SR04_ECHO_PIN 6

extern COM_GET_struct g_GET_DataStructure;

static const char *TAG = "HAL PROXIMITY SENSOR";

uint8_t distance=0;
void PROX_vRequest ()
{
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, 0);
    ets_delay_us(2);
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, 1);
    ets_delay_us(10);
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, 0);
}

int64_t PROX_u16Read ()
{
    PROX_vRequest();
    int64_t echot1=0, echot2=0;
    while(GPIO_iGetLevel(HC_SR04_ECHO_PIN)==0)
    {
    };
    
    echot1=esp_timer_get_time();
    
    while(GPIO_iGetLevel(HC_SR04_ECHO_PIN)==1)
    {

    };
    echot2=esp_timer_get_time();
    //g_GET_DataStructure.u8Distance
    distance=(echot2-echot1)*0.0343/2;
    g_GET_DataStructure.u8Distance=distance;
    //return g_GET_DataStructure.u8Distance;
    //ESP_LOGI(TAG,"%d",distance);
    return distance;
} 
