/*
 * Motor_HW using Switch.c
 *
 * Created: 06-09-2022 10:45:59 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	while(1){
		DDRC = 0b11000011;
		DDRA = 0b00000000;
		
		if(PINA & 0b00000001)
		{ // switch-1 on and motor-1 clockwise
			PORTC |= 0b00000001;
			PORTC &= ~(0b00000010);
		}
		else if(PINA & 0b00000100)
		{ // switch-2 on and motor-1  anti-clockwise
			PORTC |= 0b00000010;
			PORTC &= ~(0b00000001);
		}
		else
		{
			PORTC &= ~(0b00000011);
		}
		if(PINA & 0b00010000)
		{ // switch-3 on and motor-2 clockwise
			PORTC |= 0b01000000;
			PORTC &= ~(0b10000000);
		}
		else if(PINA & 0b01000000)
		{ // switch-4 on and motor-2  anti-clockwise
			PORTC |= 0b10000000;
			PORTC &= ~(0b01000000);
		}		
		else
		{
			PORTC &= ~(0b11000000);
		}	
	}	
}