/*
 * Keypad Interface.c
 *
 * Created: 13-09-2022 11:13:21 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_4BIT.h"

int main(void)
{
    DDRA = 0b00001111; // KEYPAD
	DDRC = 0b00001111; // LED
	LCD_initiate();
	while (1) 
    {
		PORTA = 0b00000001; // +5V on PA0 (1,2,3)
		if (PINA & 0b00010000)
		{
			PORTC = 0b00000001; // Button-1 is Pressed
			LCD_config(0x80);LCD_print("Button - 1");
		}
		else if (PINA & 0b00100000)
		{
			PORTC = 0b00000010; // Button-2 is Pressed
			LCD_config(0x80);LCD_print("Button - 2");
		}
		else if (PINA & 0b01000000)
		{
			PORTC = 0b00000011; // Button-3 is Pressed
			LCD_config(0x80);LCD_print("Button - 3");
		}
		
		_delay_ms(100);
		
		PORTA = 0b00000010; // +5V on PA1 (4,5,6)
		if (PINA & 0b00010000)
		{
			PORTC = 0b00000100; // Button-4 is Pressed
			LCD_config(0x80);LCD_print("Button - 4");
		}
		else if (PINA & 0b00100000)
		{
			PORTC = 0b00000101; // Button-5 is Pressed
			LCD_config(0x80);LCD_print("Button - 5");
		}
		else if (PINA & 0b01000000)
		{
			PORTC = 0b00000110; // Button-6 is Pressed
			LCD_config(0x80);LCD_print("Button - 6");
		}
		
		_delay_ms(100);
		
		PORTA = 0b00000100; // +5V on PA2 (7,8,9)
		if (PINA & 0b00010000)
		{
			PORTC = 0b00000111; // Button-7 is Pressed
			LCD_config(0x80);LCD_print("Button - 7");
		}
		else if (PINA & 0b00100000)
		{
			PORTC = 0b00001000; // Button-8 is Pressed
			LCD_config(0x80);LCD_print("Button - 8");
		}
		else if (PINA & 0b01000000)
		{
			PORTC = 0b00001001; // Button-9 is Pressed
			LCD_config(0x80);LCD_print("Button - 9");
		}
		
		_delay_ms(100);
		
    }
}

