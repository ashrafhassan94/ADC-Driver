/*
 * main.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Ashraf
 */

#include"ADC_int.h"
#include"LCD_int.h"
#include"avr/io.h"
#include"avr/delay.h"

void main(void)
{
	u16 u16VoltRead;
	u8  u8Digit;
	//Initialization

	DIO_vidSetPinDirection(LCD_RSPORT,LCD_RSPIN,DIO_Output);
	DIO_vidSetPinDirection(LCD_RWPORT,LCD_RWPIN,DIO_Output);
	DIO_vidSetPinDirection(LCD_ENPORT,LCD_ENPIN,DIO_Output);
	DIO_vidSetPortDirection(LCD_DATAPORT,DIO_Output);

	// LCD DRIVER
	LCDvid_Initialize();
	// Intialize

	ADC_vidIntialize();

	while(1)
	{
		ADC_vidStartConversion(ADC_CH0,&u16VoltRead);
		// 4th DIgit

		u8Digit=(u16VoltRead/1000);
		LCDvid_WriteData(u8Digit +'0');
		// 3rd DIgit
		u8Digit=((u16VoltRead/100)%10);
		LCDvid_WriteData(u8Digit +'0');
		// 2nd DIgit
		u8Digit=((u16VoltRead/10)%10);
		LCDvid_WriteData(u8Digit +'0');
		// 1st DIgit
		u8Digit=(u16VoltRead%10);
		LCDvid_WriteData(u8Digit +'0');
		_delay_ms(500);
		LCDvid_WriteCommand(LCD_CLRCODE);


	}
}
