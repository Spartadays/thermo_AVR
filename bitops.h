/*
 * bitops.h
 *
 *  Created on: 12 mar 2019
 *      Author: Mateusz W¹t³y
 */

#ifndef BITOPS_H_
#define BITOPS_H_

#define SETBIT(ADDRESS, BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS, BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS, BIT) (ADDRESS & (1<<BIT))

#define SETBITMASK(x, y) (x |= (y))
#define CLEARBITMASK(x, y) (x &= (~y))
#define FLIPBITMASK(x, y) (x ^= (y))
#define CHECKBITMASK(x, y) (x & (y))

#endif /* BITOPS_H_ */
