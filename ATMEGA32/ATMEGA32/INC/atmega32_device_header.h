/*
 * MemMap.h
 *
 * Created: 9/5/2022 7:16:37 PM
 *  Author: Ahmed
 */ 


#ifndef ATMEGA32_DEVICE_HEADER_H_
#define ATMEGA32_DEVICE_HEADER_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "Utils.h"


// ==========================================================
// ================== Memory Base Addresses =================
// ==========================================================

#define FLUSH_BASE		0x0
#define SRAM_BASE		0x60


// ==============================================================
// ================== Peripheral Base Addresses =================
// ==============================================================


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define GPIOA_BASE		0x39
#define GPIOB_BASE		0x36
#define GPIOC_BASE		0x33
#define GPIOD_BASE		0x30


// *-*-*-*-*-*-*-*-*-*-*-*-*-*
// -*-*-*-*-* USART -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-*
#define USART_BASE			0x29
#define USART_UBRRH_UCSRC	0x40

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define SPI_BASE		0x2D



// =========================================================
// ================== Peripheral Registers =================
// =========================================================

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	vuint8 PINx;
	vuint8 DDRx;
	vuint8 PORTx;
	
} GPIO_TypeDef;

// *-*-*-*-*-*-*-*-*-*-*-*-*-*
// -*-*-*-*-* USART -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	vuint8 UBRRL;
	vuint8 UCSRB;
	vuint8 UCSRA;
	vuint8 UDR;
	
} USART_TypeDef;

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{	
	vuint8 SPCR;
	vuint8 SPSR;
	vuint8 SPDR;
	
} SPI_TypeDef;

// =========================================================
// ================== Peripheral Instances =================
// =========================================================

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* GPIO -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-

#define GPIOA	(GPIO_TypeDef*) (GPIOA_BASE)
#define GPIOB	(GPIO_TypeDef*) (GPIOB_BASE)
#define GPIOC	(GPIO_TypeDef*) (GPIOC_BASE)
#define GPIOD	(GPIO_TypeDef*) (GPIOD_BASE)

// *-*-*-*-*-*-*-*-*-*-*-*-*-*
// -*-*-*-*-* USART -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-*
#define USART			(USART_TypeDef*) (USART_BASE)
#define USART_UBRRH		(uint8*) (USART_UBRRH_UCSRC)
#define USART_UCSRC		(uint8*) (USART_UBRRH_UCSRC)

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define SPI		(SPI_TypeDef*) (SPI_BASE)


#endif /* MEMMAP_H_ */