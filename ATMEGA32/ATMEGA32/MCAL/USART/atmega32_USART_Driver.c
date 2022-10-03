/*
 * atmega32_USART_Driver.c
 *
 * Created: 9/23/2022 8:07:05 AM
 *  Author: Ahmed
 */ 

// =============================================
// ================== Includes =================
// =============================================

#include <avr/interrupt.h>

#include "Utils.h"

#include "atmega32_USART_Driver.h"
#include "atmega32_GPIO_Driver.h"

/*
 * ==============================================================================
 * ================================= Generic Variables ==========================
 * ==============================================================================
 */

uint8			*GPtr2UBRRL = USARTx_UBRRL;
UCSRB_TypeDef	*GPtr2UCSRB = USARTx_UCSRB;
UCSRA_TypeDef	*GPtr2UCSRA = USARTx_UCSRA;
uint8			*GPtr2UDR	= USARTx_UDR;
UBRRH_TypeDef	*GPtr2UBRRH = USARTx_UBRRH;
UCSRC_TypeDef	*GPtr2UCSRC = USARTx_UCSRC;

/*
 * ===========================================================================
 * ================================= Generic Macros ==========================
 * ===========================================================================
 */


#define NULL (void*)0

// USART GPIO Pins


// USART Flags
#define USART_RXC		7
#define USART_TXC		6
#define USART_UDRE		5
#define USART_FE		4
#define USART_DOR		3
#define USART_PE		2

/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

/**================================================================
* @Fn				- MCAL_USART_Init
* @brief			- This is used to configure and initialize USART.
* @param [in] 		- config: This carries the configuration for USART.
* @retval 			- None.
* Note				- None.
*/
void MCAL_USART_Init(USART_Config_t *config)
{
	// Set Baud Rate.
	*GPtr2UBRRL				= (uint8)config->baudRate;
	GPtr2UBRRH->bit._URSEL	= 0;
	GPtr2UBRRH->bit._UBRR	= ((config->baudRate >> 8));
	
	// Set Character Size.
	GPtr2UCSRC->bit._URSEL = 1;
	GPtr2UCSRC->bit._UCSZx = config->characterSize;
	GPtr2UCSRB->bit._UCSZ2 = config->characterSize >> 2;
	
	// Communication Mode.
	GPtr2UCSRC->bit._URSEL = 1;
	GPtr2UCSRC->bit._UMSEL = config->communicationMode >> 1;
	
	switch (config->communicationMode)
	{
		case USART_MODE_ASYNC_NORMAL:
			GPtr2UCSRA->bit._U2X = 0;
				break;
		
		case USART_MODE_ASYNC_DOUBLE:
			GPtr2UCSRA->bit._U2X = 1;
				break;
		
		case USART_MODE_SYNC_MASETER:
			// configure XCK as output.
			GPIO_PinConfig_t pinPB0;
			pinPB0.GPIO_PinMode		= GPIO_MODE_OUTPUT;
			MCAL_GPIO_Init(GPIOx_PORTB, &pinPB0);
			
			GPtr2UCSRA->bit._U2X	= 0;
		
			// clock polarity.
			GPtr2UCSRC->bit._UCPOL = config->clockPolarity;
			break;
		
		case USART_MODE_SYNC_SLAVE:
			// configure XCK as input.
			GPIO_PinConfig_t pinPB0;
			pinPB0.GPIO_PinMode		= GPIO_MODE_INPUT;
			MCAL_GPIO_Init(GPIOx_PORTB, &pinPB0);
			
			GPtr2UCSRA->bit._U2X	= 0;
		
			// clock polarity.
			GPtr2UCSRC->bit._UCPOL = config->clockPolarity;
			break;
	}
	
	// Parity Mode.
	GPtr2UCSRC->bit._URSEL	= 1;
	GPtr2UCSRC->bit._UBMx	= config->parityMode;
	
	// Stop Bit.
	GPtr2UCSRC->bit._USBS = config->stopBit;
	
	
	// Enable Tx & Rx.
	GPtr2UCSRB->bit._TXEN = 1;
	GPtr2UCSRB->bit._RXEN = 1;
	
	
}

void MCAL_USART_sendData(uint8 TxBuffer)
{
	while(!GPtr2UCSRA->bit._UDRE);
	
	*GPtr2UDR = TxBuffer;
}


uint8 MCAL_USART_receiveData(void)
{
	while (!GPtr2UCSRA->bit._RXC);
	
	return *GPtr2UDR;
}
