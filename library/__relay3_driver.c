/*
    __relay3_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__relay3_driver.h"
#include "__relay3_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* relays */
const uint16_t _RELAY3_RELAY_1     = 0x01;
const uint16_t _RELAY3_RELAY_2     = 0x02;
const uint16_t _RELAY3_BOTH_RELAYS = 0x03;

/* units */
const uint16_t _RELAY3_SECONDS     = 0x00;
const uint16_t _RELAY3_MILISECONDS = 0x01;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __RELAY3_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __RELAY3_DRV_SPI__

void relay3_spiDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RELAY3_DRV_I2C__

void relay3_i2cDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __RELAY3_DRV_UART__

void relay3_uartDriverInit(T_RELAY3_P gpioObj, T_RELAY3_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

// GPIO Only Drivers - remove in other cases
void relay3_gpioDriverInit(T_RELAY3_P gpioObj)
{
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
}

/* ----------------------------------------------------------- IMPLEMENTATION */

void relay3_relayOn( uint8_t relay_ )
{
    if (relay_ == 1)
    {
        hal_gpio_rstSet(1);
    }
    else if (relay_ == 2)
    {
        hal_gpio_csSet(1);
    }
	else if (relay_ == 3)
    {
        hal_gpio_csSet(1);
		hal_gpio_rstSet(1);
    }
}

void relay3_relayOff( uint8_t relay_ )
{
    if (relay_ == 1)
    {
        hal_gpio_rstSet(0);
    }
    else if (relay_ == 2)
    {
        hal_gpio_csSet(0);
    }
	else if (relay_ == 3)
    {
        hal_gpio_csSet(0);
		hal_gpio_rstSet(0);
    }
}

void relay3_onDelay( uint8_t relay_, uint8_t units_, uint16_t time_ )
{
    uint16_t i;
    
    if (units_ == 0)
    {
        relay3_relayOff(relay_);
        
        for (i = 0; i < time_; i ++)
        {
            Delay_1sec( );
        }
        
        relay3_relayOn(relay_);
    }
    else if (units_ == 1)
    {
        relay3_relayOff(relay_);
        
        for (i = 0; i < time_; i ++)
        {
            Delay_1ms( );
        }
        
        relay3_relayOn(relay_);
    }
}

void relay3_offDelay( uint8_t relay_, uint8_t units_, uint16_t time_ )
{
    uint16_t i;
    
    if (units_ == 0)
    {
        relay3_relayOn(relay_);

        for (i = 0; i < time_; i ++)
        {
            Delay_1sec( );
        }

        relay3_relayOff(relay_);
    }
    else if (units_ == 1)
    {
        relay3_relayOn(relay_);

        for (i = 0; i < time_; i ++)
        {
            Delay_1ms( );
        }

        relay3_relayOff(relay_);
    }
}

/* -------------------------------------------------------------------------- */
/*
  __relay3_driver.c

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