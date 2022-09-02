/*
 * APP.c
 *
 * Created: 8/31/2022 7:22:31 PM
 *  Author: omart
 */ 

#include "APP.h"

Mode_t mode = NORMAL_MODE;

/*****************************************************************************
* Function Name: APP_init
* Purpose      : Initialize app
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_init(void){
	// Car LEDs
	LED_init(PORTA_t, PIN0_t);
	LED_init(PORTA_t, PIN1_t);
	LED_init(PORTA_t, PIN2_t);
	
	// Pedestrian LEDs
	LED_init(PORTB_t, PIN0_t);
	LED_init(PORTB_t, PIN1_t);
	LED_init(PORTB_t, PIN2_t);
	
	// Pedestrian button
	BUTTON_init_with_interrupt(PORTD_t, PIN2_t, INT0_t, RISING_EDGE, button_func);
}


/*****************************************************************************
* Function Name: APP_loop
* Purpose      : Keep app running continuously
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void APP_loop(void){
	while (1)
	{
		switch (mode)
		{
			case NORMAL_MODE:
			// Turn on car red and pedestrian green for 5 seconds
			LED_on(PORTA_t, PIN0_t);
			LED_on(PORTB_t, PIN2_t);
			
			for (uint8_t i = 0; i < 50; i++)
			{
				// If it's red and interrupt occurs, keep on normal mode
				if (mode == PEDESTRIAN_MODE)
				{
					mode = NORMAL_MODE;
				}
				delay_ms(100);
			}
		
			LED_off(PORTA_t, PIN0_t);
			LED_off(PORTB_t, PIN2_t);
			
			
			// Blink car and pedestrian yellow for 5 seconds
			for (uint8_t i = 0; i < 25; i++)
			{
				// If it's yellow and the next state is green and interrupt occurs, skip this iteration to switch to pedestrian mode
				if (mode == PEDESTRIAN_MODE)
				{
					LED_off(PORTA_t, PIN1_t);
					LED_off(PORTB_t, PIN1_t);
					continue;
				}
				LED_on(PORTA_t, PIN1_t);
				LED_on(PORTB_t, PIN1_t);
				delay_ms(100);
				
				LED_off(PORTA_t, PIN1_t);
				LED_off(PORTB_t, PIN1_t);
				delay_ms(100);
			}
			LED_off(PORTA_t, PIN1_t);
			LED_off(PORTB_t, PIN1_t);
			
			
			// Turn on car green and pedestrian red for 5 seconds
			LED_on(PORTA_t, PIN2_t);
			LED_on(PORTB_t, PIN0_t);
			for (uint8_t i = 0; i < 50; i++)
			{
				// If it's green and interrupt occurs, skip this iteration to switch to pedestrian mode
				if (mode == PEDESTRIAN_MODE)
				{
					LED_off(PORTA_t, PIN2_t);
					LED_off(PORTB_t, PIN0_t);
					continue;
				}
				delay_ms(100);
			}
			LED_off(PORTA_t, PIN2_t);
			LED_off(PORTB_t, PIN0_t);
			
			
			// Blink car and pedestrian yellow for 5 seconds
			for (uint8_t i = 0; i < 25; i++)
			{
				// If it's yellow and the next state is red and interrupt occurs, keep on normal mode
				if (mode == PEDESTRIAN_MODE)
				{
					mode = NORMAL_MODE;
				}
				LED_on(PORTA_t, PIN1_t);
				LED_on(PORTB_t, PIN1_t);
				delay_ms(100);
				
				LED_off(PORTA_t, PIN1_t);
				LED_off(PORTB_t, PIN1_t);
				delay_ms(100);
			}
			LED_off(PORTA_t, PIN1_t);
			LED_off(PORTB_t, PIN1_t);
			break;
			
			
			/**********************************************************************************************************************************************************************/
			/********************************************************************** SPLIT THE TWO MODES ***************************************************************************/
			/**********************************************************************************************************************************************************************/
			
			
			case PEDESTRIAN_MODE:
			// Turn off car and pedestrian red and green LEDs
			LED_off(PORTA_t, PIN0_t);
			LED_off(PORTB_t, PIN2_t);
			LED_off(PORTA_t, PIN2_t);
			LED_off(PORTB_t, PIN0_t);
			
			// Blink car and pedestrian yellow for 5 seconds
			for (uint8_t i = 0; i < 25; i++)
			{
				LED_on(PORTA_t, PIN1_t);
				LED_on(PORTB_t, PIN1_t);
				delay_ms(100);
				
				LED_off(PORTA_t, PIN1_t);
				LED_off(PORTB_t, PIN1_t);
				delay_ms(100);
			}
			LED_off(PORTA_t, PIN1_t);
			LED_off(PORTB_t, PIN1_t);
			
			// Switch back to normal mode
			mode = NORMAL_MODE;
			break;
		}
	}
}


/*****************************************************************************
* Function Name: button_func
* Purpose      : Function to be executed when interrupt (INT0) occurs
* Parameters   : Void
* Return value : Void
*****************************************************************************/
void button_func(void){
	mode = PEDESTRIAN_MODE;
}