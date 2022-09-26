/*
 * LCD.c
 *
 * Created: 9/7/2022 11:04:44 PM
 *  Author: Ahmed
 */ 


// =============================================
// ================== Includes =================
// =============================================

#include "Utils.h"
#include <util/delay.h>
#include "Platform_Types.h"
#include "LCD.h"

/*
 * ===========================================================================
 * ================================= Generic Macros ==========================
 * ===========================================================================
 */

#define EN_DELAY_us	5 


/************** Commands **************/
#define CLEAR	0x01
#define HOME	0x02

/** entery mode **/
#define NO_SHIFT_DEC		0x04
#define NO_SHIFT_INC		0x06
#define SHIFT_LEFT			0x07
#define SHIFT_RIGHT			0x05

#define ENTRY_MODE			NO_SHIFT_INC

/** display on/off **/
#define DISPLAY_ON		0x0c
#define DISPLAY_OFF		0xFB

#define CURSOR_ON		0x0A
#define CURSOR_OFF		0xFD

#define BLINK_ON		0x09
#define BLINK_OFF		0x0E

#define DISPLAY_INIT	(DISPLAY_ON | CURSOR_ON | BLINK_OFF)

/** Cursor or Display Shift **/
#define MOVE_CURSOR_LEFT	0x10
#define MOVE_CURSOR_RIGHT	0x14
#define MOVE_DISPLAY_LEFT	0x18
#define MOVE_DISPLAY_RIGHT	0x1C


/** Function Set **/
#define _4BIT		0x20
#define _8BIT		0x30

#define _2LINE		0x28
#define _1LINE		0x20

#define _5x10DOTS	0x24
#define _5x8DOTS	0x20

#if (LCD_MODE == LCD_MODE_4BITS)

	#define FUNC_SET	(_4BIT | _2LINE | _5x8DOTS)
	
#elif (LCD_MODE == LCD_MODE_8BITS)

	#define FUNC_SET	(_8BIT | _2LINE | _5x8DOTS)
	
#endif

/** Positions */
#define FIRSTLINE	0x80
#define SECONDLINE	0xc0


/*
 * ========================================================================================
 * ================================= Generic Function Definition ==========================
 * ========================================================================================
 */

void LCD_sendCommand(LCD_Config_t *Config, uint8 command)
{
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_RSPin, GPIO_STATE_LOW);
	
	#if (LCD_MODE == LCD_MODE_4BITS)
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(command, 4));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(command, 5));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(command, 6));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(command, 7));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(command, 0));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(command, 1));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(command, 2));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(command, 3));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	#elif (LCD_MODE == LCD_MODE_8BITS)
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB0, READBIT(command, 0));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB1, READBIT(command, 1));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB2, READBIT(command, 2));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB3, READBIT(command, 3));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(command, 4));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(command, 5));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(command, 6));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(command, 7));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	#endif
	
	_delay_ms(3);
}

void LCD_sendData(LCD_Config_t *Config, uint8 byte)
{
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_RSPin, GPIO_STATE_HIGH);
	
	#if (LCD_MODE == LCD_MODE_4BITS)
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(byte, 4));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(byte, 5));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(byte, 6));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(byte, 7));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(byte, 0));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(byte, 1));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(byte, 2));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(byte, 3));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	#elif (LCD_MODE == LCD_MODE_8BITS)
	
	MCAL_GPIO_writePin(LCD_DATAPORT, DB0, READBIT(byte, 0));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB1, READBIT(byte, 1));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB2, READBIT(byte, 2));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB3, READBIT(byte, 3));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB4, READBIT(byte, 4));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB5, READBIT(byte, 5));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB6, READBIT(byte, 6));
	MCAL_GPIO_writePin(LCD_DATAPORT, DB7, READBIT(byte, 7));
	
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_HIGH);
	_delay_us(EN_DELAY_us);
	MCAL_GPIO_writePin(Config->LCD_ControlPort, Config->LCD_ENPin, GPIO_STATE_LOW);
	
	#endif
	
	_delay_ms(3);
}


