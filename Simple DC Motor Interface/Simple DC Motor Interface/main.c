/*
 * Simple DC Motor Interface.c
 *
 * Created: 05-09-2022 11:13:21 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRC = 0b01000001;// PC0 and PC6 are connected to motor
	while (1) 
    {
	    PORTC = 0b00000001; // Motor-1 is ON, Motor-2 is OFF
	    _delay_ms(3000);
	    PORTC = 0b01000000; // Motor-2 is ON, Motor-1 is OFF
	    _delay_ms(3000);
	    PORTC = 0b01000001; // Motor-2 is ON, Motor-2 is ON
	    _delay_ms(3000);
	    PORTC = 0b00000000; // Motor-2 is OFF, Motor-1 is OFF
	    _delay_ms(3000);
    }
}

