/*
 * Interrupt Interface (External).c
 *
 * Created: 21-09-2022 11:01:49 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
// for interrupt interfacing
#include <avr/interrupt.h>

ISR(INT0_vect) // Interrupt Service Routine
{
	for (int i = 0 ; i < 3; i= i + 1)
	{
		PORTC = 0b11110000;
		_delay_ms(300);
		PORTC = 0b00001111;
		_delay_ms(300);
	}
}
int main(void)
{
	DDRD = 0b00000000; // PORTD is INput
	DDRC = 0b11111111; // LED on PORTC
	// Interrupt Setting //
    GICR = 0b01000000; // INT0 is enabled
	MCUCR = 0b00000011; // INT0 is triggered on Rising Edge
	// to enable the interrupt routines
	sei();
	// start interrupt
	while (1) 
    {
		PORTC = 0; // all clear
		_delay_ms(100);
		for (int i = 0; i <= 7; i = i+1)
		{
			PORTC |= (1<<i);
			_delay_ms(100);
		}
		PORTC = 0; // all clear
		_delay_ms(100);
		for (int i = 7; i >= 0; i = i-1)
		{
			PORTC |= (1<<i);
			_delay_ms(100);
		}
    }
}

