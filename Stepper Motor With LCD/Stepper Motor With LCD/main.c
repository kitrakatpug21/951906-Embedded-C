/*
 * Stepper Motor With LCD.c
 *
 * Created: 13-09-2022 10:49:00 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_4BIT.h"

int main(void)
{
	DDRC = 0b11000011;// PC0, PC1, PC6, PC7 as output
	DDRA = 0b00000000; // Inputs at PortA
	LCD_initiate();
	int count = 0;
	while (1)
	{
		if (PINA & 0b00000001)
		{
			while (PINA & 0b00000001)
			_delay_ms(1); // debounce
			if (count == 7)
			count = 0;
			else
			count = count + 1;
		}
		else if (PINA & 0b00000010)
		{
			while (PINA & 0b00000010)
			_delay_ms(1); // debounce
			if (count == 0)
			count = 7;
			else
			count = count - 1;
		}
		
		
		if (count == 0)
		{
			// 0 degree
			PORTC = 0b01000010; // A and D is ON
			LCD_config(0x80);LCD_print("At 0 Degree   ");
		}
		else if (count == 1)
		{
			// 45 degree
			PORTC = 0b00000010; // A is ON
			LCD_config(0x80);LCD_print("At 45 Degree   ");
		}
		else if (count == 2)
		{
			// 90 degree
			PORTC = 0b00000011; // A and B is ON
			LCD_config(0x80);LCD_print("At 90 Degree   ");
		}
		else if (count == 3)
		{
			// 135 degree
			PORTC = 0b00000001; // B is ON
			LCD_config(0x80);LCD_print("At 135 Degree   ");
		}
		else if (count == 4)
		{
			// 180 degree
			PORTC = 0b10000001; // B and C is ON
			LCD_config(0x80);LCD_print("At 180 Degree   ");
		}
		else if (count == 5)
		{
			// 225 degree (-135 degree)
			PORTC = 0b10000000; // C is ON
			LCD_config(0x80);LCD_print("At 225 Degree   ");
		}
		else if (count == 6)
		{
			// 270 degree
			PORTC = 0b11000000; // C and D is ON
			LCD_config(0x80);LCD_print("At 270 Degree   ");
		}
		else if (count == 7)
		{
			// 315 degree
			PORTC = 0b01000000; // D is ON
			LCD_config(0x80);LCD_print("At 315 Degree   ");
		}
	}
}
