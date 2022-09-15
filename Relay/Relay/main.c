/*
 * Relay.c
 *
 * Created: 15-09-2022 11:29:22 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0x01;
	DDRA = 0x00;
	while (1) 
    {
		if (PINA & 0b00000001)
		{
			PORTC = 0b00000001;
		}
		else
		{
			PORTC = 0b00000000;
		}
    }
}

