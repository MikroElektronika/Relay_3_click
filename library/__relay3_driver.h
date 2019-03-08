/*
    __relay3_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __relay3_driver.h
@brief    Relay_3 Driver
@mainpage Relay_3 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RELAY3
@brief      Relay_3 Click Driver
@{

| Global Library Prefix | **RELAY3** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Aleksandar Paunovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RELAY3_H_
#define _RELAY3_H_

/** 
 * @macro T_RELAY3_P
 * @brief Driver Abstract type 
 */
#define T_RELAY3_P    const uint8_t*

/** @defgroup RELAY3_COMPILE Compilation Config */              /** @{ */

// #define   __RELAY3_DRV_SPI__                            /**<     @macro __RELAY3_DRV_SPI__  @brief SPI driver selector */
// #define   __RELAY3_DRV_I2C__                            /**<     @macro __RELAY3_DRV_I2C__  @brief I2C driver selector */
// #define   __RELAY3_DRV_UART__                           /**<     @macro __RELAY3_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RELAY3_VAR Variables */                           /** @{ */

/* relays */
extern const uint16_t _RELAY3_RELAY_1;
extern const uint16_t _RELAY3_RELAY_2;
extern const uint16_t _RELAY3_BOTH_RELAYS;

/* units */
extern const uint16_t _RELAY3_SECONDS;
extern const uint16_t _RELAY3_MILISECONDS;

                                                                       /** @} */
/** @defgroup RELAY3_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RELAY3_INIT Driver Initialization */              /** @{ */

#ifdef   __RELAY3_DRV_SPI__
void relay3_spiDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P spiObj);
#endif
#ifdef   __RELAY3_DRV_I2C__
void relay3_i2cDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P i2cObj, uint8_t slave);
#endif
#ifdef   __RELAY3_DRV_UART__
void relay3_uartDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void relay3_gpioDriverInit(T_RELAY3_P gpioObj);
                                                                       /** @} */
/** @defgroup RELAY3_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Turning relay on
 *
 * @param[in] uint8_t relay_ - relay to turn on
 *
 * This function turns selected relay on
 */
void relay3_relayOn( uint8_t relay_ );

/**
 * @brief Turning relay off
 *
 * @param[in] uint8_t relay_ - relay to turn on
 *
 * This function turns selected relay off
 */
void relay3_relayOff( uint8_t relay_ );

/**
 * @brief Turning relay on with delay
 *
 * @param[in] uint8_t relay_ - relay to turn on after a period of time
 * @param[in] uint8_t units_ - units can be seconds or miliseconds
 * @param[in] uint8_t time_  - time
 *
 * This function turns selected relay on after a period of time
 */
void relay3_onDelay( uint8_t relay_, uint8_t units_, uint16_t time_ );

/**
 * @brief Turning relay off with delay
 *
 * @param[in] uint8_t relay_ - relay to turn off after a period of time
 * @param[in] uint8_t units_ - units can be seconds or miliseconds
 * @param[in] uint8_t time_  - time
 *
 * This function turns selected relay off after a period of time
 */
void relay3_offDelay( uint8_t relay_, uint8_t units_, uint16_t time_ );



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Relay_3_STM.c
    @example Click_Relay_3_TIVA.c
    @example Click_Relay_3_CEC.c
    @example Click_Relay_3_KINETIS.c
    @example Click_Relay_3_MSP.c
    @example Click_Relay_3_PIC.c
    @example Click_Relay_3_PIC32.c
    @example Click_Relay_3_DSPIC.c
    @example Click_Relay_3_AVR.c
    @example Click_Relay_3_FT90x.c
    @example Click_Relay_3_STM.mbas
    @example Click_Relay_3_TIVA.mbas
    @example Click_Relay_3_CEC.mbas
    @example Click_Relay_3_KINETIS.mbas
    @example Click_Relay_3_MSP.mbas
    @example Click_Relay_3_PIC.mbas
    @example Click_Relay_3_PIC32.mbas
    @example Click_Relay_3_DSPIC.mbas
    @example Click_Relay_3_AVR.mbas
    @example Click_Relay_3_FT90x.mbas
    @example Click_Relay_3_STM.mpas
    @example Click_Relay_3_TIVA.mpas
    @example Click_Relay_3_CEC.mpas
    @example Click_Relay_3_KINETIS.mpas
    @example Click_Relay_3_MSP.mpas
    @example Click_Relay_3_PIC.mpas
    @example Click_Relay_3_PIC32.mpas
    @example Click_Relay_3_DSPIC.mpas
    @example Click_Relay_3_AVR.mpas
    @example Click_Relay_3_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __relay3_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */