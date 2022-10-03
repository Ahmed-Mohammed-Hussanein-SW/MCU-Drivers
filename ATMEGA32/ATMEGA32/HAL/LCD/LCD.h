/*
 * LCD.h
 *
 * Created: 9/7/2022 11:04:53 PM
 *  Author: Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "atmega32_GPIO_Driver.h"



// ==========================================================
// ================== User Type Definitions =================
// ==========================================================

typedef struct
{
	GPIO_TypeDef *LCD_ControlPort;		// This specifies the port contains the control pins of lcd.
									   //  This parameter must be a value of @ref LCD_CTRLPORT_define.
									
	uint8 LCD_RSPin;				// This specifies the control pin RS of lcd.
								   //  This parameter must be a value of @ref LCD_RS_PIN_define.
								   
	uint8 LCD_ENPin;				// This specifies the control pin EN of lcd.
								   //  This parameter must be a value of @ref LCD_EN_PIN_define.

} LCD_Config_t;

/* This specifies the data pins of LCD and port of this pins. */
#define LCD_DATAPORT	LCD_DATAPORT_A // This parameter must be a value of @ref LCD_DATAPORT_define.

// This parameter must be a value of @ref LCD_DB_define.
// The following four pins must be defined if the lcd configured in 8 bit mode
#define DB0				LCD_DB_0
#define DB1				LCD_DB_1
#define DB2				LCD_DB_2
#define DB3				LCD_DB_3

#define DB4				LCD_DB_4
#define DB5				LCD_DB_5
#define DB6				LCD_DB_6
#define DB7				LCD_DB_7

/* This specifies the data pins of LCD and port of this pins. */
#define LCD_MODE		LCD_MODE_4BITS	// This parameter must be a value of @ref LCD_MODE_define.

// ===================================================================
// ================== Macros Configuration Reference =================
// ===================================================================

// @ref LCD_CTRLPORT_define.
#define LCD_CTRLPORT_A		GPIOx_PORTA
#define LCD_CTRLPORT_B		GPIOx_PORTB
#define LCD_CTRLPORT_C		GPIOx_PORTC
#define LCD_CTRLPORT_D		GPIOx_PORTD

// @ref LCD_RS_PIN_define.
#define LCD_RS_PIN_0		GPIO_PIN_0
#define LCD_RS_PIN_1		GPIO_PIN_1
#define LCD_RS_PIN_2		GPIO_PIN_2
#define LCD_RS_PIN_3		GPIO_PIN_3
#define LCD_RS_PIN_4		GPIO_PIN_4
#define LCD_RS_PIN_5		GPIO_PIN_5
#define LCD_RS_PIN_6		GPIO_PIN_6
#define LCD_RS_PIN_7		GPIO_PIN_7

// @ref LCD_EN_PIN_define.
#define LCD_EN_PIN_0		GPIO_PIN_0
#define LCD_EN_PIN_1		GPIO_PIN_1
#define LCD_EN_PIN_2		GPIO_PIN_2
#define LCD_EN_PIN_3		GPIO_PIN_3
#define LCD_EN_PIN_4		GPIO_PIN_4
#define LCD_EN_PIN_5		GPIO_PIN_5
#define LCD_EN_PIN_6		GPIO_PIN_6
#define LCD_EN_PIN_7		GPIO_PIN_7

// @ref LCD_DATAPORT_define.
#define LCD_DATAPORT_A		GPIOx_PORTA
#define LCD_DATAPORT_B		GPIOx_PORTB
#define LCD_DATAPORT_C		GPIOx_PORTC
#define LCD_DATAPORT_D		GPIOx_PORTD

// @ref LCD_DB_define.
#define LCD_DB_0			GPIO_PIN_0
#define LCD_DB_1			GPIO_PIN_1
#define LCD_DB_2			GPIO_PIN_2
#define LCD_DB_3			GPIO_PIN_3
#define LCD_DB_4			GPIO_PIN_4
#define LCD_DB_5			GPIO_PIN_5
#define LCD_DB_6			GPIO_PIN_6
#define LCD_DB_7			GPIO_PIN_7

// @ref LCD_MODE_define.
#define LCD_MODE_4BITS		0
#define LCD_MODE_8BITS		1



// ===================================================
// ================== APIs Functions =================
// ===================================================
void HAL_LCD_Init(LCD_Config_t *Config);

void HAL_LCD_Clear(LCD_Config_t *Config);
void HAL_LCD_Home(LCD_Config_t *Config);

void HAL_LCD_writeChar(LCD_Config_t *Config, uint8 data);
void HAL_LCD_writeString(LCD_Config_t *Config, uint8 *ptr2string);
void HAL_LCD_GoXY(LCD_Config_t *Config, uint8 x, uint8 y);

void HAL_LCD_autoShiftLeft(LCD_Config_t *Config);
void HAL_LCD_noAutoShiftLeft(LCD_Config_t *Config);

void HAL_LCD_autoShiftRight(LCD_Config_t *Config);
void HAL_LCD_noAutoShiftRight(LCD_Config_t *Config);

void HAL_LCD_writeLeftToRight(LCD_Config_t *Config);
void HAL_LCD_writeRightToLeft(LCD_Config_t *Config);

void HAL_LCD_displayOn(LCD_Config_t *Config);
void HAL_LCD_displayOff(LCD_Config_t *Config);

void HAL_LCD_cursorOn(LCD_Config_t *Config);
void HAL_LCD_cursorOff(LCD_Config_t *Config);

void HAL_LCD_blinkOn(LCD_Config_t *Config);
void HAL_LCD_blinkOff(LCD_Config_t *Config);

void HAL_LCD_moveCursorLeft(LCD_Config_t *Config);
void HAL_LCD_moveCursorRight(LCD_Config_t *Config);

void HAL_LCD_moveDisplayLeft(LCD_Config_t *Config);
void HAL_LCD_moveDisplayRight(LCD_Config_t *Config);



void LCD_sendCommand(LCD_Config_t *Config, uint8 command);
#endif /* LCD_H_ */