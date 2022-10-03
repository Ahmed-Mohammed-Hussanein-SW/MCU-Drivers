/*
 * atmega32_EXTI_Driver.h
 *
 * Created: 9/28/2022 4:10:00 PM
 *  Author: Ahmed
 */ 


#ifndef ATMEGA32_EXTI_DRIVER_H_
#define ATMEGA32_EXTI_DRIVER_H_


// =============================================
// ================== Includes =================
// =============================================

#include <avr/interrupt.h>

#include "Platform_Types.h"
#include "Utils.h"

#include "atmega32_device_header.h"


// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

// INT0 --> PD2 
// INT1 -->	PD3
// INT2 --> PB2

typedef struct
{
	uint8 EXTI_INTx;		 // This specifies which INT to be configured.
							//	This parameter must be a value of @ref EXTI_INT_define.
	
	uint8 EXTI_Trigger;	 // This specifies the trigger of the interrupt.
						//  This parameter must be a value of @ref EXTI_TRIGGER_define.
						
	void (* P_IRQ_CallBack) (void);  // set call back function.
	
}	EXTI_PinConfig_t;


// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref EXTI_INT_define.
#define EXTI_INT_0					0
#define EXTI_INT_1					1
#define EXTI_INT_2					2

// @ref EXTI_TRIGGER_define.
// Note only INT2 has Falling or Rising Trigger only.
#define EXTI_TRIGGER_LOWLEVEL		0
#define EXTI_TRIGGER_ANY			1
#define EXTI_TRIGGER_FALLING		2
#define EXTI_TRIGGER_RISING			3


// ===================================================
// ================== APIs Functions =================
// ===================================================
void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_Config);

void MCAL_EXTI_Update(EXTI_PinConfig_t *EXTI_Config);




#endif /* ATMEGA32_EXTI_DRIVER_H_ */