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

#include "BSW/HAL/Shift_Register/shift_register.h"

#include "BSW/MCAL/GPIO/gpio.h"


static const char *TAG = "HAL SHIFT REGISTER";

/*******************************************************************************
 *  Function name    : SHIFTREG_vOutput8Bits
 *
 *  Description      : Output an 8 bit data value
 *
 *  List of arguments: u8Data -> Data to be output MSb to LSb
 *
 *  Return value     : -
 *
 ******************************************************************************/
#define SN74HC595_DS_PIN 2
#define SN74HC595_SH_CP_PIN 3
#define SN74HC595_ST_CP_PIN 4

void SHIFTREG_vOutput8Bits(uint8_t u8Data)
{
 GPIO_vSetLevel(SN74HC595_DS_PIN,0);
 GPIO_vSetLevel(SN74HC595_SH_CP_PIN,0);
 GPIO_vSetLevel(SN74HC595_ST_CP_PIN,0);
 for(int i=7;i>=0;i--)
 {
     GPIO_vSetLevel( SN74HC595_DS_PIN,((u8Data)&(1<<i))>>i);

     //extragere bit cu shiftare  
     //GPIO_vSetLevel(SN74HC595_DS_PIN,u8Data>>i);

     //clock pe SHCP
     GPIO_vSetLevel(SN74HC595_SH_CP_PIN,1);
     GPIO_vSetLevel(SN74HC595_SH_CP_PIN,0);

     //GPIO_vSetLevel(SN74HC595_DS_PIN,0);

 }
 //clock STCP 
    GPIO_vSetLevel(SN74HC595_ST_CP_PIN,1);
    GPIO_vSetLevel(SN74HC595_ST_CP_PIN,0);

}
