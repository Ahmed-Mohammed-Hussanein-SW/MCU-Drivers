/*
 * atmega32_SPI_Driver.c
 *
 * Created: 9/20/2022 1:23:03 AM
 *  Author: Ahmed
 */ 


// =============================================
// ================== Includes =================
// =============================================

#include "Utils.h"
#include "atmega32_GPIO_Driver.h"

#include "atmega32_SPI_Driver.h"

/*
 * ==============================================================================
 * ================================= Generic Variables ==========================
 * ==============================================================================
 */

void (* GPtr2IRQ_CallBack) (void);

SPI_TypeDef* SPI = SPIx;

/*
 * ===========================================================================
 * ================================= Generic Macros ==========================
 * ===========================================================================
 */


#define NULL 0

// SPI GPIO Pins
#define SPI_PORT		GPIOx_PORTB
#define SCK_PIN			GPIO_PIN_7
#define MISO_PIN		GPIO_PIN_6
#define MOSI_PIN		GPIO_PIN_5
#define SS_PIN			GPIO_PIN_4

// SPI Flags
#define SPI_SPIF		7
#define SPI_WCOL		6

/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

/**================================================================
* @Fn				- MCAL_SPI_Init
* @brief			- This is used to configure and initialize the SPI module.
* @param [in] 		- Config: This defines the initialization and configuration for SPI.
* @retval 			- None.
* Note				- None.
*/
void MCAL_SPI_Init(SPI_Config_t *Config)
{
	//uint8 tempConfig = 0;
	//tempConfig |= Config->SPI_MasterSlaveSelect;
	//tempConfig |= Config->SPI_DataOrder;
	//tempConfig |= Config->SPI_ClockPolarityPhase;
	//tempConfig |= (Config->SPI_ClockRate & 0x03);
	//tempConfig |= Config->SPI_INT_EN;
	//tempConfig |= (1<<6);
	
	// Master or Slave.
	SPI->_SPCR.bit._MSTR = Config->SPI_MasterSlaveSelect;
	
	// Data Order.
	SPI->_SPCR.bit._DORD = Config->SPI_DataOrder;
	
	// Clock Polarity and Phase.
	// CPOL  CPHA
	SPI->_SPCR.bit._CPHA = Config->SPI_ClockPolarityPhase;
	SPI->_SPCR.bit._CPOL = Config->SPI_ClockPolarityPhase >> 1;
	
	// Clock Rate.
	SPI->_SPCR.bit._SPRx	= Config->SPI_ClockRate;
	SPI->_SPSR.bit._SPI2X	= Config->SPI_ClockRate >> 2;
	
	// Enable Interrupt.
	SPI->_SPCR.bit._SPIE	= Config->SPI_INT_EN;
	
	// CallBack Function.
	GPtr2IRQ_CallBack = Config->ptr2IRQ_CallBack;
	
	//SPI->SPSR |= (Config->SPI_ClockRate >> 2);
//
	GPIO_PinConfig_t pinConfig;
	if(Config->SPI_MasterSlaveSelect == SPI_MCU_MODE_MASTER)
	{
		pinConfig.GPIO_PinNumber = MOSI_PIN;
		pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
		MCAL_GPIO_Init(SPI_PORT, &pinConfig);

		pinConfig.GPIO_PinNumber = SCK_PIN;
		MCAL_GPIO_Init(SPI_PORT, &pinConfig);

		pinConfig.GPIO_PinNumber = SS_PIN;
		MCAL_GPIO_Init(SPI_PORT, &pinConfig);
		
	}
	else if(Config->SPI_MasterSlaveSelect == SPI_MCU_MODE_SLAVE)
	{
		pinConfig.GPIO_PinNumber = MISO_PIN;
		pinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
		MCAL_GPIO_Init(SPI_PORT, &pinConfig);
	}
	//
	//
	//gptr2IRQ_CallBack = Config->ptr2IRQ_CallBack;
//
	//SPI->SPCR = tempConfig;
	
	SPI->_SPCR.bit._SPE = 1;
}

/**================================================================
* @Fn				- MCAL_SPI_Tx
* @brief			- This is used to transmit a byte through the SPI.
* @param [in] 		- data: this is the data to be transmitted.
* @retval 			- None.
* Note				- None.
*/
void MCAL_SPI_Tx(uint8 data)
{	
	SPI->_SPDR = data;

	while(!SPI->_SPSR.bit._SPIF);
}

/**================================================================
* @Fn				- MCAL_SPI_Rx
* @brief			- This is used to receive a byte through the SPI.
* @param [in] 		- None.
* @retval 			- The data received.
* Note				- None.
*/
uint8 MCAL_SPI_Rx(void)
{
	while(!SPI->_SPSR.bit._SPIF);
	
	return SPI->_SPDR;
}


//ISR(SPI_STC_vect)
//{
	//if(NULL != gptr2IRQ_CallBack)
	//{
		//gptr2IRQ_CallBack();
	//}
//}