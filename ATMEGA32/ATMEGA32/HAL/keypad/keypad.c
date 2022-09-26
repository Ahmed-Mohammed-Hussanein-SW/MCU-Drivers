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
 * ========================================================================================
 * ================================= Generic Function Definition ==========================
 * ========================================================================================
 */




/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

uint8 cols[COLS_NUMBER] = {COL0, COL1, COL2, COL3};
uint8 rows[ROWS_NUMBER] = {ROW0, ROW1, ROW2, ROW3};


uint8 keys[ROWS_NUMBER][COLS_NUMBER] =
		{
			{'7', '8', '9', '/',},
			{'4', '5', '6', '*',},
			{'1', '2', '3', '-',},
			{'?', '0', '=', '+'}
		};


void HAL_keypad_Init(void)
{
	uint8 i;
	GPIO_PinConfig_t pin;
	
	pin.GPIO_PinMode = GPIO_MODE_OUTPUT;
	for (i = 0; i < COLS_NUMBER; ++i)
	{
		pin.GPIO_PinNumber = cols[i];
		MCAL_GPIO_Init(COLS_PORT, &pin);
	}
	
	pin.GPIO_PinMode = GPIO_MODE_INPUT_PUR;
	for (i = 0; i < ROWS_NUMBER; ++i)
	{
		pin.GPIO_PinNumber = rows[i];
		MCAL_GPIO_Init(ROWS_PORT, &pin);
	}
	
}

/*
uint8_t Keypad_getkey(void)
{
	char col0Val=0,col1Val=0,col2Val=0,col3Val=0;
	char i;
	char KBD_value=255;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0 :
			col0Val=1;
			col1Val=0;
			col2Val=0;
			col3Val=0;
			break;
			
			case 1 :
			col0Val=0;
			col1Val=1;
			col2Val=0;
			col3Val=0;
			break;
			
			case 2 :
			col0Val=0;
			col1Val=0;
			col2Val=1;
			col3Val=0;
			break;
			
			case 3 :
			col0Val=0;
			col1Val=0;
			col2Val=0;
			col3Val=1;
			break;
			
			default:
			break;
		}
		DIO_writePin(COL0,col0Val);
		DIO_writePin(COL1,col1Val);
		DIO_writePin(COL2,col2Val);
		DIO_writePin(COL3,col3Val);
		
		if(DIO_readPin(ROW0)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value = '7';
				break;
				case 1:
				KBD_value = '8';
				break;
				case 2:
				KBD_value = '9';
				break;
				case 3:
				KBD_value = '-';
				break;
				default:
				
				break;
			}
		}
		else if (DIO_readPin(ROW1)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value = '4';
				break;
				case 1:
				KBD_value = '5';
				break;
				case 2:
				KBD_value = '6';
				break;
				case 3:
				KBD_value = '*';
				break;
				default:
				
				break;
			}
		}
		else if (DIO_readPin(ROW2)==1)
		{
			switch(i)
			{
				case 0:
				KBD_value = '1';
				break;
				case 1:
				KBD_value = '2';
				break;
				case 2:
				KBD_value = '3';
				break;
				case 3:
				KBD_value = '/';
				break;
				default:
				
				break;
			}
		}
		else
		{
			switch(i)
			{
				case 0:
				KBD_value = '?';
				break;
				case 1:
				KBD_value = '0';
				break;
				case 2:
				KBD_value = '=';
				break;
				case 3:
				KBD_value = '+';
				break;
				default:
				
				break;
			}
		}
	}
	
	return KBD_value;
}

*/


/*
uint8_t Keypad_getkey(void)
{
	uint8_t i, j;
	
	for (i = 0; i<COLS_NUMBER; ++i)
	{
		switch(i)
		{
			case 0:
			DIO_writePin(cols[0], LOW);
			DIO_writePin(cols[1], HIGH);
			DIO_writePin(cols[2], HIGH);
			DIO_writePin(cols[3], HIGH);
			break;
			
			case 1:
			DIO_writePin(cols[0], HIGH);
			DIO_writePin(cols[1], LOW);
			DIO_writePin(cols[2], HIGH);
			DIO_writePin(cols[3], HIGH);
			break;
			
			case 2:
			DIO_writePin(cols[0], HIGH);
			DIO_writePin(cols[1], HIGH);
			DIO_writePin(cols[2], LOW);
			DIO_writePin(cols[3], HIGH);
			break;
			
			case 3:
			DIO_writePin(cols[0], HIGH);
			DIO_writePin(cols[1], HIGH);
			DIO_writePin(cols[2], HIGH);
			DIO_writePin(cols[3], LOW);
			break;
		}
		
		for (j = 0; j<ROWS_NUMBER; ++j)
		{
			if (DIO_readPin(rows[j]) == 0)
			{
				while (DIO_readPin(rows[j]) == 0);
				//DIO_writePin(cols[i], HIGH);
				return keys[j][i];
			}
		}
	}
	
	return '\0';
}

*/



 
 uint8 HAL_keypad_getKey(void)
 {
	 uint8 i, j;
	 
	 for (i = 0; i<COLS_NUMBER; ++i)
	 {
		 //DIO_writePin(cols[i], LOW);
		 
		 for (j = 0; j<COLS_NUMBER; ++j)
		 {
			 
			 if(j == i)
			 {
				 MCAL_GPIO_writePin(COLS_PORT, cols[j], GPIO_STATE_LOW);
			 }
			 else
			 {
				 MCAL_GPIO_writePin(COLS_PORT, cols[j], GPIO_STATE_HIGH);
			 }
		 }
		 
		 for (j = 0; j<ROWS_NUMBER; ++j)
		 {
			 if (MCAL_GPIO_readPin(ROWS_PORT, rows[j]) == 0)
			 {
				 while (MCAL_GPIO_readPin(ROWS_PORT, rows[j]) == 0);
				 //DIO_writePin(cols[i], HIGH);
				 return keys[j][i];
			 }
		 }
		 
		 //DIO_writePin(cols[i], HIGH);
	 }
	 
	 return '\0';
 }
 
