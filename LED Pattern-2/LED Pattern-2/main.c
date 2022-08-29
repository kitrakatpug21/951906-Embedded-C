/*
 * LED Pattern-2.c
 *
 * Created: 25-08-2022 06:24:05 PM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11111111; // all pins in PORTC are set as OUTPUT
    DDRA = 0b11111111; // all pins in PORTA are set as OUTPUT
    while (1) 
    {
		for (int i = 0; i <= 7; i = i+1)
		{
			PORTC = (0b00000001 << i);
			PORTA = (0b10000000 >> i);
			_delay_ms(100);
		}
		for (int i = 7; i >= 0; i = i-1)
		{
			PORTC = (0b00000001 << i);
			PORTA = (0b10000000 >> i);
			_delay_ms(100);
		}
    }
}


/*
for (int i = 0; i <= 7; i = i+1)
{
	PORTC = (0b00000001 << i);
	_delay_ms(100);
}
for (int i = 7; i >= 0; i = i-1)
{
	PORTC = (0b00000001 << i);
	_delay_ms(100);
}
for (int i = 0; i <= 7; i = i+1)
{
	PORTA = (0b00000001 << i);
	_delay_ms(100);
}
for (int i = 0; i <= 7; i = i+1)
{
	PORTA = (0b10000000 >> i);
	_delay_ms(100);
}

*/