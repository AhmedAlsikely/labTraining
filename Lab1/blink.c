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

//---------------------------------------------- Variables -----------------------------------------

//-------------------------------------- Function Decelerations ------------------------------------
void DelayMS(uint32_t delayValueMs);


void main(void){
    SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_2_5 );

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
    while(1){
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0b1000);
        DelayMS(500);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
        DelayMS(500);
    }
}


void DelayMS(uint32_t delayValueMs){
    SysCtlDelay(((float)80000000.0 * (float)delayValueMs)/6000.0);
}
