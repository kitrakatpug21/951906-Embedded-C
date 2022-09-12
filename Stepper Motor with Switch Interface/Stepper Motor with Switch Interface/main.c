/*
 * Stepper Motor with Switch Interface.c
 *
 * Created: 12-09-2022 11:22:22 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
    DDRC = 0b11000011;// PC0, PC1, PC6, PC7 as output
	DDRA = 0b00000000; // Inputs at PortA
	while (1) 
    {
		if (PINA & 0b00000001)
		{
			// 45 degree
			PORTC = 0b00000010; // A is ON
		}
		else if (PINA & 0b00000010)
		{
			// 135 degree
			PORTC = 0b00000001; // B is ON
		}
		else if (PINA & 0b00000100)
		{
			// 225 degree (-135 degree)
			PORTC = 0b10000000; // C is ON
		}
		else if (PINA & 0b00001000)
		{
			// 315 degree
			PORTC = 0b01000000; // D is ON
		}
	}
}

