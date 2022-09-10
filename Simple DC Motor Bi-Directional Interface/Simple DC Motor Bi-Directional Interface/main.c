/*
 * Simple DC Motor Bi-Directional Interface.c
 *
 * Created: 05-09-2022 11:28:37 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b11000011;// PC0, PC1 (motor-1) and PC6, PC7 (motor-2) are connected to motor
	while (1) 
    {
	    // Clockwise in motor-1
		PORTC = 0b00000001;
		_delay_ms(2000);
		// Clockwise in motor-2
		PORTC = 0b01000000;
		_delay_ms(2000);
		// Clockwise both motor
		PORTC = 0b01000001;
		_delay_ms(2000);
		// STOP Both Motor
		PORTC = 0b00000000;
		_delay_ms(2000);
		// Anti-Clockwise in motor-1
		PORTC = 0b00000010;
		_delay_ms(2000);
		// Anti-Clockwise in motor-2
		PORTC = 0b10000000;
		_delay_ms(2000);
		// Anti-Clockwise both motor
		PORTC = 0b10000010;
		_delay_ms(2000);
		// STOP Both Motor
		PORTC = 0b00000000;
		_delay_ms(2000);
		// Motor-1 Clockwise, Motor-2 Anti-Clockwise
		PORTC = 0b10000001;
		_delay_ms(2000);
		// Motor-1 Anti-Clockwise, Motor-2 Clockwise
		PORTC = 0b01000010;
		_delay_ms(2000);
		// STOP Both Motor
		PORTC = 0b00000000;
		_delay_ms(2000);
    }
}


