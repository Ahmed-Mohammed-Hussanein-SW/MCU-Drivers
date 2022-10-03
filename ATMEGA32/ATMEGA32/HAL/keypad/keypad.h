/*
 * Keypad.h
 *
 * Created: 9/8/2022 1:05:53 AM
 *  Author: Ahmed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"

// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

typedef struct  
{
	uint8 colsNumber;		// This specifies the number of columns of the keypad.
						   //  This parameter must be a positive number.
						   
	uint8 *colsPins;		// This specifies the columns pins of the keypad.
						   //  This parameter must be a value of @ref COLS_PIN_define.
							   
	uint8 rowsNumber;		// This specifies the number of columns of the keypad.
						   //  This parameter must be a positive number.
						   
	uint8 *rowsPins;		// This specifies the columns pins of the keypad.
						   //  This parameter must be a value of @ref ROWS_PIN_define.
							   
	uint8 (*keys)[];			// This is used to set the symbols of the key.

} keypad_Config_t;



#define COLS_PORT			COLS_PORT_A		// This specifies the port of the columns of the keypad.
										   //  This parameter must be a value of @ref COLS_PORT_define.

#define ROWS_PORT			ROWS_PORT_A		// This specifies the port of the columns of the keypad.
										   //  This parameter must be a value of @ref ROWS_PORT_define.


// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref COLS_PIN_define.
#define COLS_PIN_0			GPIO_PIN_0
#define COLS_PIN_1			GPIO_PIN_1
#define COLS_PIN_2			GPIO_PIN_2
#define COLS_PIN_3			GPIO_PIN_3
#define COLS_PIN_4			GPIO_PIN_4
#define COLS_PIN_5			GPIO_PIN_5
#define COLS_PIN_6			GPIO_PIN_6
#define COLS_PIN_7			GPIO_PIN_7


// @ref ROWS_PIN_define.
#define ROWS_PIN_0			GPIO_PIN_0
#define ROWS_PIN_1			GPIO_PIN_1
#define ROWS_PIN_2			GPIO_PIN_2
#define ROWS_PIN_3			GPIO_PIN_3
#define ROWS_PIN_4			GPIO_PIN_4
#define ROWS_PIN_5			GPIO_PIN_5
#define ROWS_PIN_6			GPIO_PIN_6
#define ROWS_PIN_7			GPIO_PIN_7

// @ref COLS_PORT_define.
#define COLS_PORT_A			GPIOx_PORTA
#define COLS_PORT_B			GPIOx_PORTB
#define COLS_PORT_C			GPIOx_PORTC
#define COLS_PORT_D			GPIOx_PORTD

// @ref ROWS_PORT_define.
#define ROWS_PORT_A			GPIOx_PORTA
#define ROWS_PORT_B			GPIOx_PORTB
#define ROWS_PORT_C			GPIOx_PORTC
#define ROWS_PORT_D			GPIOx_PORTD

//#define COLS_PORT			GPIOx_PORTC
//#define COLS_NUMBER			4
//#define COL0				GPIO_PIN_4
//#define COL1				GPIO_PIN_5
//#define COL2				GPIO_PIN_6
//#define COL3				GPIO_PIN_7
//
//#define ROWS_PORT			GPIOx_PORTC
//#define ROWS_NUMBER			4
//#define ROW0				GPIO_PIN_0
//#define ROW1				GPIO_PIN_1
//#define ROW2				GPIO_PIN_2
//#define ROW3				GPIO_PIN_3


// ===================================================
// ================== APIs Functions =================
// ===================================================
void HAL_keypad_Init(keypad_Config_t *Config);
uint8 HAL_keypad_getKey(void);



#endif /* KEYPAD_H_ */