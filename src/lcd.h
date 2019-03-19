//*****************************************************************************
//
// File Name	: 'lcd_lib.h'
// Title		: 4-bit LCd interface
// Author		: Ahmed Osama
// Date			: Mar 13 2019
// Target MCU	: STM32F10xx
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************
#ifndef LCD_H_
#define LCD_H_

#include <inttypes.h>

#define LCD_RS_PIN	3 	//define MCU pin connected to LCD RS
#define LCD_RS_PORT	GPIOA

#define LCD_RW_PIN	4 	//define MCU pin connected to LCD R/W
#define LCD_RW_PORT	GPIOA

#define LCD_EN_PIN	5	//define MCU pin connected to LCD E
#define LCD_EN_PORT	GPIOA

#define LCD_D4_PIN	6	//define MCU pin connected to LCD D4
#define LCD_D4_PORT	GPIOA

#define LCD_D5_PIN	7	//define MCU pin connected to LCD D5
#define LCD_D5_PORT	GPIOA

#define LCD_D6_PIN	10	//define MCU pin connected to LCD D6
#define LCD_D6_PORT	GPIOB

#define LCD_D7_PIN	11	//define MCU pin connected to LCD D7
#define LCD_D7_PORT	GPIOB

// cursor position to DDRAM mapping
#define LCD_DDRAM           7	//DB7: set DD RAM address
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54


void lcd_EN_pulse(void);
void lcd_send_nibble(uint8_t data); // re-maps data bits to LCD Pins.
void lcd_send_char(char data);		//forms data ready to send to LCD
void lcd_send_command(uint8_t data);	//forms command ready to send to LCD
void lcd_init(void);			//Initializes LCD
void lcd_clear(void);				//Clears LCD
void lcd_send_string(char *data);	//Outputs string to LCD
void lcd_goto_xy(uint8_t x, uint8_t y);	//Cursor to X Y position

#endif /* LCD_H_ */
