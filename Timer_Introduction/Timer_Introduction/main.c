/*
 * Timer_Introduction.c
 *
 * Created: 22-09-2022 10:59:03 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL

int main(void)
{
    TCCR0 = 0b00010001; // No force, WGM: normal, OUTPUT: Toggle, Prescale: 1
	DDRB = 0b00001000; // PB3 as output for OC0
	OCR0 = 255;TCNT0 = 0;
	while (1) 
    {
    }
}
