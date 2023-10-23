/*
 * Pin.h
 *
 *  Created on: Oct 19, 2023
 *      Author: Alsikely
 */

#ifndef PIN_H_
#define PIN_H_

//----------------------------------------------- Include Files ------------------------------------
#include "stdint.h"
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <MCAL_Layer/Interrupt/gpio_interrupt_cfg.h>
//---------------------------------------------- Macros --------------------------------------------


#define PORT_A GPIO_PORTA_AHB_BASE
#define PORT_B GPIO_PORTB_AHB_BASE
#define PORT_C GPIO_PORTC_AHB_BASE
#define PORT_D GPIO_PORTD_AHB_BASE
#define PORT_E GPIO_PORTE_AHB_BASE
#define PORT_F GPIO_PORTF_AHB_BASE


#define PIN_0 GPIO_PIN_0
#define PIN_1 GPIO_PIN_1
#define PIN_2 GPIO_PIN_2
#define PIN_3 GPIO_PIN_3
#define PIN_4 GPIO_PIN_4
#define PIN_5 GPIO_PIN_5
#define PIN_6 GPIO_PIN_6
#define PIN_7 GPIO_PIN_7
#define PIN_8 GPIO_PIN_8

// pad type
#define PIN_STD GPIO_PIN_TYPE_STD
#define PIN_PU  GPIO_PIN_TYPE_STD_WPU
#define PIN_PD  GPIO_PIN_TYPE_STD_WPD

// Direction

#define PIN_OUT GPIO_DIR_MODE_OUT
#define PIN_IN  GPIO_DIR_MODE_IN

// Current

#define CURRENT_2MA GPIO_STRENGTH_2MA
#define CURRENT_4MA GPIO_STRENGTH_4MA
#define CURRENT_8MA GPIO_STRENGTH_8MA

// pin status

#define LOW  0
#define HIGH 1

//------------------------------- User define datatypes ------------------------

typedef struct{
    uint32_t port;
    uint32_t pinNumber;
    uint32_t direction;
    uint32_t current;
    uint32_t pinType;
#if INTERRUPT_FEATURE_ENABLE == INTERRUPT_EXTERNAL_INTx_FEATURE_ENABLE
    void(* PORT_InterruptHandler)(void);
    uint32_t INT_Type;
    uint8_t INT_priority;
#endif
}pin_t;

typedef enum{
    R_NOK =0,
    R_OK
}Std_Return;

//----------------------- Functions Decelarations ------------------------------

extern Std_Return Pin_Init(pin_t *pin);

extern Std_Return Pin_Write(pin_t *pin, uint8_t state);
extern int8_t Pin_read_value(pin_t *pin,uint8_t *returnType);
extern Std_Return Pin_Toggle(pin_t *pin);



#endif /* PIN_H_ */
