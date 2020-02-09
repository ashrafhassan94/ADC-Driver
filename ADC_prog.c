/*
 * ADC_prog.c
 *
 *  Created on: Dec 3, 2018
 *      Author: Ashraf
 */
#include"ADC_cfg.h"
#include"ADC_int.h"
#include"Bit_math.h"
#include<avr/interrupt.h>

#if ADC_LADJ_START  == ADC_LADJ_ENABLE

#if ADC_VREF_SOURCE == ADC_VCC
#define ADC_STEPSIZE  20
#elif ADC_VREF_SOURCE == ADC_2500mv
#define ADC_STEPSIZE  10
#endif

#else
#if ADC_VREF_SOURCE == ADC_VCC
#define ADC_STEPSIZE  5
#elif ADC_VREF_SOURCE == ADC_2500mv
#define ADC_STEPSIZE  2
#endif

#endif

void ADC_vidStartConversion(u8 u8ChanelID, u16 * pu16AnalogValue_mv)
{
	switch(u8ChanelID)
	{
	case ADC_CH0 :
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
		break;
	case ADC_CH1 :
		break;
	case ADC_CH2 :
		break;
	case ADC_CH3 :
		break;
	case ADC_CH4 :
		break;
	case ADC_CH5 :
		break;
	case ADC_CH6 :
		break;
	case ADC_CH7 :
		break;

	}

	// Start conversion
	SET_BIT(ADCSRA,ADSC);

	while(GET_BIT(ADCSRA,ADSC) == 1)
	{ }
	// Read Conversion

#if ADC_LADJ_START == ADC_LADJ_ENABLE
	(*pu16AnalogValue_mv) = (ADCH * ADC_STEPSIZE );

#else
#endif


}
void ADC_vidIntialize(void)

{

	// Select Vref Source

#if ADC_VREF_SOURCE == ADC_AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

#elif ADC_VREF_SOURCE == ADC_VCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);


	////// Left Adjustment Enable

#elif ADC_VREF_SOURCE == ADC_2500mv
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);

#endif

#if ADC_LADJ_START == ADC_LADJ_ENABLE
	SET_BIT(ADMUX,ADLAR);

#elif ADC_LADJ_START == ADC_LADJ_DIABLE
	CLR_BIT(ADMUX,ADLAR);

#endif


	/////Channel options comp


#if ADC_CHANNEL_INIT == ADC_CH0
#elif ADC_CHANNEL_INIT == ADC_CH1
	SET_BIT(ADMUX,MUX0);
#elif ADC_CHANNEL_INIT == ADC_CH2
	SET_BIT(ADMUX,MUX1);
#elif ADC_CHANNEL_INIT == ADC_CH3
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
#elif ADC_CHANNEL_INIT == ADC_CH4
	SET_BIT(ADMUX,MUX2);
#elif ADC_CHANNEL_INIT == ADC_CH5
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX2);
#elif ADC_CHANNEL_INIT == ADC_CH6
	SET_BIT(ADMUX,MUX2);
	SET_BIT(ADMUX,MUX1);
#elif ADC_CHANNEL_INIT == ADC_CH7
	SET_BIT(ADMUX,MUX0);
	SET_BIT(ADMUX,MUX1);
	SET_BIT(ADMUX,MUX2);

#endif

#if ADC_AUTOTRIG_SOURCE == ADC_FREE_RUNNING


#else
#endif

#if ADC_INT_INIT == ADC_INTDIABLE
	CLR_BIT(ADCSRA,ADIE);

#else
	SET_BIT(ADCSRA,ADIE);
#endif
	/// prescaller 64

	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);

	// Enable ADC
	SET_BIT(ADCSRA,ADEN);
}
