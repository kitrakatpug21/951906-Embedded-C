/*
 * Timer0_CTC_Interface.c
 *
 * Created: 26-09-2022 10:44:46 AM
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
    TCCR0 = 0b00011001; 
	// Force: No, WGM: CTC, Output: Toggle, Prescale: No
	DDRB = 0b00001000; // Set PB3 as Output
	TCNT0 = 0;
	ADC_Init(0);
	sei();
	while (1) 
    {
		ADCSRA = ADCSRA | 0b01000000;// Start bit is set to 1
// 		if (PINA & 0b00000001)
// 		{
// 			OCR0 = 200 - 1; // 25us Time
// 		}
// 		else if (PINA & 0b00000010)
// 		{
// 			OCR0 = 80 - 1; // 10us Time
// 		}
// 		
// 		else if (PINA & 0b00000100)
// 		{
// 			OCR0 = 8 - 1; // 1us Time
// 		}
// 		else
// 		{
// 			OCR0 = 0;	// 125ns Time
// 		}
	}
}

