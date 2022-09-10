/*
 * RGB LED.c
 *
 * Created: 30-08-2022 11:41:14 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	DDRD = 0b11111111;
    while (1) 
    {
		_delay_ms(1);
		for (int i = 0; i <= 2; i = i+1)
		{
			PORTA = (0b00000001 << i);
			_delay_ms(100);
		}
		PORTA = 0;
		_delay_ms(1);
		for (int i = 0; i <= 2; i = i+1)
		{
			PORTB = (0b00000001 << i);
			_delay_ms(100);
		}
		PORTB =0;
		_delay_ms(1);
		for (int i = 0; i <= 2; i = i+1)
		{
			PORTD = (0b00000001 << i);
			_delay_ms(100);
		}
		PORTD = 0;
		for (int i = 0; i <= 2; i = i+1)
		{
			PORTB = (0b00000001 << i);
			PORTA = (0b00000001 << i);
			_delay_ms(100);
		}
		PORTB =0;_delay_ms(1);
		PORTA = 0;_delay_ms(1);
		_delay_ms(1);
    }
}

