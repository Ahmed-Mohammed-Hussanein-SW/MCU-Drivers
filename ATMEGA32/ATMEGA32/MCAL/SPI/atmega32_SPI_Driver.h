/*
 * atmega32_SPI_Driver.h
 *
 * Created: 9/20/2022 1:23:13 AM
 *  Author: Ahmed
 */ 


#ifndef ATMEGA32_SPI_DRIVER_H_
#define ATMEGA32_SPI_DRIVER_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"

#include "atmega32_device_header.h"

// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

typedef struct
{
	uint8 SPI_MasterSlaveSelect;	 // This specifies the MCU works in master mode or slave mode.
									//	This parameter must be a value of @ref SPI_MCU_MODE_define.
	
	uint8 SPI_DataOrder;	 // This specifies the data order (MSB first or LSB first) to be transmitted.
							//  This parameter must be a value of @ref SPI_DATA_ORDER_define.
							
	uint8 SPI_ClockPolarityPhase;		// This specifies the clock polarity this means at idle case the clock will be high or low.
									   //  and clock phase which means the data is sampled at first edge or last edge.
									  //   This parameter must be a value of @ref SPI_CLOCK_POLARITY_PHASE_define.
									  
	uint8 SPI_ClockRate;		// This specifies the clock speed from master to slave by dividing the input clock to SPI by a factor.
							   //  This parameter must be a value of @ref SPI_CLOCK_RATE_define.
							   
	uint8 SPI_INT_EN;		// This is used to enable the interrupt or disable it.
						   //  This parameter must be a value of @ref SPI_INT_define.
							   
	void (* ptr2IRQ_CallBack) (void);	
	
}	SPI_Config_t;



// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref SPI_MCU_MODE_define.
#define SPI_MCU_MODE_SLAVE		  0
#define SPI_MCU_MODE_MASTER		  1


// @ref SPI_DATA_ORDER_define.
#define SPI_DATA_ORDER_MSB		 0
#define SPI_DATA_ORDER_LSB		 1


// @ref SPI_CLOCK_POLARITY_PHASE_define.
#define SPI_CLOCK_POLARITY_PHASE_LOW_FIRST		0
#define SPI_CLOCK_POLARITY_PHASE_LOW_LAST		1
#define SPI_CLOCK_POLARITY_PHASE_HIGH_FIRST		2	
#define SPI_CLOCK_POLARITY_PHASE_HIGH_LAST		3 

// @ref SPI_CLOCK_RATE_define.
#define SPI_CLOCK_RATE_DIV_4					0
#define SPI_CLOCK_RATE_DIV_16					1
#define SPI_CLOCK_RATE_DIV_64					2
#define SPI_CLOCK_RATE_DIV_128					3
#define SPI_CLOCK_RATE_DIV_2					4
#define SPI_CLOCK_RATE_DIV_8					5
#define SPI_CLOCK_RATE_DIV_32					6
//#define SPI_CLOCK_RATE_DIV_64					7

// @ref SPI_INT_define.
#define SPI_INT_DISABLE							0
#define SPI_INT_ENABLE							1

// ===================================================
// ================== APIs Functions =================
// ===================================================

void MCAL_SPI_Init(SPI_Config_t *Config);
void MCAL_SPI_Tx(uint8 data);
uint8 MCAL_SPI_Rx(void);



#endif /* ATMEGA32_SPI_DRIVER_H_ */