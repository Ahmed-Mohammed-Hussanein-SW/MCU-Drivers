/*
 * atmega32_GPIO_Driver.h
 *
 * Created: 9/18/2022 12:01:49 AM
 *  Author: Ahmed
 */ 


#ifndef ATMEGA32_GPIO_DRIVER_H_
#define ATMEGA32_GPIO_DRIVER_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "Utils.h"

#include "atmega32_device_header.h"


// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

typedef struct
{
	uint8 GPIO_PinNumber;	 // This specifies which pin in GPIO to be configured.
							//	This parameter must be a value of @ref GPIO_PIN_define.
							
	uint8 GPIO_PinMode;	 // This specifies what the mode of GPIO pin is.
							//  This parameter must be a value of @ref GPIO_MODE_define.
	
}	GPIO_PinConfig_t;


// ===================================================================
// ================== Macros Configuration Reference =================
// =================================================================== 

// @ref GPIO_PIN_define
// GPIO_MASK_CONFIG is used to configure more than one pin at the same time but must be at the same port.
// You can write your configuration as following:
// 0b PIN7 PIN6 PIN5 PIN4 PIN3 PIN2 PIN1 PIN0
//#define GPIOA_MASK_GONFIG	(uint8_t) (0b11111111)
#define GPIO_PIN_0			(uint8) (0x01)
#define GPIO_PIN_1			(uint8) (0x02)
#define GPIO_PIN_2			(uint8) (0x04)
#define GPIO_PIN_3			(uint8) (0x08)
#define GPIO_PIN_4			(uint8) (0x10)
#define GPIO_PIN_5			(uint8) (0x20)
#define GPIO_PIN_6			(uint8) (0x40)
#define GPIO_PIN_7			(uint8) (0x80)

// @ref GPIO_MODE_define
#define GPIO_MODE_INPUT			   0
#define GPIO_MODE_OUTPUT		   1
#define GPIO_MODE_INPUT_PUR		   2

// @ref GPIOx_define
#define GPIOx_PORTA				   GPIOA
#define GPIOx_PORTB				   GPIOB
#define GPIOx_PORTC				   GPIOC
#define GPIOx_PORTD				   GPIOD

/* This specifies the output and input states */
// @ref GPIO_STATE_define
#define GPIO_STATE_LOW				0
#define GPIO_STATE_HIGH				1

// ===================================================
// ================== APIs Functions =================
// =================================================== 
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);

void MCAL_GPIO_writePin(GPIO_TypeDef *GPIOx, uint8 PinNumber, uint8 value);
void MCAL_GPIO_writePort(GPIO_TypeDef *GPIOx, uint8 value);

uint8 MCAL_GPIO_readPin(GPIO_TypeDef *GPIOx, uint8 PinNumber);
uint8 MCAL_GPIO_readPort(GPIO_TypeDef *GPIOx);

void MCAL_GPIO_togglePin(GPIO_TypeDef *GPIOx, uint8 PinNumber);
void MCAL_GPIO_togglePort(GPIO_TypeDef *GPIOx);


#endif /* ATMEGA32_GPIO_DRIVER_H_ */