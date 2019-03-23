/*
 * main.h
 *
 *  Created on: Mar 23, 2019
 *      Author: Mateusz W¹t³y
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <avr/io.h>
#include <util/delay.h>
#include "bitops.h"
#include "myatmega8macros.h"
#include "twodigitsevensegment.h"

#define _NOP() do { __asm__ __volatile__ ("nop"); } while (0)

int main();

#endif /* MAIN_H_ */
