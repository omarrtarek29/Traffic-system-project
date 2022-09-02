/*
 * TIMER1.h
 *
 * Created: 8/30/2022 11:18:36 PM
 *  Author: omart
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_reg_conf.h"
#include "../../std_macros.h"


void TIMER1_normalMode_init(void);
void TIMER1_ctcMode_init(void (*fptr)(void));
void TIMER1_write(uint16_t value);
void TIMER1_ctcMode_stop(void);
void delay_ms(uint16_t delayTime);



#endif /* TIMER1_H_ */