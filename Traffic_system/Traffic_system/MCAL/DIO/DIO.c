/*
 * DIO.c
 *
 * Created: 8/30/2022 8:46:49 PM
 *  Author: omart
 */ 

#include "DIO.h"


/*****************************************************************************
* Function Name: DIO_init_pin
* Purpose      : Initialize a specific pin in a specific port to be input or output
* Parameters   : Register name, pin number and the direction
* Return value : Void
*****************************************************************************/
void DIO_init_pin(REG_name_t reg, PIN_num_t pin, PIN_direction_t direction){
	switch (direction)
	{
		case INPUT:
		switch (reg)
		{
			case PORTA_t:
			CLRBIT(DDRA,pin);
			break;
		
			case PORTB_t:
			CLRBIT(DDRB,pin);
			break;
				
			case PORTC_t:
			CLRBIT(DDRC,pin);
			break;
			
			case PORTD_t:
			CLRBIT(DDRD,pin);
			break;
		}
		break;
		
		case OUTPUT:
		switch (reg)
		{
			case PORTA_t:
			SETBIT(DDRA,pin);
			break;
			
			case PORTB_t:
			SETBIT(DDRB,pin);
			break;
			
			case PORTC_t:
			SETBIT(DDRC,pin);
			break;
			
			case PORTD_t:
			SETBIT(DDRD,pin);
			break;
		}
		break;		
	}
}


/*****************************************************************************
* Function Name: DIO_write
* Purpose      : Write on a specific pin in a specific port whether low or high
* Parameters   : Register name, pin number and the value to be written
* Return value : Void
*****************************************************************************/
void DIO_write(REG_name_t reg, PIN_num_t pin, PIN_value_t value){
	switch (value)
	{
		case LOW:
		switch (reg)
		{
			case PORTA_t:
			CLRBIT(PORTA,pin);
			break;
			
			case PORTB_t:
			CLRBIT(PORTB,pin);
			break;
			
			case PORTC_t:
			CLRBIT(PORTC,pin);
			break;
			
			case PORTD_t:
			CLRBIT(PORTD,pin);
			break;
		}
		break;
		
		case HIGH:
		switch (reg)
		{
			case PORTA_t:
			SETBIT(PORTA,pin);
			break;
			
			case PORTB_t:
			SETBIT(PORTB,pin);
			break;
			
			case PORTC_t:
			SETBIT(PORTC,pin);
			break;
			
			case PORTD_t:
			SETBIT(PORTD,pin);
			break;
		}
		break;
	}
}


/*****************************************************************************
* Function Name: DIO_toggle
* Purpose      : Toggle the value on a specific pin in a specific register
* Parameters   : Register name and pin number
* Return value : Void
*****************************************************************************/
void DIO_toggle(REG_name_t reg, PIN_num_t pin){
	switch (reg)
	{
		case PORTA_t:
		TOGBIT(PORTA,pin);
		break;
		
		case PORTB_t:
		TOGBIT(PORTB,pin);
		break;
		
		case PORTC_t:
		TOGBIT(PORTC,pin);
		break;
		
		case PORTD_t:
		TOGBIT(PORTD,pin);
		break;
	}
}


/*****************************************************************************
* Function Name: DIO_read
* Purpose      : Reads the value on a specific pin in a specific port
* Parameters   : Register name and pin number
* Return value : Pin value (uint8_t) 0 or 1
*****************************************************************************/
PIN_value_t DIO_read(REG_name_t reg, PIN_num_t pin){
	switch (reg)
	{
		case PORTA_t:
		return READBIT(PINA,pin);
		
		case PORTB_t:
		return READBIT(PINB,pin);
		
		case PORTC_t:
		return READBIT(PINC,pin);
		
		case PORTD_t:
		return READBIT(PIND,pin);
	}
	
	return 0;
}