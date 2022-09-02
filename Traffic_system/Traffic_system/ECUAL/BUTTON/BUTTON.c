/*
 * BUTTON.c
 *
 * Created: 8/31/2022 5:54:18 PM
 *  Author: omart
 */ 

#include "BUTTON.h"

/*****************************************************************************
* Function Name: BUTTON_init
* Purpose      : Initialize button
* Parameters   : Register name, pin number
* Return value : Void
*****************************************************************************/
void BUTTON_init(REG_name_t reg, PIN_num_t pin){
	DIO_init_pin(reg, pin, INPUT);	
	DIO_write(reg, pin, HIGH);
}


/*****************************************************************************
* Function Name: BUTTON_init_with_interrupt
* Purpose      : Initialize button with external interrupt pin
* Parameters   : Register name, pin number, external interrupt #, edge, function to be used when interrupt occurs
* Return value : Void
*****************************************************************************/
void BUTTON_init_with_interrupt(REG_name_t reg, PIN_num_t pin, EX_INT_num_t ex, EX_INT_edge_t edge, void(*fptr)(void)){
	DIO_init_pin(reg, pin, INPUT);
	DIO_write(reg, pin, HIGH);
	EX_INTERRUPT_init(ex, edge, fptr);
}


/*****************************************************************************
* Function Name: BUTTON_read
* Purpose      : Read value on button
* Parameters   : Register name, pin number
* Return value : Value on button (uint8_t) 0 or 1
*****************************************************************************/
uint8_t BUTTON_read(REG_name_t reg, PIN_num_t pin){
	return DIO_read(reg, pin);
}