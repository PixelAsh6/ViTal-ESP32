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

#include "RTE/rte.h"

#include "BSW/HAL/Buzzer/buzzer.h"
#include "BSW/HAL/Com/com.h"
#include "BSW/HAL/DC_Motor/dc_motor.h"
#include "BSW/HAL/Proximity_Sensor/proximity_sensor.h"
#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "BSW/HAL/Shift_Register/shift_register.h"


static const char *TAG = "RTE";

extern COM_GET_struct g_GET_DataStructure;
extern COM_POST_struct g_POST_DataStructure;
unsigned char u8Color;

void RTE_vSetAmbientalLightsState(bool bState)
{
    if(bState==ON)
    {
        u8Color=RED;

        if(u8Color==RED)
        {
            SHIFTREG_vOutput8Bits(0b00010000);
        }
        ets_delay_us(2000000);

        u8Color=BLUE;
        if(u8Color==BLUE)
        {
            SHIFTREG_vOutput8Bits(0b00001000);
        }
        ets_delay_us(2000000);

        u8Color=GREEN;
        if(u8Color==GREEN)
        {
            SHIFTREG_vOutput8Bits(0b00100000);
        }
        ets_delay_us(2000000);

        u8Color=RED_BLUE;
        if(u8Color==RED_BLUE)
        {
             SHIFTREG_vOutput8Bits(0b00011000);
        }
        ets_delay_us(2000000);

        u8Color=RED_GREEN;
        if(u8Color==RED_GREEN)
        {
            SHIFTREG_vOutput8Bits(0b00110000);
        }
        ets_delay_us(2000000);

        u8Color=GREEN_BLUE;
        if(u8Color==GREEN_BLUE)
        {
                SHIFTREG_vOutput8Bits(0b00101000);
        }
        ets_delay_us(2000000);

        u8Color=ALL_COLORS;
        if(u8Color==ALL_COLORS)
        {
                SHIFTREG_vOutput8Bits(0b00111000);
        }
        ets_delay_us(2000000);
    }

}
