/*
 * ATMEGA32.c
 *
 * Created: 9/17/2022 10:59:10 PM
 *  Author: Ahmed
 */ 

#define F_CPU 1000000UL
#include <util/delay.h>

#define NULL (void)0

#include "Platform_Types.h"

#include "atmega32_GPIO_Driver.h"
#include "atmega32_SPI_Driver.h"
#include "LCD.h"
#include "keypad.h"

#define MASTER  1
#define SLAVE	0

#define MCU     SLAVE

int main(void)
{		
	SPI_Config_t mySPI;
	mySPI.SPI_DataOrder = SPI_DATA_ORDER_LSB;
	mySPI.SPI_ClockPolarityPhase = SPI_CLOCK_POLARITY_PHASE_HIGH_FIRST;
	mySPI.SPI_ClockRate = SPI_CLOCK_RATE_DIV_2;
	mySPI.SPI_INT_EN = SPI_INT_DISABLE;
	//mySPI.ptr2IRQ_CallBack = NULL;
	
	#if (MCU == MASTER)
	
	mySPI.SPI_MasterSlaveSelect = SPI_MCU_MODE_MASTER;
	
	uint8 key;
	HAL_keypad_Init();
	
	#endif
	
	#if (MCU == SLAVE)
	
	mySPI.SPI_MasterSlaveSelect = SPI_MCU_MODE_SLAVE;
	
	LCD_Config_t myLCD;
	myLCD.LCD_ControlPort = GPIOx_PORTC;
	myLCD.LCD_ENPin = LCD_EN_PIN_1;
	myLCD.LCD_RSPin = LCD_RS_PIN_0;
	HAL_LCD_Init(&myLCD);
	
	#endif
	
	MCAL_SPI_Init(&mySPI);
	
    while(1)
    {
        //TODO:: Please write your application code
		
		#if (MCU == MASTER)

		key = HAL_keypad_getKey();
		
		if (key != '\0')
		{
			MCAL_SPI_Tx(key);
		}
		
		#endif
		
		
		#if (MCU == SLAVE)
		
		HAL_LCD_writeChar(&myLCD, MCAL_SPI_Rx());
		
		#endif
    }
}