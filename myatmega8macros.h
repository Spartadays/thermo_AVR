/*
 * myatmega8macros.h
 *
 *  Created on: Mar 21, 2019
 *      Author: Mateusz W¹t³y
 */

#ifndef MYATMEGA8MACROS_H_
#define MYATMEGA8MACROS_H_

#include "bitops.h"
#include <avr/io.h>

#define PIN_OUTPUT(A, x) SETBIT(DDR##A, x)
#define PIN_INPUT(A, x) CLEARBIT(DDR##A, x)
#define PIN_INPUT_PULLUP(A, x) CLEARBIT(DDR##A, x);	SETBIT(PORT##A, x)

#define PIN_SETX(A, x) PIN_SET(A, x)
#define PIN_SET(A, x) SETBIT(PORT##A, x)

#define PIN_CLEARX(A, x) PIN_CLEAR(A, x)
#define PIN_CLEAR(A, x) CLEARBIT(PORT##A, x)

#define PIN_CHECK(A, x) CHECKBIT(PIN##A, x)

#endif /* MYATMEGA8MACROS_H_ */
