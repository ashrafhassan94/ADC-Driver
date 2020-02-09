/*
 * DIO_prog.c
 *
 *  Created on: Nov 12, 2018
 *      Author: Ashraf
 */

#include"DIO_int.h"

#include"Bit_math.h"
#include<avr/io.h>

void DIO_vidSetPinDirection(u8 u8PortNumber ,u8 u8PinNumber,u8 u8Direction)
{
	// check port number
	switch(u8PortNumber)
	{
	case DIO_PORTA:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// pin is output
			SET_BIT(DDRA,u8PinNumber);

		}

		else
		{
			// pin is input
			CLR_BIT(DDRA,u8PinNumber);
		}
		break ;
	case DIO_PORTB:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// pin is output
			SET_BIT(DDRB,u8PinNumber);
		}

		else
		{
			// pin is input
			CLR_BIT(DDRB,u8PinNumber );
		}
		break ;
	case DIO_PORTC:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// pin is output
			SET_BIT(DDRC,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(DDRC,u8PinNumber );
		}
		break ;
	case DIO_PORTD:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// pin is output
			SET_BIT(DDRD,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(DDRD,u8PinNumber );
		}
		break ;

	default :
		break;
	}
}
void DIO_vidSetPinValue(u8 u8PortNumber , u8 u8PinNumber, u8 u8Value)
{
	switch(u8PortNumber)
	{
	case DIO_PORTA:
		// check value
		if(u8Value == DIO_High)
		{
			// pin is output
			SET_BIT(PORTA,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(PORTA,u8PinNumber );
		}
		break ;
	case DIO_PORTB:
		// check direction
		if(u8Value == DIO_High)
		{
			// pin is output
			SET_BIT(PORTB,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(PORTB,u8PinNumber );
		}
		break ;
	case DIO_PORTC:
		// check direction
		if(u8Value == DIO_High)
		{
			// pin is output
			SET_BIT(PORTC,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(PORTC,u8PinNumber );
		}
		break ;
	case DIO_PORTD:
		// check direction
		if(u8Value == DIO_High)
		{
			// pin is output
			SET_BIT(PORTD,u8PinNumber );
		}

		else
		{
			// pin is input
			CLR_BIT(PORTD,u8PinNumber );
		}
		break ;

	default :
		break;

	}
}
void DIO_vidGetPinValue(u8 u8PortNumber ,u8 u8PinNumber,u8 * pu8Value)
{
	// check port number
	switch(u8PortNumber)
	{
	case DIO_PORTA:

		(*pu8Value) = GET_BIT(PINA,u8PinNumber);

		break ;
	case DIO_PORTB:

		(*pu8Value) = GET_BIT(PINB,u8PinNumber);

		break;
	case DIO_PORTC:

		(*pu8Value) = GET_BIT(PINC,u8PinNumber);

		break ;
	case DIO_PORTD:

		(*pu8Value) = GET_BIT(PIND,u8PinNumber);

		break ;
	default :
		break;
	}
}

void DIO_vidSetPortDirection(u8 u8PortNumber,u8 u8Direction)
{
	// check port number
	switch(u8PortNumber)
	{
	case DIO_PORTA:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// Port is output
			SET_REG(DDRA);
		}

		else
		{
			// port is input
			CLR_REG(DDRA );
		}
		break ;
	case DIO_PORTB:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// Port is output
			SET_REG(DDRB);
		}

		else
		{
			// port is input
			CLR_REG(DDRB );
		}
		break ;
	case DIO_PORTC:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// Port is output
			SET_REG(DDRC);
		}

		else
		{
			// port is input
			CLR_REG(DDRC );
		}
		break ;
	case DIO_PORTD:
		// check direction
		if(u8Direction == DIO_Output)
		{
			// Port is output
			SET_REG(DDRD);
		}

		else
		{
			// port is input
			CLR_REG(DDRD );
		}
		break ;

	default :
		break;
	}
}
void DIO_vidSetPortValue(u8 u8PortNumber, u8 u8Value)
{
	switch(u8PortNumber)
	{
	case DIO_PORTA:
		// check value
		PORTA=u8Value;
		break ;
	case DIO_PORTB:
		PORTB=u8Value;
		break ;
	case DIO_PORTC:
		PORTC=u8Value;
		break ;
	case DIO_PORTD:
		PORTD=u8Value;
		break ;

	default :
		break;

	}
}
void DIO_vidGetPortValue(u8 u8PortNumber ,u8 * pu8Value)
{
	// check port number
	switch(u8PortNumber)
	{
	case DIO_PORTA:

		(*pu8Value) = PINA;

		break ;
	case DIO_PORTB:

		(*pu8Value) = PINB;

		break;
	case DIO_PORTC:

		(*pu8Value) = PINC;
		break ;
	case DIO_PORTD:

		(*pu8Value) = PIND;

		break ;
	default :
		break;
	}
}

void DIO_vidEnablePullUp(u8 u8PortNumber,u8 u8PinNumber)
{
	switch(u8PortNumber)
	{
	case DIO_PORTA:
		/*Enable Pull up resistance for Port A*/
		SET_BIT(PORTA,u8PinNumber);
		break;
	case DIO_PORTB:
		/*Enable Pull up Resistane for Port B*/
		SET_BIT(PORTB,u8PinNumber);
		break;
	case DIO_PORTC:
		/*Enable Pull up Resistane for Port C*/
		SET_BIT(PORTC,u8PinNumber);
		break;
	case DIO_PORTD:
		/*Enable Pull up Resistane for Port D*/
		SET_BIT(PORTD,u8PinNumber);
		break;
	default:
		break;
	}
}
