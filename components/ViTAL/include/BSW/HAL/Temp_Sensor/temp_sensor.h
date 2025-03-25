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

#ifndef COMPONENTS_VITAL_BSW_HAL_TEMP_SENSOR_H
#define COMPONENTS_VITAL_BSW_HAL_TEMP_SENSOR_H

#include "global.h"

#endif

void DHT11_vRequest (void);
uint8_t DHT11_vResponse (void);
uint8_t DHT11_u8Receive (void);
void DHT11_dht11Read (void);
void DHT11_vTaskTempAndHumCalculate (void);