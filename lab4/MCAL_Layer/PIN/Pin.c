/*
 * Pin.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Alsikely
 */

#include <MCAL_Layer/PIN/Pin.h>

Std_Return Pin_Init(pin_t *pin){
    Std_Return ret_status = R_NOK;
    uint32_t port_Select =0;
    if(NULL == pin){
        ret_status = R_NOK;
    }
    else
    {
        switch(pin->port){
            case PORT_A:
                port_Select = SYSCTL_PERIPH_GPIOA;
                break;
            case PORT_B:
                port_Select = SYSCTL_PERIPH_GPIOB;
                break;
            case PORT_C:
                port_Select = SYSCTL_PERIPH_GPIOC;
                break;
            case PORT_D:
                port_Select = SYSCTL_PERIPH_GPIOD;
                break;
            case PORT_E:
                port_Select = SYSCTL_PERIPH_GPIOE;
                break;
            case PORT_F:
                port_Select = SYSCTL_PERIPH_GPIOF;
                break;
            default :
                port_Select = SYSCTL_PERIPH_GPIOF;
                break;
        }
        SysCtlGPIOAHBEnable(port_Select);
        SysCtlPeripheralEnable(port_Select);
        while(!SysCtlPeripheralReady(port_Select));
        GPIOPadConfigSet(pin->port, pin->pinNumber, pin->current, pin->pinType);
        GPIODirModeSet(pin->port, pin->pinNumber, pin->direction);
        GPIOPinWrite(pin->port, pin->pinNumber, 0x00);

        ret_status = R_OK;
    }
    return ret_status;
}

Std_Return Pin_Write(pin_t *pin, uint8_t state){
    Std_Return ret_status = R_NOK;
    if(NULL == pin ){
        ret_status = R_NOK;
    }
    else
    {
        switch(state){
        case HIGH:
            GPIOPinWrite(pin->port, pin->pinNumber, pin->pinNumber);
            break;
        case LOW:
            GPIOPinWrite(pin->port, pin->pinNumber, 0x00);
            break;
        default:
            GPIOPinWrite(pin->port, pin->pinNumber, 0x00);
            break;
        }

        ret_status = R_OK;
    }
    return ret_status;
}


int8_t Pin_read_value(pin_t *pin,uint8_t *returnType){
    Std_Return ret_status = R_NOK;
    uint32_t pin_value = 0;
    if(NULL == pin || NULL == returnType){
            ret_status = R_NOK;
    }
    else
    {
         pin_value = GPIOPinRead(pin->port, pin->pinNumber);

         ret_status = R_OK;
    }
    *returnType = ret_status;
    return pin_value;
}


Std_Return Pin_Toggle(pin_t *pin){
    Std_Return ret_status = R_NOK;
        uint32_t pin_value =0;
        if(NULL == pin){
            ret_status = R_NOK;
        }
        else
        {
            pin_value = GPIOPinRead(pin->port, pin->pinNumber);
            if(pin_value == pin->pinNumber)
            {
                GPIOPinWrite(pin->port, pin->pinNumber, 0x00);

            }
            else
            {
                GPIOPinWrite(pin->port, pin->pinNumber, pin->pinNumber);

            }

            ret_status = R_OK;
        }
        return ret_status;
}
