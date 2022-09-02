/*
 * LED.h
 *
 * Created: 8/31/2022 5:29:53 PM
 *  Author: omart
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"

void LED_init(REG_name_t reg, PIN_num_t pin);
void LED_on(REG_name_t reg, PIN_num_t pin);
void LED_off(REG_name_t reg, PIN_num_t pin);
void LED_toggle(REG_name_t reg, PIN_num_t pin);


#endif /* LED_H_ */