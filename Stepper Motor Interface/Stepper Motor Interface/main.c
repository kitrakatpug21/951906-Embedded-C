/*
 * Stepper Motor Interface.c
 *
 * Created: 12-09-2022 10:53:51 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void ClockWise()
{
	// 45 degree
	PORTC = 0b00000010; // A is ON
	_delay_ms(1000);
	// 90 degree
	PORTC = 0b00000011; // A and B are ON
	_delay_ms(1000);
	// 135 degree
	PORTC = 0b00000001; // B is ON
	_delay_ms(1000);
	// 180 degree
	PORTC = 0b10000001; // B and C are ON
	_delay_ms(1000);
	// 225 degree
	PORTC = 0b10000000; // C is ON
	_delay_ms(1000);
	// 270 degree
	PORTC = 0b11000000; // C and D are ON
	_delay_ms(1000);
	// 315 degree
	PORTC = 0b01000000; // D is ON
	_delay_ms(1000);
	// 0 degree
	PORTC = 0b01000010; // A and D are ON
	_delay_ms(1000);
}

void AntiClockWise()
{
	// 315 degree (-45 degree)
	PORTC = 0b01000000; // D is ON
	_delay_ms(1000);
	// 270 degree (-90 degree)
	PORTC = 0b11000000; // C and D are ON
	_delay_ms(1000);
	// 225 degree (-135 degree)
	PORTC = 0b10000000; // C is ON
	_delay_ms(1000);
	// 180 degree (-180 degree)
	PORTC = 0b10000001; // B and C are ON
	_delay_ms(1000);
	// 135 degree (-225 degree)
	PORTC = 0b00000001; // B is ON
	_delay_ms(1000);
	// 90 degree (-270 degree)
	PORTC = 0b00000011; // A and B are ON
	_delay_ms(1000);
	// 45 degree (-315 degree)
	PORTC = 0b00000010; // A is ON
	_delay_ms(1000);
	// 0 degree
	PORTC = 0b01000010; // A and D are ON
	_delay_ms(1000);
}
int main(void)
{
    DDRC = 0b11000011;// PC0, PC1, PC6, PC7 as output
	while (1) 
    {
		ClockWise();
		AntiClockWise();
		AntiClockWise();
		ClockWise();
	}
}

