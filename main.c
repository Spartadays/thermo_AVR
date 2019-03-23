/*
 * main.c
 *
 *  Created on: Mar 21, 2019
 *      Author: Mateusz W¹t³y
 */
#include "main.h"

int main()
{
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
	_NOP();
	//----
	send_reg_to_led(0x00, 0x00);  //clear leds
	//LOOP:
	while(1)
	{
		led_startup_test();
	}
	//----
	return 0;
}

