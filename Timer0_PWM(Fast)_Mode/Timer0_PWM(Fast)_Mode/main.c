/*
 * Timer0_PWM(Fast)_Mode.c
 *
 * Created: 26-09-2022 11:23:13 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>

ISR (ADC_vect)
{
	OCR0 = (int)(ADC * 0.25);
}

void ADC_Init(uint8_t channel)
{
	///// ADC Setting ////////
	ADMUX = 0b01000000 | channel; // ADC: Single Ended MOde, LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10001110; // ADC: ADC Mode, Prescale by 64, Interrupt Enabled
}

int main(void)
{
    TCCR0 = 0b01111011; 
	// Force: No, WGM: PWM(Fast), Output: Set on Match, Prescale: 64
	DDRB = 0b00001000; // Set PB3 as Output
	TCNT0 = 0;
	ADC_Init(0);
	sei();
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;// Start bit is set to 1
	}
}

