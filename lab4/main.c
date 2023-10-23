

/**
 * main.c
 *
 *   Created on: Oct 23, 2023
 *   Author: Ahmed Alsikely
 */
//----------------------------------------------- Include Files ------------------------------------
#include "stdint.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <MCAL_Layer/PIN/Pin.h>
#include <MCAL_Layer/UART/uart.h>

//---------------------------------------------- Macros --------------------------------------------

//---------------------------------------------- Variables -----------------------------------------
pin_t red_led ={
                .port=PORT_F,
                .pinNumber = PIN_1,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};
pin_t blue_led ={
                .port=PORT_F,
                .pinNumber = PIN_2,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};
pin_t green_led ={
                .port=PORT_F,
                .pinNumber = PIN_3,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};
uart_t uart_ ={
               .uart_Select = UART_0,
               .baud_rate = UART_BAUD_RATE_115200,
               .data_length = LENGTH_8_BIT,
               .parity_type = PARITY_NONE,
               .stopBit_length = STOP_BIT_ONE
};
//-------------------------------------- Function Decelerations ------------------------------------

//-------------------------------------- program ---------------------------------------------------
int main(void)
{
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );
        Pin_Init(&red_led);
        Pin_Init(&blue_led);
        Pin_Init(&green_led);
        UART_Init(&uart_);
        Std_Return retVal = R_NOK;
        char receivedChar;

        while(1){
            receivedChar = UART_ReceiveChar(&uart_ , &retVal);
            if(R_OK == retVal){
                switch (receivedChar) {
                    case 'r':
                        Pin_Write(&red_led, HIGH);
                        break;
                    case 'g':
                        Pin_Write(&green_led, HIGH);
                        break;
                    case 'b':
                        Pin_Write(&blue_led, HIGH);
                       break;
                    case 'o':
                        Pin_Write(&red_led, LOW);
                        Pin_Write(&green_led, LOW);
                        Pin_Write(&blue_led, LOW);
                       break;
                    default:
                       break;
                }
            }
        }
	return 0;
}
