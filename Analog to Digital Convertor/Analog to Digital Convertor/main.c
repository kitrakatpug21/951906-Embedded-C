/*
 * Analog to Digital Convertor.c
 *
 * Created: 19-09-2022 10:53:58 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000; // ADC Input on PORTA
	DDRC = 0b11111111;// 8 LEDs on PORTC
	DDRD = 0b00000011;// 2 LEDs on PORTD
	///// ADC Setting ////////
	ADMUX = 0b01000011; // ADC: Single Ended MOde on ADC3, LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64	
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;
		while ((ADCSRA & 0b00010000)==0)
		{/*until the flag is 0, wait here*/}
		PORTC = ADCL;
		PORTD = ADCH;
    }
}

