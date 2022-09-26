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

//typedef struct  
//{
	//
//};

// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

#define COLS_PORT			GPIOx_PORTC
#define COLS_NUMBER			4
#define COL0				GPIO_PIN_4
#define COL1				GPIO_PIN_5
#define COL2				GPIO_PIN_6
#define COL3				GPIO_PIN_7

#define ROWS_PORT			GPIOx_PORTC
#define ROWS_NUMBER			4
#define ROW0				GPIO_PIN_0
#define ROW1				GPIO_PIN_1
#define ROW2				GPIO_PIN_2
#define ROW3				GPIO_PIN_3


// ===================================================
// ================== APIs Functions =================
// ===================================================
void HAL_keypad_Init(void);
uint8 HAL_keypad_getKey(void);



#endif /* KEYPAD_H_ */