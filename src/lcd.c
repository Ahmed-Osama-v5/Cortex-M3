//*****************************************************************************
//
// File Name	: 'lcd_lib.c'
// Title		: 4-bit LCd interface
// Author		: Ahmed Osama
// Date			: Mar 13 2019
// Target MCU	: STM32F10xx
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************
#include <inttypes.h>
#include "stm32f10x.h"
#include "stm32f10x_spi.h"
#include "lcd.h"
#include "delay.h"

void lcd_EN_pulse(void){
	LCD_EN_PORT->ODR |= (1 << LCD_EN_PIN);
	delay(1000);
	LCD_EN_PORT->ODR &= ~(1 << LCD_EN_PIN);
	delay(1000);
}

void lcd_send_nibble(uint8_t data){
	uint8_t mask = 1;
	data >>= 4;
	if(data&mask)
		LCD_D4_PORT->ODR |= (1 << LCD_D4_PIN);
	else
		LCD_D4_PORT->ODR &= ~(1 << LCD_D4_PIN);

	mask *= 2;
	if(data&mask)
		LCD_D5_PORT->ODR |= (1 << LCD_D5_PIN);
	else
		LCD_D5_PORT->ODR &= ~(1 << LCD_D5_PIN);

	mask *= 2;
	if(data&mask)
		LCD_D6_PORT->ODR |= (1 << LCD_D6_PIN);
	else
		LCD_D6_PORT->ODR &= ~(1 << LCD_D6_PIN);

	mask *= 2;
	if(data&mask)
		LCD_D7_PORT->ODR |= (1 << LCD_D7_PIN);
	else
		LCD_D7_PORT->ODR &= ~(1 << LCD_D7_PIN);
}

void lcd_send_char(char data)		//Sends Char to LCD
{
	LCD_RS_PORT->ODR |= (1 << LCD_RS_PIN);

	lcd_send_nibble(data); // Higher nibble first
	lcd_EN_pulse();

	lcd_send_nibble(data<<4);
	lcd_EN_pulse();
}
void lcd_send_command(uint8_t data)	//Sends Command to LCD
{
	LCD_RS_PORT->ODR &= ~(1 << LCD_RS_PIN);

	lcd_send_nibble(data); // Higher nibble first
	lcd_EN_pulse();

	lcd_send_nibble(data<<4);
	lcd_EN_pulse();
}
void lcd_init(void)//Initializes LCD
{
	delay(15);
	lcd_send_nibble(0x00);

	LCD_RS_PORT->ODR &= ~(1 << LCD_RS_PIN);
	LCD_RW_PORT->ODR &= ~(1 << LCD_RW_PIN);
	LCD_EN_PORT->ODR &= ~(1 << LCD_EN_PIN);

	lcd_send_command(0x33);
	lcd_send_command(0x32);
	lcd_send_command(0x28); // 4-bit
	lcd_send_command(0x0E);
	lcd_send_command(0x01);
	delay(10000);
	lcd_send_command(0x06);
	lcd_send_command(0x0C); // Cursor off
}
void lcd_clear(void)				//Clears LCD
{
	lcd_send_command(0x01);
}

void lcd_send_string(char *data)	//Outputs string to LCD
{
	while(*data){
		lcd_send_char(*data++);
	}
}

void lcd_goto_xy(uint8_t x, uint8_t y)	//Cursor to X Y position
{
	uint8_t DDRAMAddr;
	// remap lines into proper order
	switch(y)
	{
	case 0: DDRAMAddr = LCD_LINE0_DDRAMADDR+x; break;
	case 1: DDRAMAddr = LCD_LINE1_DDRAMADDR+x; break;
	case 2: DDRAMAddr = LCD_LINE2_DDRAMADDR+x; break;
	case 3: DDRAMAddr = LCD_LINE3_DDRAMADDR+x; break;
	default: DDRAMAddr = LCD_LINE0_DDRAMADDR+x;
	}
	// set data address
	lcd_send_command(1<<LCD_DDRAM | DDRAMAddr);

}
