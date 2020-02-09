/*
 * LCD_int.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Ashraf
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include"types.h"
#include"DIO_int.h"

#define LCD_RSPIN  0
#define LCD_RSPORT  DIO_PORTC
#define LCD_RWPIN  1
#define LCD_RWPORT  DIO_PORTC
#define LCD_DATAPORT DIO_PORTD
#define LCD_ENPIN 2
#define	LCD_ENPORT	DIO_PORTC

/// command code
#define LCD_CLRCODE 1




void LCDvid_WriteData(u8 u8Data);
void LCDvid_WriteCommand(u8 u8Command);
void LCDvid_Initialize(void);

void LCD_VIDGOTO(u8 line_num,u8 u8charnum);////assignment 1

void LCD_vidWriteString(u8 str[], u8 u8lenght);

//void LCD_vidWriteString(u8* pu8string, u8 u8lenght); //assignment 2

//void LCD_vidWriteString(u8 u8string, u8 u8lenght);

/* hint : u8 ass[]6={'a','s',....};
 */

//// IMT 1,1----> 2,2----> 3,1 AFTER 500ms



#endif /* LCD_INT_H_ */
