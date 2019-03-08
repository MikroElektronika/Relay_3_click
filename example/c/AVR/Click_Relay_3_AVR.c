/*
Example for Relay_3 Click

    Date          : Nov 2018.
    Author        : Aleksandar Paunovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes LOG functionality, initializes RST and CS pins as OUTPUTs
- Application Initialization - Initializes GPIO driver
- Application Task - Activates relays 1 and/or 2 based on user input

Commands :
- '1' - Turns relay 1 on/off
- '2' - Turns relay 2 on/off
- '3' - Turns both relays on/off

Additional Functions :

- void relay3_case1( ) - Turns relay 1 on/off
- void relay3_case2( ) - Turns relay 2 on/off
- void relay3_case3( ) - Turns relays  on/off
*/

#include "Click_Relay_3_types.h"
#include "Click_Relay_3_config.h"


uint8_t dataReady;
uint8_t receivedData;
uint8_t iterator1 = 0;
uint8_t iterator2 = 0;
uint8_t iterator3 = 0;

void relay3_case1( )
{
    if (iterator1 == 0)
    {
        relay3_relayOn(_RELAY3_RELAY_1);

        iterator1 = 1;

        mikrobus_logWrite( "relay 1 on", _LOG_LINE );
    }
    else if (iterator1 == 1)
    {
        relay3_relayOff(_RELAY3_RELAY_1);

        iterator1 = 0;

        mikrobus_logWrite( "relay 1 off", _LOG_LINE );
    }
}

void relay3_case2( )
{
    if (iterator2 == 0)
    {
        relay3_relayOn(_RELAY3_RELAY_2);

        iterator2 = 1;

        mikrobus_logWrite( "relay 2 on", _LOG_LINE );
    }
    else if (iterator2 == 1)
    {
        relay3_relayOff(_RELAY3_RELAY_2);

        iterator2 = 0;

        mikrobus_logWrite( "relay 2 off", _LOG_LINE );
    }
}

void relay3_case3( )
{
    if (iterator3 == 0)
    {
        relay3_relayOn(_RELAY3_BOTH_RELAYS);

        iterator3 = 1;

        mikrobus_logWrite( "relays on", _LOG_LINE );
    }
    else if (iterator3 == 1)
    {
        relay3_relayOff(_RELAY3_BOTH_RELAYS);

        iterator3 = 0;

        mikrobus_logWrite( "relays off", _LOG_LINE );
    }
}

void systemInit( )
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN,  _GPIO_OUTPUT );

    mikrobus_logInit( _LOG_USBUART_A, 9600 );

    Delay_ms(100);
    
    mikrobus_logWrite( "system init done", _LOG_LINE );
}

void applicationInit( )
{
    relay3_gpioDriverInit( (T_RELAY3_P)&_MIKROBUS1_GPIO );
    
    mikrobus_logWrite( "application init done", _LOG_LINE );
}

void applicationTask( )
{
    dataReady = UART_Rdy_Ptr( );

    if (dataReady != 0)
    {
        receivedData = UART_Rd_Ptr( );

        switch (receivedData)
        {
            case '1' :
            {
                relay3_case1( );

                break;
            }
            case '2' :
            {
                relay3_case2( );

                break;
            }
            case '3' :
            {
                relay3_case3( );

                break;
            }
            default :
            {
                mikrobus_logWrite( "wrong command", _LOG_LINE );

                break;
            }
        }
    }
}

void main( )
{
    systemInit( );
    applicationInit( );

    while (1)
    {
        applicationTask( );
    }
}