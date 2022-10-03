/*
 * atmega32_USART_Driver.h
 *
 * Created: 9/23/2022 8:07:45 AM
 *  Author: Ahmed
 */ 


#ifndef ATMEGA32_USART_DRIVER_H_
#define ATMEGA32_USART_DRIVER_H_


// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"

#include "atmega32_device_header.h"

// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

// XCK --> PB0
// PD0 --> RXD
// PD1 --> TXD

typedef struct
{
	uint16 baudRate;			// This specifies the speed of transmission and receiving.
							   //  This parameter must be a value of @ref USART_DAUDRATE_define.
	
	uint8 characterSize;		// This specifies frame's payload character size.
							   //  This parameter must be a value of @ref USART_CHARSIZE_define.
							   
	uint8 clockPolarity;		 // This specifies the edge of the clock where the data is sampled.
								//  This parameter must be a value of @ref USART_PLORITY_define.
							   
	uint8 communicationMode;	// This specifies the mode of communication between Tx and Rx.
							   //  This parameter must be a value of @ref USART_MODE_define.
							  
	uint8 parityMode;			// This specifies the parity bit in the frame.
							   //  This parameter must be a value of @ref USART_PARITYMODE_define.

	uint8 stopBit;				// This specifies the number of stop bit in the frame.
							   //  This parameter must be a value of @ref USART_STOPBIT_define.
	


}	USART_Config_t;



// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref USART_DAUDRATE_define.
// @ f = 1MHz and Normal speed mode
#define USART_DAUDRATE_NORMAL_2400				25		// error 0.2%
#define USART_DAUDRATE_NORMAL_4800				12		// error 0.2%
#define USART_DAUDRATE_NORMAL_14400				3		// error 8.5%
#define USART_DAUDRATE_NORMAL_19200				2		// error 8.5%
#define USART_DAUDRATE_NORMAL_28800				1		// error 8.5%
#define USART_DAUDRATE_NORMAL_57600				0		// error 8.5%

// @ f = 1MHz and Double speed mode
#define USART_DAUDRATE_DOUBLE_2400				51		// error 0.2%
#define USART_DAUDRATE_DOUBLE_4800				25		// error 0.2%
#define USART_DAUDRATE_DOUBLE_9600				12		// error 0.2%
#define USART_DAUDRATE_DOUBLE_28800				3		// error 8.5%
#define USART_DAUDRATE_DOUBLE_38400				2		// error 8.5%
#define USART_DAUDRATE_DOUBLE_57600				1		// error 8.5%
#define USART_DAUDRATE_DOUBLE_115200			0		// error 8.5%

// @ref USART_CHARSIZE_define.
#define USART_CHARSIZE_5						0
#define USART_CHARSIZE_6						1
#define USART_CHARSIZE_7						2
#define USART_CHARSIZE_8						3
#define USART_CHARSIZE_9						7


// @ref USART_PLORITY_define.
#define USART_PLORITY_FALLING					0
#define USART_PLORITY_RISING					1


// @ref USART_MODE_define.
#define USART_MODE_ASYNC_NORMAL					0
#define USART_MODE_ASYNC_DOUBLE					1
#define USART_MODE_SYNC_MASETER					2
#define USART_MODE_SYNC_SLAVE					3

// @ref USART_PARITYMODE_define.
#define USART_PARITYMODE_DISABLE				0
#define USART_PARITYMODE_EVEN					2
#define USART_PARITYMODE_ODD					3

// @ref USART_STOPBIT_define
#define USART_STOPBIT_1							0
#define USART_STOPBIT_2							1


// ===================================================
// ================== APIs Functions =================
// ===================================================
void MCAL_USART_Init(USART_Config_t *config);

void MCAL_USART_sendData(uint8 TxBuffer);
uint8 MCAL_USART_receiveData(void);


#endif /* ATMEGA32_USART_DRIVER_H_ */