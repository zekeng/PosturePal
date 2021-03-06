/******************************************************************************
 * Filename:       SENSOR_SERVICE.h
 *
 * Description:    This file contains the SENSOR_SERVICE service definitions and
 *                 prototypes.
 *
 *                 Generated by:
 *                 BDS version: 1.1.3139.0
 *                 Plugin:      Texas Instruments BLE SDK GATT Server plugin 1.0.9
 *                 Time:        Fri Feb 16 2018 11:16:33 GMT+02:00
 *

 * Copyright (c) 2015-2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

#ifndef _SENSOR_SERVICE_H_
#define _SENSOR_SERVICE_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include <bcomdef.h>

/*********************************************************************
 * CONSTANTS
 */
// Service UUID
#define SENSOR_SERVICE_SERV_UUID 0xFFF0

// ACC ENABLE Characteristic defines
#define SS_ACC_ENABLE_ID                 0
#define SS_ACC_ENABLE_UUID               0xFFF1
#define SS_ACC_ENABLE_LEN                1
#define SS_ACC_ENABLE_LEN_MIN            1

// ACC ODR Characteristic defines
#define SS_ACC_ODR_ID                 1
#define SS_ACC_ODR_UUID               0xFFF2
#define SS_ACC_ODR_LEN                4
#define SS_ACC_ODR_LEN_MIN            4

// ACC FS Characteristic defines
#define SS_ACC_FS_ID                 2
#define SS_ACC_FS_UUID               0xFFF3
#define SS_ACC_FS_LEN                2
#define SS_ACC_FS_LEN_MIN            2

// GYRO FS Characteristic defines
#define SS_GYRO_FS_ID                 3
#define SS_GYRO_FS_UUID               0xFFF6
#define SS_GYRO_FS_LEN                2
#define SS_GYRO_FS_LEN_MIN            2

// GYRO ODR Characteristic defines
#define SS_GYRO_ODR_ID                 4
#define SS_GYRO_ODR_UUID               0xFFF5
#define SS_GYRO_ODR_LEN                4
#define SS_GYRO_ODR_LEN_MIN            4

// GYRO ENABLE Characteristic defines
#define SS_GYRO_ENABLE_ID                 5
#define SS_GYRO_ENABLE_UUID               0xFFF4
#define SS_GYRO_ENABLE_LEN                1
#define SS_GYRO_ENABLE_LEN_MIN            1

// DATA Characteristic defines
#define SS_DATA_ID                 6
#define SS_DATA_UUID               0xFFF7
#define SS_DATA_LEN                20
#define SS_DATA_LEN_MIN            1

/*********************************************************************
 * TYPEDEFS
 */

// Fields in characteristic "ACC ENABLE"
//   Field "FLAG" format: boolean, bits: 8

// Fields in characteristic "ACC ODR"
//   Field "ODR" format: uint32, bits: 32

// Fields in characteristic "ACC FS"
//   Field "FS" format: uint16, bits: 16

// Fields in characteristic "GYRO FS"
//   Field "FS" format: uint16, bits: 16

// Fields in characteristic "GYRO ODR"
//   Field "ODR" format: uint32, bits: 32

// Fields in characteristic "GYRO ENABLE"
//   Field "FLAG" format: boolean, bits: 8

// Fields in characteristic "DATA"
//   Field "DATA" format: uint8[], bits: -1

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * Profile Callbacks
 */

// Callback when a characteristic value has changed
typedef void (*SensorServiceChange_t)( uint16_t connHandle, uint16_t svcUuid, uint8_t paramID, uint8_t *pValue, uint16_t len );

typedef struct
{
  SensorServiceChange_t        pfnChangeCb;     // Called when characteristic value changes
  SensorServiceChange_t        pfnCfgChangeCb;  // Called when characteristic CCCD changes
} SensorServiceCBs_t;



/*********************************************************************
 * API FUNCTIONS
 */


/*
 * SensorService_AddService- Initializes the SensorService service by registering
 *          GATT attributes with the GATT server.
 *
 *    rspTaskId - The ICall Task Id that should receive responses for Indications.
 */
extern bStatus_t SensorService_AddService( uint8_t rspTaskId );

/*
 * SensorService_RegisterAppCBs - Registers the application callback function.
 *                    Only call this function once.
 *
 *    appCallbacks - pointer to application callbacks.
 */
extern bStatus_t SensorService_RegisterAppCBs( SensorServiceCBs_t *appCallbacks );

/*
 * SensorService_SetParameter - Set a SensorService parameter.
 *
 *    param - Profile parameter ID
 *    len   - length of data to write
 *    value - pointer to data to write.  This is dependent on
 *            the parameter ID and may be cast to the appropriate
 *            data type (example: data type of uint16_t will be cast to
 *            uint16_t pointer).
 */
extern bStatus_t SensorService_SetParameter( uint8_t param, uint16_t len, void *value );

/*
 * SensorService_GetParameter - Get a SensorService parameter.
 *
 *    param - Profile parameter ID
 *    len   - pointer to a variable that contains the maximum length that can be written to *value.
              After the call, this value will contain the actual returned length.
 *    value - pointer to data to write.  This is dependent on
 *            the parameter ID and may be cast to the appropriate
 *            data type (example: data type of uint16_t will be cast to
 *            uint16_t pointer).
 */
extern bStatus_t SensorService_GetParameter( uint8_t param, uint16_t *len, void *value );

/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _SENSOR_SERVICE_H_ */