/*
 * =====================================================================================
 * ================================= APIs Function Definition ==========================
 * =====================================================================================
 */

void HAL_LCD_Init(LCD_Config_t *Config)
{
	GPIO_PinConfig_t pin;
	
	pin.GPIO_PinNumber = Config->LCD_ENPin;
	pin.GPIO_PinMode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(Config->LCD_ControlPort, &pin);
	
	pin.GPIO_PinNumber = Config->LCD_RSPin;
	MCAL_GPIO_Init(Config->LCD_ControlPort, &pin);
	
	//pin.GPIO_PinNumber = Config-> RW;
	//MCAL_GPIO_Init(LCD_CTRLPORT, &pin);
	
	pin.GPIO_PinNumber = DB4;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB5;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB6;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB7;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	#if (LCD_MODE == LCD_MODE_8BITS)

	pin.GPIO_PinNumber = DB0;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB1;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB2;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);
	
	pin.GPIO_PinNumber = DB3;
	MCAL_GPIO_Init(LCD_DATAPORT, &pin);

	#elif (LCD_MODE == LCD_MODE_4BITS)
	
	LCD_sendCommand(Config, FUNC_SET>>4);
	
	#endif
	
	
	
	
	LCD_sendCommand(Config, FUNC_SET);
	LCD_sendCommand(Config, DISPLAY_INIT);
	LCD_sendCommand(Config, ENTRY_MODE);
	LCD_sendCommand(Config, CLEAR);
	
	//_delay_ms(50);
}

void HAL_LCD_Clear(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, CLEAR);
}

void HAL_LCD_Home(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, HOME);
}

void HAL_LCD_writeChar(LCD_Config_t *Config, uint8 data)
{
	LCD_sendData(Config, data);
}

void HAL_LCD_writeString(LCD_Config_t *Config, uint8 *ptr2string)
{
	while (*ptr2string != '\0')
	{
		LCD_sendData(Config, *ptr2string);
		ptr2string++;
	}
}

void HAL_LCD_GoXY(LCD_Config_t *Config, uint8 x, uint8 y)
{
	if (y == 0)
	{
		if(x < 16 && x >= 0)
		{
			LCD_sendCommand(Config, FIRSTLINE + x);
		}
	}
	else
	{
		if(x < 16 && x >= 0)
		{
			LCD_sendCommand(Config, SECONDLINE + x);
		}
	}
}


void HAL_LCD_autoShiftLeft(LCD_Config_t *Config) // autoscroll
{
	LCD_sendCommand(Config, SHIFT_LEFT);
}

void HAL_LCD_noAutoShiftLeft(LCD_Config_t *Config) // no autoscroll
{
	LCD_sendCommand(Config, NO_SHIFT_INC);
}

void HAL_LCD_autoShiftRight(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, SHIFT_RIGHT);
}

void HAL_LCD_noAutoShiftRight(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, SHIFT_LEFT);
}

void HAL_LCD_writeLeftToRight(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, NO_SHIFT_INC);
}

void HAL_LCD_writeRightToLeft(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, NO_SHIFT_DEC);
}

void HAL_LCD_displayOn(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, DISPLAY_INIT);
}

void HAL_LCD_displayOff(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, (DISPLAY_INIT) & DISPLAY_OFF);
}

void HAL_LCD_cursorOn(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, DISPLAY_INIT);
}

void HAL_LCD_cursorOff(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, (DISPLAY_INIT) & CURSOR_OFF);
}

void HAL_LCD_blinkOn(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, DISPLAY_INIT | BLINK_ON);
}

void HAL_LCD_blinkOff(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, DISPLAY_INIT);
}

void HAL_LCD_moveCursorLeft(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, MOVE_CURSOR_LEFT);
}

void HAL_LCD_moveCursorRight(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, MOVE_CURSOR_RIGHT);
}

void HAL_LCD_moveDisplayLeft(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, MOVE_DISPLAY_LEFT);
}


void HAL_LCD_moveDisplayRight(LCD_Config_t *Config)
{
	LCD_sendCommand(Config, MOVE_DISPLAY_RIGHT);
}





