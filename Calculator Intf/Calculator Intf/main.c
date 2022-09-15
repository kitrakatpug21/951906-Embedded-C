/*
 * Calculator Intf.c
 *
 * Created: 15-09-2022 10:54:51 AM
 * Author : kartik.iot
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_4BIT.h"

int main(void)
{
	DDRA = 0b00001111; // KEYPAD
	LCD_initiate();
	char array[16];
	int index = 0;
	while (1)
	{
		PORTA = 0b00000001; // +5V on PA0 (7,8,9,/)
		if (PINA & 0b00010000)
		{
			while(PINA & 0b00010000);
			_delay_ms(1);
			array[index]='7';
			index = index + 1;
		}
		else if (PINA & 0b00100000)
		{
			while(PINA & 0b00100000);
			_delay_ms(1);
			array[index]='8';
			index = index + 1;
		}
		else if (PINA & 0b01000000)
		{
			while(PINA & 0b01000000);
			_delay_ms(1);
			array[index]='9';
			index = index + 1;
		}
		else if (PINA & 0b10000000)
		{
			while(PINA & 0b10000000);
			_delay_ms(1);
			array[index]='/';
			index = index + 1;
		}
		
		_delay_ms(100);
		
		PORTA = 0b00000010; // +5V on PA1 (4,5,6,x)
		if (PINA & 0b00010000)
		{
			while(PINA & 0b00010000);
			_delay_ms(1);
			array[index]='4';
			index = index + 1;
		}
		else if (PINA & 0b00100000)
		{
			while(PINA & 0b00100000);
			_delay_ms(1);
			array[index]='5';
			index = index + 1;
		}
		else if (PINA & 0b01000000)
		{
			while(PINA & 0b01000000);
			_delay_ms(1);
			array[index]='6';
			index = index + 1;
		}
		else if (PINA & 0b10000000)
		{
			while(PINA & 0b10000000);
			_delay_ms(1);
			array[index]='X';
			index = index + 1;
		}
		
		_delay_ms(100);
		
		PORTA = 0b00000100; // +5V on PA2 (1,2,3,-)
		if (PINA & 0b00010000)
		{
			while(PINA & 0b00010000);
			_delay_ms(1);
			array[index]='1';
			index = index + 1;
		}
		else if (PINA & 0b00100000)
		{
			while(PINA & 0b00100000);
			_delay_ms(1);
			array[index]='2';
			index = index + 1;
		}
		else if (PINA & 0b01000000)
		{
			while(PINA & 0b01000000);
			_delay_ms(1);
			array[index]='3';
			index = index + 1;
		}
		else if (PINA & 0b10000000)
		{
			while(PINA & 0b10000000);
			_delay_ms(1);
			array[index]='-';
			index = index + 1;
		}
		
		_delay_ms(100);
		
		PORTA = 0b00001000; // +5V on PA2 (on,0,=,+)
		if (PINA & 0b00010000)
		{
			while(PINA & 0b00010000);
			_delay_ms(1);
			for (int i = 0; i <16; i = i + 1)
			{
				array[i]='\0';
			}
			LCD_config(0x01);_delay_ms(10);
			index = 0;
		}
		else if (PINA & 0b00100000)
		{
			while(PINA & 0b00100000);
			_delay_ms(1);
			array[index]='0';
			index = index + 1;
		}
		else if (PINA & 0b01000000)
		{
			while(PINA & 0b01000000);
			_delay_ms(1);
			array[index]='=';
			index = index + 1;
		}
		else if (PINA & 0b10000000)
		{
			while(PINA & 0b10000000);
			_delay_ms(1);
			array[index]='+';
			index = index + 1;
		}
		
		_delay_ms(100);
		LCD_config(0x80);
		LCD_print(array);
	}
}

