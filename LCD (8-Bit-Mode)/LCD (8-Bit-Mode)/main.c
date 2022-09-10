/*
 * LCD (8-Bit-Mode).c
 *
 * Created: 06-09-2022 11:05:03 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_Config(uint8_t cmd)
{
	//1. RS pin must be set to 0 for configuration mode
	PORTC = 0b00000000;// EN = 0; RS = 0
	//2. Command must be load on D0-D7 Pins
	PORTD = cmd;
	//3. Generate a Clock Signal 0-1-0
	PORTC = 0b00000010;// EN = 1; RS = 0
	_delay_ms(10);
	PORTC = 0b00000000;// EN = 0; RS = 0
	_delay_ms(10);
}
void LCD_Char(char data)
{
	//1. RS pin must be set to 1 for character mode
	PORTC = 0b00000001;// EN = 0; RS = 1 
	//2. Data must be load on D0-D7 Pins
	PORTD = data;
	//3. Generate a Clock Signal 0-1-0
	PORTC = 0b00000011;// EN = 1; RS = 1
	_delay_ms(10);
	PORTC = 0b00000001;// EN = 0; RS = 1
	_delay_ms(10);//3. Generate a Clock Signal 0-1-0
}

void LCD_Init()
{
	// To init LCD, first wait for 300ms to let LCD boot
	_delay_ms(300);
	// 1. Set LCD mode to 8-bit, 16 character, 2 row
	LCD_Config(0x38); 
	// 0x30 (16 char 1 row 8b)/ 0x28 (16 char 2 row 4b)/ 0x20 (16 char 1 row 4b)
	//2. Set the cursor of LCD
	LCD_Config(0x0E); // 0x0E (Solid)/ 0x0F (blinky)/ 0x0C (OFF)
	//3. Clear the LCD
	LCD_Config(0x01); // CLEAR
	_delay_ms(1);
	//4. Set the display direction from Left->Right
	LCD_Config(0x06); // 0x04 (Right->Left)
	//5. Set the starting Point of Display
	LCD_Config(0x80);
}

int main(void)
{
	DDRC = 0b00000011; // EN,RS
	DDRD = 0b11111111; // D7-D0
	LCD_Init();
	while (1) 
    {
		if (PINA & 0b00000001)
		{
			LCD_Config(0x80); 
			LCD_Char('B');
			LCD_Char('U');
			LCD_Char('T');
			LCD_Char('T');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char('1');
			LCD_Char(' ');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char(' ');
		}
		else
		{
			LCD_Config(0x80);
			LCD_Char('B');
			LCD_Char('U');
			LCD_Char('T');
			LCD_Char('T');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char('1');
			LCD_Char(' ');
			LCD_Char('O');
			LCD_Char('F');
			LCD_Char('F');
		}
		if (PINA & 0b10000000)
		{
			LCD_Config(0xC0);
			LCD_Char('B');
			LCD_Char('U');
			LCD_Char('T');
			LCD_Char('T');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char('2');
			LCD_Char(' ');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char(' ');
		}
		else
		{
			LCD_Config(0xC0);
			LCD_Char('B');
			LCD_Char('U');
			LCD_Char('T');
			LCD_Char('T');
			LCD_Char('O');
			LCD_Char('N');
			LCD_Char('2');
			LCD_Char(' ');
			LCD_Char('O');
			LCD_Char('F');
			LCD_Char('F');
		}	
    }
}

