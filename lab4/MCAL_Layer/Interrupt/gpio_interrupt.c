/*
 * gpio_interrupt.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Alsikely
 */
#include <MCAL_Layer/Interrupt/gpio_interrupt.h>

Std_Return Pin_INT_Config(pin_t *pin){
    Std_Return ret_status = R_NOK;
    uint32_t port_Select =0;
        if(NULL == pin){
                ret_status = R_NOK;
        }
        else
        {
            switch(pin->port){
                case PORT_A:
                       port_Select = INT_GPIOA;
                       break;
                   case PORT_B:
                       port_Select = INT_GPIOB;
                       break;
                   case PORT_C:
                       port_Select = INT_GPIOC;
                       break;
                   case PORT_D:
                       port_Select = INT_GPIOD;
                       break;
                   case PORT_E:
                        port_Select = INT_GPIOE;
                        break;
                   case PORT_F:
                        port_Select = INT_GPIOF;
                        break;
                   default :
                        port_Select = INT_GPIOF;
                        break;
                    }


            IntMasterDisable();
            GPIOIntClear(pin->port, pin->pinNumber);
            IntRegister(port_Select, pin->PORT_InterruptHandler);
            GPIOIntTypeSet(pin->port, pin->pinNumber, pin->INT_Type);
            IntPrioritySet(port_Select, pin->INT_priority);
            GPIOIntEnable(pin->port, pin->pinNumber);
            IntEnable(port_Select);
            IntMasterEnable();
             ret_status = R_OK;
        }
        return ret_status;
}

