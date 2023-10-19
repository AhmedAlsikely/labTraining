/*
 * appication.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Alsikley
 */
/*
 * blink.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Alsikely
 */

//----------------------------------------------- Include Files ------------------------------------
#include "stdint.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <Pin.h>
#include <gpio_interrupt.h>

//---------------------------------------------- Macros --------------------------------------------
#define DELAY_TIME 500

//---------------------------------------------- Variables -----------------------------------------
void Portx_INT_Handler(void);

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

pin_t SW1 ={
                .port=PORT_F,
                .pinNumber = PIN_4,
                .direction = PIN_IN,
                .current = CURRENT_2MA,
                .pinType = PIN_PU,
                .PORT_InterruptHandler = Portx_INT_Handler,
                .INT_Type = GPIO_RISING_EDGE_,
                .INT_priority = 0x00,
};
pin_t SW2 ={
                .port=PORT_F,
                .pinNumber = PIN_0,
                .direction = PIN_IN,
                .current = CURRENT_2MA,
                .pinType = PIN_PU,
                .PORT_InterruptHandler = Portx_INT_Handler,
                .INT_Type = GPIO_RISING_EDGE_,
                .INT_priority = 0x00,
};
//-------------------------------------- Function Decelerations ------------------------------------
void DelayMS(uint32_t delayValueMs);



void main(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );
    Pin_Init(&red_led);
    Pin_Init(&blue_led);
    Pin_Init(&green_led);
    Pin_Init(&SW1);
    Pin_Init(&SW2);
    Pin_INT_Config(&SW1);
    Pin_INT_Config(&SW2);
    Std_Return retVal = R_NOK;
    while(1){
     Pin_Toggle(&green_led);
     Pin_Write(&red_led, LOW, &retVal);
     Pin_Write(&blue_led, LOW, &retVal);
     DelayMS(500);
    }


}


void DelayMS(uint32_t delayValueMs){
    SysCtlDelay(((float)80000000.0 * (float)delayValueMs)/6000.0);
}

void Portx_INT_Handler(void){
    uint8_t int_status = 0;
    Std_Return retVal = R_OK;
    int_status = GPIOIntStatus(SW1.port, true);
    if(int_status == SW1.pinNumber){
        GPIOIntClear(SW1.port, SW1.pinNumber);
        Pin_Write(&green_led, LOW, &retVal);
        retVal = Pin_Toggle(&red_led);
    }
    else if(int_status == SW2.pinNumber){
        GPIOIntClear(SW2.port, SW2.pinNumber);
        Pin_Write(&green_led, LOW, &retVal);
        retVal = Pin_Toggle(&blue_led);
    }
}


