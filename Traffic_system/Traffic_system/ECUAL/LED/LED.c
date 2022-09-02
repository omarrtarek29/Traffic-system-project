/*
 * LED.c
 *
 * Created: 8/31/2022 5:29:21 PM
 *  Author: omart
 */ 

#include "LED.h"


/*****************************************************************************
* Function Name: LED_init
* Purpose      : Initialize led
* Parameters   : Register name, pin number
* Return value : Void
*****************************************************************************/
void LED_init(REG_name_t reg, PIN_num_t pin){
	DIO_init_pin(reg, pin, OUTPUT);
}


/*****************************************************************************
* Function Name: LED_on
* Purpose      : Turning led on
* Parameters   : Register name, pin number
* Return value : Void
*****************************************************************************/
void LED_on(REG_name_t reg, PIN_num_t pin){
	DIO_write(reg, pin, HIGH);
}


/*****************************************************************************
* Function Name: LED_off
* Purpose      : Turning led off
* Parameters   : Register name, pin number
* Return value : Void
*****************************************************************************/
void LED_off(REG_name_t reg, PIN_num_t pin){
	DIO_write(reg, pin, LOW);
}


/*****************************************************************************
* Function Name: LED_toggle
* Purpose      : Toggle led (Turning it on if it was off or turning it off if it was on)
* Parameters   : Register name, pin number
* Return value : Void
*****************************************************************************/
void LED_toggle(REG_name_t reg, PIN_num_t pin){
	DIO_toggle(reg, pin);
}