/*
 * LCD_prog.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Ashraf
 */
#define F_CPU 12000000
#include<avr/io.h>
#include<avr/delay.h>

#include"types.h"
#include"DIO_int.h"
#include"LCD_int.h"

void LCDvid_WriteData(u8 u8Data)
{
	/* Logic control pins
	 *
	 RS<<--1*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,DIO_High);

	/*RS<<--0*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RWPIN,DIO_low);
	// write data
	DIO_vidSetPortValue(LCD_DATAPORT,u8Data);

	// enable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,DIO_High);
	_delay_ms(2);
	//disable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,DIO_low);
}

void LCDvid_WriteCommand(u8 u8Command)
{
	/* Logic control pins
	 *
		 RS<<--1*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,DIO_low);

	/*RS<<--0*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RWPIN,DIO_low);
	// write data
	DIO_vidSetPortValue(LCD_DATAPORT,u8Command);
	// enable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,DIO_High);
	_delay_ms(2);
	//disable
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,DIO_low);
}

void LCDvid_Initialize(void)

{
	//DELAY wait for VSS to reach it's value
	_delay_ms(100);
	// function set ON two lines
	LCDvid_WriteCommand(0b00111000);
	//DELAY
	_delay_ms(1);
	// write command on display cursor blinking
	LCDvid_WriteCommand(0b00001111);
	//DELAY
	_delay_ms(1);
	// write command clear last display
	LCDvid_WriteCommand(0b00000001);
	//DELAY
	_delay_ms(20);
}


void LCD_VIDGOTO(u8 line_num,u8 u8charnum)
{
	u8 u8counter;
	switch (line_num)
	{
		case LINE_1:
			for(u8counter=0;u8counter<=u8charnum;u8counter++)
			{
				LCDvid_WriteCommand(0b00011100);
			}
			break;
		case LINE_2:
			LCDvid_WriteCommand(0b11000000);
				for(u8counter=0;u8counter<=u8charnum;u8counter++)
						{
							LCDvid_WriteCommand(0b00011100);
						}
						break;
			break;
		default:
			break;
	}
	// one shift to the right
		LCDvid_WriteCommand(0b00011100);
	// delay
		_delay_ms(1);


}

void LCD_vidWriteString(u8 str[], u8 u8lenght)
{

	 //u8* pu8string;
	 u8 i;

		//(pu8string)=str[0];

		for(i=0; i<u8lenght; i++)
			{
			LCDvid_WriteData(str[i]);
			}

}
