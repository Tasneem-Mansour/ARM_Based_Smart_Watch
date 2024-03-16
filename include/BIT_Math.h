/*
 * BIT_Math.h
 *
 *  Created on: Dec 10, 2023
 *      Author: Tasneem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG , BIT)     REG |= 1<<BIT
#define CLR_BIT(REG , BIT)     REG &= ~(1<<BIT)
#define TOG_BIT(REG , BIT)     REG ^= 1<<BIT
#define GET_BIT(REG , BIT)     ((REG >> BIT) & 1)

/* if VAL is low, it will set the bit to zero*/
/* can be used instead of switch case in WritePin function*/
//#define WRITE_BIT(REG, BIT, VAL)  	CLR_BIT(REG, BIT) | (VAL <<BIT)

#endif /* BIT_MATH_H_ */
