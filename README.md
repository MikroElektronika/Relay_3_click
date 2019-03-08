![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Relay_3 Click

- **CIC Prefix**  : RELAY3
- **Author**      : Aleksandar Paunovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the Relay_3 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2662/relay-3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

 Library contains functoins for turning on/off relays 1 and 2.
 Library contains functions for turning on/off relays 1 and 2 after a defined period of time.

Key functions :

- ``` void relay3_relayOn( uint8_t relay_ )```   - Turns selected relay on
- ``` void relay3_relayOff( uint8_t relay_ ) ``` - Turns selected relay off
- ``` void relay3_onDelay( uint8_t relay_, uint8_t units_, uint16_t time_ ) ```  - Turns selected relay on after a defined period of time in selected units of time
- ``` void relay3_offDelay( uint8_t relay_, uint8_t units_, uint16_t time_ ) ``` - Turns selected relay off after a defined period of time in selected units of time

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes LOG functionality, initializes RST and CS pins as OUTPUTs
- Application Initialization - Initializes GPIO driver
- Application Task - Activates relays 1 and/or 2 based on user input


```.c

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

```

**Additional Functions**

- void relay3_case1( ) - Turns relay 1 on/off
- void relay3_case2( ) - Turns relay 2 on/off
- void relay3_case3( ) - Turns relays  on/off

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2662/relay-3-click) page.

Other mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
