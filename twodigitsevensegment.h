/*
 * twodigitsevensegment.h
 *
 *  Created on: Mar 22, 2019
 *      Author: Mateusz W¹t³y
 */

#ifndef TWODIGITSEVENSEGMENT_H_
#define TWODIGITSEVENSEGMENT_H_

#include <avr/io.h>
#include <util/delay.h>
#include "myatmega8macros.h"
#include "bitops.h"

//PORTS AND PINS HERE (CONNECTIONS):
#define GLPORT B
#define GLPIN 3
#define FLPORT B
#define FLPIN 5
#define ELPORT D
#define ELPIN 6
#define DLPORT D
#define DLPIN 7
#define CLPORT D
#define CLPIN 5
#define BLPORT C
#define BLPIN 0
#define ALPORT B
#define ALPIN 4

#define GRPORT C
#define GRPIN 4
#define FRPORT C
#define FRPIN 2
#define ERPORT B
#define ERPIN 2
#define DRPORT B
#define DRPIN 0
#define CRPORT B
#define CRPIN 1
#define BRPORT C
#define BRPIN 1
#define ARPORT C
#define ARPIN 3
//---------END---------------

#define ERROR 0b01001111

enum Segment{A = 6, B = 5, C = 4, D = 3, E = 2, F = 1, G = 0};

struct NumberAs2Digits{ char dL, dR; };

//PROCESS DATA:
void seg_L_lcd(char i, char state);
void seg_R_lcd(char i, char state);
struct NumberAs2Digits num_to_dig (char num);
char dig_to_reg(char dig);

//SEND TO LCD:
void send_reg_to_led(char regL, char regR);
void send_number_to_led(char two_digit_number);

void led_startup_short_test();
void led_startup_test();

#endif /* TWODIGITSEVENSEGMENT_H_ */
