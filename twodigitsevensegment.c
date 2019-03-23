/*
 * twodigitsevensegment.c
 *
 *  Created on: Mar 22, 2019
 *      Author: Mateusz W¹t³y
 */
#include "twodigitsevensegment.h"

void seg_L_lcd(char i, char state)
{
	switch (i)
		{
			case G:
				if(state) PIN_SETX(GLPORT, GLPIN); else PIN_CLEARX(GLPORT, GLPIN);
				break;
			case F:
				if(state) PIN_SETX(FLPORT, FLPIN); else PIN_CLEARX(FLPORT, FLPIN);
				break;
			case E:
				if(state) PIN_SETX(ELPORT, ELPIN); else PIN_CLEARX(ELPORT, ELPIN);
				break;
			case D:
				if(state) PIN_SETX(DLPORT, DLPIN); else PIN_CLEARX(DLPORT, DLPIN);
				break;
			case C:
				if(state) PIN_SETX(CLPORT, CLPIN); else PIN_CLEARX(CLPORT, CLPIN);
				break;
			case B:
				if(state) PIN_SETX(BLPORT, BLPIN); else PIN_CLEARX(BLPORT, BLPIN);
				break;
			case A:
				if(state) PIN_SETX(ALPORT, ALPIN); else PIN_CLEARX(ALPORT, ALPIN);
				break;
			default:
				break;
		}
}

void seg_R_lcd(char i, char state)
{
	switch (i)
		{
			case G:
				if(state) PIN_SETX(GRPORT, GRPIN); else PIN_CLEARX(GRPORT, GRPIN);
				break;
			case F:
				if(state) PIN_SETX(FRPORT, FRPIN); else PIN_CLEARX(FRPORT, FRPIN);
				break;
			case E:
				if(state) PIN_SETX(ERPORT, ERPIN); else PIN_CLEARX(ERPORT, ERPIN);
				break;
			case D:
				if(state) PIN_SETX(DRPORT, DRPIN); else PIN_CLEARX(DRPORT, DRPIN);
				break;
			case C:
				if(state) PIN_SETX(CRPORT, CRPIN); else PIN_CLEARX(CRPORT, CRPIN);
				break;
			case B:
				if(state) PIN_SETX(BRPORT, BRPIN); else PIN_CLEARX(BRPORT, BRPIN);
				break;
			case A:
				if(state) PIN_SETX(ARPORT, ARPIN); else PIN_CLEARX(ARPORT, ARPIN);
				break;
			default:
				break;
		}
}

struct NumberAs2Digits num_to_dig (char number)
{
	struct NumberAs2Digits num;
	num.dL = number/10;
	num.dR = number%10;
	return num;
}

char dig_to_reg(char dig)
{
	char reg = 0x00;
	switch (dig)
	{
		case 0:
			//----0b0abcdefg
			reg = 0b01111110;
			break;
		case 1:
			reg = 0b00110000;
			break;
		case 2:
			reg = 0b01101101;
			break;
		case 3:
			reg = 0b01111001;
			break;
		case 4:
			reg = 0b00110011;
			break;
		case 5:
			reg = 0b01011011;
			break;
		case 6:
			reg = 0b01011111;
			break;
		case 7:
			reg = 0b01110000;
			break;
		case 8:
			reg = 0b01111111;
			break;
		case 9:
			reg = 0b01111011;
			break;
		default:
			reg = ERROR;
			break;
	}
	return reg;
}

void send_reg_to_led(char regL, char regR)
{
	for (int i = G; i <= A; i++)
	{
		seg_L_lcd(i, CHECKBIT(regL, i));
		seg_R_lcd(i, CHECKBIT(regR, i));
	}
}

void send_number_to_led(char two_digit_number)
{
	if(two_digit_number > 99 || two_digit_number < 0)
	{
		send_reg_to_led(ERROR, ERROR);
		return;
	}
	send_reg_to_led(dig_to_reg(num_to_dig(two_digit_number).dL),
					dig_to_reg(num_to_dig(two_digit_number).dR));
}

void led_startup_test()
{
	send_reg_to_led(ERROR, ERROR);
	_delay_ms(500);
	for (char var = 0; var <= 8; var++)
	{
		send_reg_to_led(0x01 << var, 0x01 << var);
		_delay_ms(250);
	}

	_delay_ms(250);
	send_reg_to_led(0xFF, 0xFF);
	_delay_ms(250);
	send_reg_to_led(0x00, 0x00);

	for (char var = 0; var <= 99; var++)
	{
		send_number_to_led(var);
		_delay_ms(50);
	}
	for (char var = 0; var <= 9; var++)
	{
		send_number_to_led(var);
		_delay_ms(500);
	}
}
