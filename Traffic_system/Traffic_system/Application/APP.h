/*
 * APP.h
 *
 * Created: 8/31/2022 7:22:38 PM
 *  Author: omart
 */ 


#ifndef APP_H_
#define APP_H_


#include "../ECUAL/LED/LED.h"
#include "../ECUAL/BUTTON/BUTTON.h"
#include "../SERVICES/DELAY/DELAY_MS.h"


typedef enum{
	NORMAL_MODE,
	PEDESTRIAN_MODE
}Mode_t;


void APP_init(void);
void APP_loop(void);
void button_func(void);

#endif /* APP_H_ */