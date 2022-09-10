/*
 * Interfacing Switch.c
 *
 * Created: 31-08-2022 10:53:16 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
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
	DDRC = 0b11111111; // ALL PORTC PINS ARE OUTPUT
	DDRA = 0b00000000; // PA0 and PA7 will be INPUT   
	while (1) 
    {
		if (PINA == 0b00000001)
		{
			upwardLED();
		}
		else if (PINA == 0b10000000)
		{
			downwardLED();
		}
		else
		{
			PORTC = 0b00000000;
		}
		
    }
}

