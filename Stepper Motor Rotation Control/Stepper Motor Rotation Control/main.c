/*
 * Stepper Motor Rotation Control.c
 *
 * Created: 12-09-2022 11:31:14 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;// PC0, PC1, PC6, PC7 as output
	DDRA = 0b00000000; // Inputs at PortA
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
		}
		else if (count == 1) 
		{
			// 45 degree
			PORTC = 0b00000010; // A is ON
		}
		else if (count == 2)
		{
			// 90 degree
			PORTC = 0b00000011; // A and B is ON
		}
		else if (count == 3)
		{
			// 135 degree
			PORTC = 0b00000001; // B is ON
		}
		else if (count == 4)
		{
			// 180 degree
			PORTC = 0b10000001; // B and C is ON
		}
		else if (count == 5)
		{
			// 225 degree (-135 degree)
			PORTC = 0b10000000; // C is ON
		}
		else if (count == 6)
		{
			// 270 degree
			PORTC = 0b11000000; // C and D is ON
		}
		else if (count == 7)
		{
			// 315 degree
			PORTC = 0b01000000; // D is ON
		}
	}
}


