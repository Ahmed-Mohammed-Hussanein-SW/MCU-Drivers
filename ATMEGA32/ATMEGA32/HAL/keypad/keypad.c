/*
 * Keypad.c
 *
 * Created: 9/8/2022 1:06:06 AM
 *  Author: Ahmed
 */ 

// =============================================
// ================== Includes =================
// =============================================

#include "keypad.h"
#include "Platform_Types.h"

#include "atmega32_GPIO_Driver.h"



/*
 * ===========================================================================
 * ================================= Generic Macros ==========================
 * ===========================================================================
 */



/*
 * ==============================================================================
 * ================================= Generic Variables ==========================
 * ==============================================================================
 */

uint8 gcolsNumber;
uint8 growsNumber;

uint8 *gP2colsPins;
uint8 *gP2rowsPins;

uint8 (*gP2keys)[];

/*
 * ========================================================================================
 * ================================= Generic Function Definition ==========================
 * ========================================================================================
 */




/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

//uint8 cols[COLS_NUMBER] = {COL0, COL1, COL2, COL3};
//uint8 rows[ROWS_NUMBER] = {ROW0, ROW1, ROW2, ROW3};
//
//
//uint8 keys[ROWS_NUMBER][COLS_NUMBER] =
		//{
			//{'7', '8', '9', '/',},
			//{'4', '5', '6', '*',},
			//{'1', '2', '3', '-',},
			//{'?', '0', '=', '+'}
		//};


void HAL_keypad_Init(keypad_Config_t *Config)
{
	uint8 i;
	GPIO_PinConfig_t pin;
	
	// set keypad dimension.
	gcolsNumber = Config->colsNumber;
	growsNumber = Config->rowsNumber;
	
	// set keypad pins.
	gP2colsPins = Config->colsPins;
	gP2rowsPins = Config->rowsPins;
	
	// set keypad symbols.
	gP2keys = Config->keys;
	
	pin.GPIO_PinMode = GPIO_MODE_OUTPUT;
	for (i = 0; i < gcolsNumber; ++i)
	{
		pin.GPIO_PinNumber = gP2colsPins[i];
		MCAL_GPIO_Init(COLS_PORT, &pin);
	}
	
	pin.GPIO_PinMode = GPIO_MODE_INPUT_PUR;
	for (i = 0; i < growsNumber; ++i)
	{
		pin.GPIO_PinNumber = gP2rowsPins[i];
		MCAL_GPIO_Init(ROWS_PORT, &pin);
	}
	
}
 
 uint8 HAL_keypad_getKey(void)
 {
	 uint8 i, j;
	 
	 for (i = 0; i < gcolsNumber; ++i)
	 {
		 
		 for (j = 0; j < gcolsNumber; ++j)
		 {
			 
			 if(j == i)
			 {
				 MCAL_GPIO_writePin(COLS_PORT, gP2colsPins[j], GPIO_STATE_LOW);
			 }
			 else
			 {
				 MCAL_GPIO_writePin(COLS_PORT, gP2colsPins[j], GPIO_STATE_HIGH);
			 }
		 }
		 
		 for (j = 0; j < growsNumber; ++j)
		 {
			 if (MCAL_GPIO_readPin(ROWS_PORT, gP2rowsPins[j]) == 0)
			 {
				 while (MCAL_GPIO_readPin(ROWS_PORT, gP2rowsPins[j]) == 0);
				 //return keys[j][i];
				 return *(*gP2keys + gcolsNumber * j + i);
			 }
		 }
	 }
	 
	 return '\0';
 }
 
