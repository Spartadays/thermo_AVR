/*
 * main.c
 *
 *  Created on: Mar 21, 2019
 *      Author: Mateusz W¹t³y
 */
#include "main.h"

void ADC_Init()
{
	//---ADMUX---:
	{
		//[7,6] REFSn - Vref selection: (avcc)
		CLEARBIT(ADMUX, REFS1);
		SETBIT(ADMUX, REFS0);
		//[5] ADLAR - ADC Left Adjust Result: (off)
		CLEARBIT(ADMUX, ADLAR);
		//[3, 2, 1, 0] MUXn - Analog channel selection: (ADC5)
		CLEARBIT(ADMUX, MUX3);
		SETBIT(ADMUX, MUX2);
		CLEARBIT(ADMUX, MUX1);
		SETBIT(ADMUX, MUX0);
	}
	//---ADCSRA---:
	{
		//[7] ADEN - ADC enable: (on)
		SETBIT(ADCSRA, ADEN);
		//[6] ADSC - ADC start conversion: (off)
		CLEARBIT(ADCSRA, ADSC);
		//[5] ADFR - ADC free running select: (off)
		CLEARBIT(ADCSRA, ADFR);
		//[4] ADIF - ADC interrupt flag (check)
		//[3] ADIE - ADC interrupt enable: (off)
		CLEARBIT(ADCSRA, ADIE);
		//[2, 1, 0] ADPSn - ADC prescaler select: (128)
		SETBIT(ADCSRA, ADPS2);
		SETBIT(ADCSRA, ADPS1);
		SETBIT(ADCSRA, ADPS0);
	}
}

int main()
{
	int temp_val = 0;

	//PIN SETUP:
	PIN_OUTPUT(B, 0);  //disp 6
	PIN_OUTPUT(B, 1);  //disp 8
	PIN_OUTPUT(B, 2);  //disp 7
	PIN_OUTPUT(B, 3);  //disp 16
	PIN_OUTPUT(B, 4);  //disp 15
	PIN_OUTPUT(B, 5);  //disp 14

	PIN_OUTPUT(C, 0);  //disp 13
	PIN_OUTPUT(C, 1);  //disp 12
	PIN_OUTPUT(C, 2);  //disp 11
	PIN_OUTPUT(C, 3);  //disp 10
	PIN_OUTPUT(C, 4);  //disp 9
	PIN_INPUT(C, 5);   //temperature analog in

	PIN_OUTPUT(D, 5);  //disp 1
	PIN_OUTPUT(D, 6);  //disp 2
	PIN_OUTPUT(D, 7);  //disp 3
	//----
	ADC_Init();
	//NOP:
	_NOP();
	//----
	send_reg_to_led(0x00, 0x00);  //clear leds
	//led_startup_test();
	SETBIT(ADCSRA, ADSC); //start conversion
	//LOOP:
	while(1)
	{
		while(CHECKBIT(ADCSRA, ADSC)) {};
		temp_val = ADC/2;
		send_number_to_led(temp_val);
		SETBIT(ADCSRA, ADSC); //start conversion
		_delay_ms(500);
	}
	//----
	return 0;
}

