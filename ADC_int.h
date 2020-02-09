/*
 * ADC_int.h
 *
 *  Created on: Dec 3, 2018
 *      Author: Ashraf
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_
#include"types.h"

#define ADC_STEPSIZE
void ADC_vidStartConversion(u8 u8ChanelID, u16 * pu16AnalogValue_mv);
void ADC_vidIntialize(void);

// Vref options

#define ADC_AREF   0
#define ADC_VCC    1
#define ADC_2500mv 2


// Left Adjustment options
#define ADC_LADJ_ENABLE 0
#define ADC_LADJ_DIABLE 1


// Channel options

#define ADC_CH0    0
#define ADC_CH1    1
#define ADC_CH2    2
#define ADC_CH3    3
#define ADC_CH4    4
#define ADC_CH5    5
#define ADC_CH6    6
#define ADC_CH7    7


// auto trigger source

#define ADC_FREE_RUNNING   0
#define ADC_INT0           1

// intterupt enable options

#define ADC_INTENABLE 1
#define ADC_INTDIABLE 0




#endif /* ADC_INT_H_ */
