/*
 * Utils.h
 *
 * Created: 9/5/2022 7:42:01 PM
 *  Author: Ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SETBIT(reg, bit)		( reg |= ( 1 << (bit) ) )
#define CLEARBIT(reg, bit)		( reg &= ~( 1 << (bit) ) )
#define TOGGLEBIT(reg, bit)		( reg ^= ( 1 << (bit) ) )
#define READBIT(reg, bit)		( ( reg >> (bit) ) & 1 )



#endif /* UTILS_H_ */