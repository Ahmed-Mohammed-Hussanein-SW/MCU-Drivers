/*
 * Platform_Types.h
 *
 * Created: 9/5/2022 7:28:02 PM
 *  Author: Ahmed
 */ 


#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#define CPU_TYPE_8        8
#define CPU_TYPE_16      16
#define CPU_TYPE_32      32

#define MSB_FIRST        0
#define LSB_FIRST        1

#define HIGH_BYTE_FIRST  0
#define LOW_BYTE_FIRST   1

/* Little endian, 32 bit processor */
#define CPU_TYPE			    CPU_TYPE_8
#define CPU_BIT_ORDER   	LSB_FIRST
#define CPU_BYTE_ORDER  	LOW_BYTE_FIRST

typedef unsigned char 		boolean;

#ifndef true
#define true  (boolean) 1
#endif

#ifndef false
#define false (boolean) 0
#endif


typedef signed char					sint8;
typedef unsigned char				uint8;
typedef volatile signed char		vsint8;
typedef volatile unsigned char		vuint8;

//typedef signed short				sint16;
//typedef unsigned short				uint16;
//typedef volatile signed short		vsint16;
//typedef volatile unsigned short		vuint16;

typedef signed int					sint16;
typedef unsigned int				uint16;
typedef volatile signed int			vsint16;
typedef volatile unsigned int		vuint16;

typedef signed long int					sint32;
typedef unsigned long int				uint32;
typedef volatile signed long int		vsint32;
typedef volatile unsigned long int		vuint32;

typedef float				    float32;

#endif /* PLATFORM_TYPES_H_ */