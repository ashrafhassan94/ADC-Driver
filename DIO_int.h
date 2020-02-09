/*
 * DIO_int.h
 *
 *  Created on: Nov 12, 2018
 *      Author: Ashraf
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#include"types.h"

//Port value options
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// directions options

#define DIO_Output 1
#define DIO_Input  0

//pin values

#define DIO_High 1
#define DIO_low 0

// line values

#define LINE_1 0
#define LINE_2 1

// 7 segments number

#define zero  0b00111111
#define one   0b00000110
#define two   0b01011011
#define three 0b01001111
#define four  0b01100110
#define five  0b01101101
#define six   0b01111101
#define seven 0b00000111
#define eight 0b01111111
#define nine  0b01101111


void DIO_vidSetPinDirection(u8 u8PortNumber ,u8 u8PinNumber,u8 u8Direction);
void DIO_vidGetPinValue(u8 u8PortNumber ,u8 u8PinNumber,u8 * pu8Value);
void DIO_vidSetPinValue(u8 u8PortNumber , u8 u8PinNumber, u8 u8Value);

void DIO_vidSetPortDirection(u8 u8PortNumber ,u8 u8Direction);
void DIO_vidSetPortValue(u8 u8PortNumber , u8 u8Value);
void DIO_vidGetPortValue(u8 u8PortNumber , u8 * pu8Value);

void DIO_vidEnablePullUp(u8 u8PortNumber,u8 u8PinNumber);

#endif /* DIO_INT_H_ */
