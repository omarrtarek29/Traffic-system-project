/*
 * TIMER1_reg_conf.h
 *
 * Created: 8/30/2022 10:51:00 PM
 *  Author: omart
 */ 


#ifndef TIMER1_REG_CONF_H_
#define TIMER1_REG_CONF_H_

// Defining macros for needed registers and pins
#define SREG		(*(volatile uint8_t *)(0x5F))
#define GINT		7	// Global interrupt pin		

#define TIMSK		(*(volatile uint8_t *)(0x59))
#define TOIE0		0
#define OCIE0		1
#define TOIE1		2
#define OCIE1B		3
#define OCIE1A		4

#define TCCR1A		(*(volatile uint8_t *)(0x4F))
#define WGM10		0
#define WGM11		1
#define FOC1B		2
#define FOC1A		3
#define COM1B0		4
#define COM1B1		5
#define COM1A0		6
#define COM1A1		7

#define TCCR1B		(*(volatile uint8_t *)(0x4E))
#define CS10		0
#define CS11		1
#define CS12		2
#define WGM12		3
#define WGM13		4


#define TCNT1H		(*(volatile uint8_t *)(0x4D))
#define TCNT1L		(*(volatile uint8_t *)(0x4C))

#define OCR1AH		(*(volatile uint8_t *)(0x4B))
#define OCR1AL		(*(volatile uint8_t *)(0x4A))

#define OCR1BH		(*(volatile uint8_t *)(0x49))
#define OCR1BL		(*(volatile uint8_t *)(0x48))

#define TIMER1_COMPA_vect		__vector_7

#endif /* TIMER1_REG_CONF_H_ */