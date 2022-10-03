/*
 * atmega32_EXTI_Driver.c
 *
 * Created: 9/28/2022 4:10:15 PM
 *  Author: Ahmed
 */ 

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"

#include "atmega32_EXTI_Driver.h"
#include "atmega32_GPIO_Driver.h"


/*
 * =====================================================================================
 * ================================= Generic Variables =================================
 * =====================================================================================
 */

#define NULL (void*)0

/*
 * =====================================================================================
 * ================================= Generic Variables =================================
 * =====================================================================================
 */

void (* GP_IRQ_CallBack[3]) (void);

EXTI_GI_TypeDef* GP2EXTI_GI = EXTI_GI;
EXTI_MCU_TypeDef* GP2EXTI_MCU = EXTI_MCU;

/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

/**================================================================
* @Fn				- MCAL_EXTI_Init
* @brief			- This is used to configure and initialize a pin as EXTI.
* @param [in] 		- EXTI_Config: This is the configuration for EXTI.
* @retval 			- None.
* Note				- None.
*/

void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_Config)
{
	GPIO_PinConfig_t EXTI_pinConfig;
	EXTI_pinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	
	switch (EXTI_Config->EXTI_INTx)
	{
	case EXTI_INT_0:
		// Enable Interrupt.
		GP2EXTI_GI->_GICR.bit._INT0 = 1;
		
		// Configure INT pin as INPUT and Trigger Configuration.
		EXTI_pinConfig.GPIO_PinNumber = GPIO_PIN_2;
		MCAL_GPIO_Init(GPIOx_PORTD, &EXTI_pinConfig);
		
		// Trigger Configuration.
		GP2EXTI_MCU->_MCUCR.bit._ISC0x = EXTI_Config->EXTI_Trigger;
		
		// Set Call back function.
		GP_IRQ_CallBack[0] = EXTI_Config->P_IRQ_CallBack;
		break;
		
	case EXTI_INT_1:
		// Enable Interrupt.
		GP2EXTI_GI->_GICR.bit._INT1 = 1;
	
		// Configure INT pin as INPUT.
		EXTI_pinConfig.GPIO_PinNumber = GPIO_PIN_3;
		MCAL_GPIO_Init(GPIOx_PORTD, &EXTI_pinConfig);
		
		// Trigger Configuration.
		GP2EXTI_MCU->_MCUCR.bit._ISC1x = EXTI_Config->EXTI_Trigger;
		
		// Set Call back function.
		GP_IRQ_CallBack[1] = EXTI_Config->P_IRQ_CallBack;
		break;
		
	case EXTI_INT_2:
		// Enable Interrupt.
		GP2EXTI_GI->_GICR.bit._INT2 = 1;
	
		// Configure INT pin as INPUT.
		EXTI_pinConfig.GPIO_PinNumber = GPIO_PIN_2;
		MCAL_GPIO_Init(GPIOx_PORTB, &EXTI_pinConfig);
		
		// Trigger Configuration.
		GP2EXTI_MCU->_MCUCSR.bit._ISC2 = EXTI_Config->EXTI_Trigger & 1;
		
		// Set Call back function.
		GP_IRQ_CallBack[2] = EXTI_Config->P_IRQ_CallBack;
		break;
	}
	
	// Enable Global INT.
	Enable_Global_INT();
}


ISR(INT0_vect)
{
	if (NULL != GP_IRQ_CallBack[0])
	{
		GP_IRQ_CallBack[0]();
	}
}

ISR(INT1_vect)
{
	if (NULL != GP_IRQ_CallBack[1])
	{
		GP_IRQ_CallBack[1]();
	}
}

ISR(INT2_vect)
{
	if (NULL != GP_IRQ_CallBack[2])
	{
		GP_IRQ_CallBack[2]();
	}
}

