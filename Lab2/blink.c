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

//---------------------------------------------- Macros --------------------------------------------
#define DELAY_TIME 500

//---------------------------------------------- Variables -----------------------------------------
pin_t red_led ={
                .port=PORT_F,
                .pinNumber = PIN_1,
                .direction = PIN_OUT,
                .current = CURRENT_2MA,
                .pinType = PIN_STD,
};

//-------------------------------------- Function Decelerations ------------------------------------
void DelayMS(uint32_t delayValueMs);


void main(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );
    Pin_Init(&red_led);
    Std_Return retVal = R_NOK;
    while(1){
     Pin_Write(&red_led, HIGH, &retVal);
     DelayMS(500);
     Pin_Write(&red_led, LOW, &retVal);
     DelayMS(500);
    }


}


void DelayMS(uint32_t delayValueMs){
    SysCtlDelay(((float)80000000.0 * (float)delayValueMs)/6000.0);
}
