/*
 * ATMEGA32.c
 *
 * Created: 9/17/2022 10:59:10 PM
 *  Author: Ahmed
 */ 

#define ENTER  0x0D

#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

#define NULL (void)0

#include "Platform_Types.h"

#include "atmega32_GPIO_Driver.h"
#include "atmega32_EXTI_Driver.h"
#include "atmega32_USART_Driver.h"
#include "LCD.h"
#include "keypad.h"


//void INT0_IRQ()
//{
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_5, GPIO_STATE_HIGH);
	//_delay_ms(1000);
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_5, GPIO_STATE_LOW);
	//_delay_ms(1000);
//}
//
//void INT1_IRQ()
//{
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_6, GPIO_STATE_HIGH);
	//_delay_ms(1000);
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_6, GPIO_STATE_LOW);
	//_delay_ms(1000);
//}
//
//void INT2_IRQ()
//{
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_7, GPIO_STATE_HIGH);
	//_delay_ms(1000);
	//MCAL_GPIO_writePin(GPIOx_PORTD, GPIO_PIN_7, GPIO_STATE_LOW);
	//_delay_ms(1000);
//}

int main(void)
{
	//GPIO_PinConfig_t pin;
	//pin.GPIO_PinMode = GPIO_MODE_OUTPUT;
	//pin.GPIO_PinNumber = GPIO_PIN_5;
	//
	//MCAL_GPIO_Init(GPIOx_PORTD, &pin);
	//
	//pin.GPIO_PinNumber = GPIO_PIN_6;
	//MCAL_GPIO_Init(GPIOx_PORTD, &pin);
	//
	//pin.GPIO_PinNumber = GPIO_PIN_7;
	//MCAL_GPIO_Init(GPIOx_PORTD, &pin);
	//
	//EXTI_PinConfig_t int0;
	//
	//int0.EXTI_INTx = EXTI_INT_0;
	//int0.EXTI_Trigger = EXTI_TRIGGER_ANY;
	//int0.P_IRQ_CallBack = INT0_IRQ;
	//MCAL_EXTI_Init(&int0);
	//
	//int0.EXTI_INTx = EXTI_INT_1;
	//int0.EXTI_Trigger = EXTI_TRIGGER_RISING;
	//int0.P_IRQ_CallBack = INT1_IRQ;
	//MCAL_EXTI_Init(&int0);
	//
	//int0.EXTI_INTx = EXTI_INT_2;
	//int0.EXTI_Trigger = EXTI_TRIGGER_FALLING;
	//int0.P_IRQ_CallBack = INT2_IRQ;
	//MCAL_EXTI_Init(&int0);
	
	LCD_Config_t lcd;
	lcd.LCD_ControlPort = LCD_CTRLPORT_A;
	lcd.LCD_ENPin		= LCD_EN_PIN_0;
	lcd.LCD_RSPin		= LCD_RS_PIN_1;
	
	HAL_LCD_Init(&lcd);
	
	
	
	
	USART_Config_t usrt;
	usrt.baudRate			= 51;
	usrt.characterSize		= USART_CHARSIZE_8;
	usrt.clockPolarity		= USART_PLORITY_FALLING;
	usrt.communicationMode	= USART_MODE_SYNC_MASETER;
	usrt.parityMode			= USART_PARITYMODE_EVEN;
	usrt.stopBit			= USART_STOPBIT_2;
	
	MCAL_USART_Init(&usrt);
	
	GPIO_PinConfig_t pin;
	pin.GPIO_PinMode = GPIO_MODE_INPUT;
	pin.GPIO_PinNumber = GPIO_PIN_0;
	
	MCAL_GPIO_Init(GPIOx_PORTB, &pin);
	
	uint16 data;
	
    while(1)
    {
        //TODO:: Please write your application code
		data = MCAL_USART_receiveData();
		
		HAL_LCD_writeChar(&lcd, data);
		HAL_LCD_writeChar(&lcd, data>>8);
		
    }
}