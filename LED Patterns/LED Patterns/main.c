/*
 * LED Patterns.c
 *
 * Created: 25-08-2022 05:51:06 PM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
// system freq is 8MHz
#define F_CPU 8000000UL
// a system library in AVR which is utilized to generate precise delay
#include <util/delay.h>


void downwardLED()
{
	PORTC = 0b00000000; // here all pins in PORTC is at 0V
	_delay_ms(100);
	PORTC = 0b00000001; // here only PC0 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00000010; // here only PC1 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00000100; // here only PC2 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00001000; // here only PC3 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00010000; // here only PC4 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00100000; // here only PC5 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b01000000; // here only PC6 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b10000000; // here only PC7 is at +5V rest at 0V
	_delay_ms(100);
}

void upwardLED()
{
	PORTC = 0b00000000; // here all pins in PORTC is at 0V
	_delay_ms(100);
	PORTC = 0b10000000; // here only PC7 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b01000000; // here only PC6 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00100000; // here only PC5 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00010000; // here only PC4 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00001000; // here only PC3 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00000100; // here only PC2 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00000010; // here only PC1 is at +5V rest at 0V
	_delay_ms(100);
	PORTC = 0b00000001; // here only PC0 is at +5V rest at 0V
	_delay_ms(100);
}

int main(void)
{
    DDRC = 0b11111111;// i need all pins in PORTC as OUTPUT 
	while (1) 
    {
		downwardLED();
		upwardLED();
    }
}

