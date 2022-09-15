/*
 * ADC - Simple Interface.c
 *
 * Created: 14-09-2022 10:53:00 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000;
	DDRC = 0b11000000;// LED 8, 9
	DDRD = 0b11111111;// LED 0 to 7
	ADMUX = 0b01100100;
	/*
	in ADMUX, 
	ref volt is external (7:6)
	left adjust is from MSB to LSB (5)
	channel selected is ADC4 (4:0)
	*/
	
	ADCSRA = 0b10000110;
	/*
	in ADCSRA, 
	ADEN is set to 1 (7) to make PORT A as ADC
	ADSC is not set as of now (6)
	ADATE (5) and ADIE (3) is not used at this point of time 
	Prescale (2:0) is set to Clk/64
	ADIF, the ADC Flag (4) will be set once the start bit is set to 1 
						   and conversion is completed
	*/
	while (1) 
    {
		ADCSRA |= (0b01000000); // Set the start bit to 1, initiate conversion
		while ((ADCSRA & 0b00010000) == 0)
		{	/* wait here till conversion is complete*/   }
		// once conversion is done, while loop will break
		//Transfer the ADC result on LEDs
		PORTC = ADCL;
		PORTD = ADCH;
    }
}

