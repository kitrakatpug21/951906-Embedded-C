/*
 * ADC_TempSensor.c
 *
 * Created: 19-09-2022 11:45:44 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000; // ADC Input on PORTA
	DDRC = 0b00000111; // 3 LEDs on PORTC
	///// ADC Setting ////////
	ADMUX = 0b01000011; // ADC: Single Ended MOde on ADC3, LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64	
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;// STart bit is set to 1
		while ((ADCSRA & 0b00010000)==0)
		{/*until the flag is 0, wait here*/}
		
		if (ADC >= 30 && ADC < 40)
		{
			PORTC = 0b00000001;
		}
		else if (ADC >= 40 && ADC < 50)
		{
			PORTC = 0b00000011;
		}
		else if (ADC >= 40 && ADC < 50)
		{
			PORTC = 0b00000011;
		}
		else if (ADC >= 50 && ADC < 60)
		{
			PORTC = 0b00000101;
		}
		else if (ADC >= 60 && ADC < 70)
		{
			PORTC = 0b00000110;
		}
		else if (ADC >= 70)
		{
			PORTC = 0b00000111;
		}
		else
		{
			PORTC = 0b00000000;
		}
    }
}


