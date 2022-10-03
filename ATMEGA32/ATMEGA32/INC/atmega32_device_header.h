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
#define UBRRL_ADDRESS			0x29
#define UCSRB_ADDRESS			0x2A
#define UCSRA_ADDRESS			0x2B
#define UDR_ADDRESS				0x2C
#define UBRRH_ADDRESS			0x40
#define UCSRC_ADDRESS			0x40

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define SPI_BASE				0x2D

// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define EXTI_GI_BASE		0x5A
#define EXTI_MCU_BASE		0x54


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
typedef union
{
	vuint8 allBits;
	
	struct  
	{
		vuint8 _TXB8	:1;
		vuint8 _RXB8	:1;
		vuint8 _UCSZ2	:1;
		vuint8 _TXEN	:1;
		vuint8 _RXEN	:1;
		vuint8 _UDRIE	:1;
		vuint8 _TXCIE	:1;
		vuint8 _RXCIE	:1;
	} bit;
	
} UCSRB_TypeDef;

typedef union
{
	vuint8 allBits;
	
	struct
	{
		vuint8 _MPCM	:1;
		vuint8 _U2X		:1;
		vuint8 _PE		:1;
		vuint8 _DOR		:1;
		vuint8 _FE		:1;
		vuint8 _UDRE	:1;
		vuint8 _TXC		:1;
		vuint8 _RXC		:1;
	} bit;
	
} UCSRA_TypeDef;

typedef union
{
	vuint8 allBits;
	
	struct
	{
		vuint8 _UBRR		:4;
		vuint8 _reserved	:3;
		vuint8 _URSEL		:1;
	} bit;
	
} UBRRH_TypeDef;

typedef union
{
	vuint8 allBits;
	
	struct
	{
		vuint8 _UCPOL	:1;
		vuint8 _UCSZx	:2;
		vuint8 _USBS	:1;
		vuint8 _UBMx	:2;
		vuint8 _UMSEL	:1;
		vuint8 _URSEL	:1;
	} bit;
	
} UCSRC_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	union
	{
		vuint8 allBits;
		
		struct  
		{
			vuint8 _SPRx			:2;
			vuint8 _CPHA			:1;
			vuint8 _CPOL			:1;
			vuint8 _MSTR			:1;
			vuint8 _DORD			:1;
			vuint8 _SPE				:1;
			vuint8 _SPIE			:1;
		} bit;
			
	} _SPCR;
	
	union
	{
		vuint8 allBits;
		
		struct
		{
			vuint8 _SPI2X			:1;
			vuint8 _reseeved		:5;
			vuint8 _WCOL			:1;
			vuint8 _SPIF			:1;
		} bit;
		
	} _SPSR;
	
	vuint8 _SPDR;
	
} SPI_TypeDef;


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{	
	union
	{
		vuint8 allBits;
		
		struct
		{
			vuint8 _reserved		:4;
			vuint8 _INTF2			:1;
			vuint8 _INTF0			:1;
			vuint8 _INTF1			:1;
			
		} bit;
		
	} _GIFR;
	
	union
	{
		vuint8 allBits;
		
		struct
		{
			vuint8 _reserved		:4;
			vuint8 _INT2			:1;
			vuint8 _INT0			:1;
			vuint8 _INT1			:1;
			
		} bit;
		
	} _GICR;
	
} EXTI_GI_TypeDef;

typedef struct
{
	union
	{
		vuint8 allBits;
		
		struct
		{
			vuint8 _reserved		:6;
			vuint8 _ISC2			:1;
			vuint8 _reserved1		:1;
		} bit;
		
	} _MCUCSR;
	
	union
	{
		vuint8 allBits;
		
		struct
		{
			vuint8 _ISC0x			:2;
			vuint8 _ISC1x			:2;
			vuint8 _reserved		:4;
		} bit;
		
	} _MCUCR;
	
} EXTI_MCU_TypeDef;

//#define EXTI_MCUCR		*(vuint8 *) (0x55)
//#define EXTI_MCUCSR		*(vuint8 *) (0x54)
//#define EXTI_GICR		*(vuint8 *) (0x5B)
//#define EXTI_GIFR		*(vuint8 *) (0x5A)

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
#define USARTx_UBRRL			(uint8*)			(UBRRL_ADDRESS)
#define USARTx_UCSRB			(UCSRB_TypeDef*)	(UCSRB_ADDRESS)
#define USARTx_UCSRA			(UCSRA_TypeDef*)	(UCSRA_ADDRESS)
#define USARTx_UDR				(uint8*)			(UDR_ADDRESS)
#define USARTx_UBRRH			(UBRRH_TypeDef*)	(UBRRH_ADDRESS)
#define USARTx_UCSRC			(UCSRC_TypeDef*)	(UCSRC_ADDRESS)


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* SPI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define SPIx					(SPI_TypeDef*)		(SPI_BASE)


// *-*-*-*-*-*-*-*-*-*-*-*-*-
// -*-*-*-*-* EXTI -*-*-*-*-*
// *-*-*-*-*-*-*-*-*-*-*-*-*-
#define EXTI_GI					(EXTI_GI_TypeDef*)	(EXTI_GI_BASE)
#define EXTI_MCU				(EXTI_MCU_TypeDef*) (EXTI_MCU_BASE)

#define Enable_Global_INT()		sei()
#define Disable_Global_INT()	cli()

#endif /* MEMMAP_H_ */