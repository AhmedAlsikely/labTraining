/*
 * gpio_interrupt.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Alsikely
 */

#ifndef GPIO_INTERRUPT_H_
#define GPIO_INTERRUPT_H_

//----------------------------------------------- Include Files ------------------------------------
#include <MCAL_Layer/PIN/Pin.h>
#include "inc/hw_types.h"
#include "driverlib/interrupt.h"
#include "inc/hw_ints.h"

//---------------------------------------------- Macros --------------------------------------------

// interrupt types
#define GPIO_FALLING_EDGE_    GPIO_FALLING_EDGE         // Interrupt on falling edge
#define GPIO_RISING_EDGE_     GPIO_RISING_EDGE          // Interrupt on rising edge
#define GPIO_BOTH_EDGES_      GPIO_BOTH_EDGES           // Interrupt on both edges
#define GPIO_LOW_LEVEL_       GPIO_LOW_LEVEL            // Interrupt on low level
#define GPIO_HIGH_LEVEL_      GPIO_HIGH_LEVEL           // Interrupt on high level
#define GPIO_DISCRETE_INT_    GPIO_DISCRETE_INT         // Interrupt for individual pins

//------------------------------- User define datatypes ------------------------


//----------------------- Functions Decelarations ------------------------------
Std_Return Pin_INT_Config(pin_t *pin);

#endif /* GPIO_INTERRUPT_H_ */
