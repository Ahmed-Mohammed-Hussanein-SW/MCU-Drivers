/*
 * MAX7221.h
 *
 * Created: 9/23/2022 9:55:16 AM
 *  Author: Ahmed
 */ 


#ifndef MAX7221_H_
#define MAX7221_H_

// =============================================
// ================== Includes =================
// =============================================

#include "Platform_Types.h"
#include "atmega32_GPIO_Driver.h"
#include "atmega32_SPI_Driver.h"

// ==========================================================
// ================== User Type Definitions =================
// ==========================================================
typedef struct
{
	uint8 decodeModeRegister;		// This specifies the display is working in BCD font B decode mode or no decode
								   //  This must be a value of @ref MAX7221_DECODE_define.
	
	uint8 intensityRegister;	  // This specifies the display brightness.
								 //  This must be a value of @ref MAX7221_INTENSITY_define.
	
	uint8 scanLimitRegister;	// This specifies the number of digits to be displayed.
							   //  This must be a value of @ref MAX7221_SCANLIMIT_define.
	
	uint8 shutDownRegister;		// This specifies the display to be turned on/off.
							   //  This must be a value of @ref MAX7221_define.
	
	uint8 displayTestRegister;
	
} MAX7221_Config_t;

// =========================================================
// ================== Register Address Map =================
// =========================================================
#define NO_OP				0x00
#define DIGIT0				0x01
#define DIGIT1				0x02
#define DIGIT2				0x03
#define DIGIT3				0x04
#define DIGIT4				0x05
#define DIGIT5				0x06
#define DIGIT6				0x07
#define DIGIT7				0x08
#define DECODE_MODE			0x09
#define INTENSITY			0x0A
#define SCAN_LIMIT			0x0B
#define SHUTDOWN			0x0C
#define DISPLAY_TEST		0x0F

// @ref MAX7221_define.
#define MAX7221_SHUTDOWN_MODE		0x00
#define MAX7221_NORMAL_MODE			0x01


// @ref MAX7221_DECODE_define.
#define MAX7221_DECODE_NOT					0x00
#define MAX7221_DECODE_DIGIT0				0x01
#define MAX7221_DECODE_DIGIT0_3				0x0F
#define MAX7221_DECODE_DIGIT0_7				0xFF

// ================================================
// ================== Code B Font =================
// ================================================
#define ZERO						0x00
#define ONE						0x01
#define TWO						0x02
#define THREE					0x03
#define FOUR						0x04
#define FIVE					0x05
#define SIX					0x06
#define SEVEN					0x07
#define EGHIT					0x08
#define NINE						0x09
#define LINE					0x0A
#define E						0x0B
#define H						0x0C
#define L						0x0D
#define P						0x0E
#define BLANK					0x0F

#define ZERO_NO_DECODE					0x7E
#define ONE_NO_DECODE					0x30
#define TWO_NO_DECODE					0x6D
#define THREE_NO_DECODE					0x79
#define FOUR_NO_DECODE					0x33
#define FIVE_NO_DECODE					0x5B
#define SIX_NO_DECODE					0x5F
#define SEVEN_NO_DECODE					0x70
#define EGHIT_NO_DECODE					0x7F
#define NINE_NO_DECODE					0x7B
#define LINE_NO_DECODE					0x01
#define E_NO_DECODE						0x4F
#define H_NO_DECODE						0x37
#define L_NO_DECODE						0x0E
#define P_NO_DECODE						0x67
#define BLANK_NO_DECODE					0x00

#define DP_On							0x80
#define DP_Off							0x7F

// @ref MAX7221_INTENSITY_define.
#define MAX7221_INTENSITY_1_16							0x00
#define MAX7221_INTENSITY_2_16							0x01
#define MAX7221_INTENSITY_3_16							0x02
#define MAX7221_INTENSITY_4_16							0x03
#define MAX7221_INTENSITY_5_16							0x04
#define MAX7221_INTENSITY_6_16							0x05
#define MAX7221_INTENSITY_7_16							0x06
#define MAX7221_INTENSITY_8_16							0x07
#define MAX7221_INTENSITY_9_16							0x08
#define MAX7221_INTENSITY_10_16							0x0A
#define MAX7221_INTENSITY_11_16							0x0B
#define MAX7221_INTENSITY_12_16							0x0C
#define MAX7221_INTENSITY_13_16							0x0D
#define MAX7221_INTENSITY_14_16							0x0E
#define MAX7221_INTENSITY_15_16							0x0F

// @ref MAX7221_SCANLIMIT_define.
#define MAX7221_SCANLIMIT_DIGIT0						0x00
#define MAX7221_SCANLIMIT_DIGIT0_1						0x01
#define MAX7221_SCANLIMIT_DIGIT0_2						0x02
#define MAX7221_SCANLIMIT_DIGIT0_3						0x03
#define MAX7221_SCANLIMIT_DIGIT0_4						0x04
#define MAX7221_SCANLIMIT_DIGIT0_5						0x05
#define MAX7221_SCANLIMIT_DIGIT0_6						0x06
#define MAX7221_SCANLIMIT_DIGIT0_7						0x07


// ==========================================================
// ================== Display-Test Register =================
// ==========================================================
#define NORMAL_OPREATION				0x00
#define TEST_MODE						0x01




#endif /* MAX7221_H_ */