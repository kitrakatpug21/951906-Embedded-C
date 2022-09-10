/*
 * 7Segment Matrix Clock.c
 *
 * Created: 30-08-2022 11:03:27 AM
 * Author : kartik.iot
 */ 
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    uint8_t gunjan_segment[10] = {0b00111111,//0
	    0b00000110,//1
	    0b01011011,//2
	    0b01001111,//3
	    0b01100110,//4
	    0b01101101,//5
	    0b01111101,//6
	    0b00000111,//7
	    0b01111111,//8
	    0b01101111 //9
    };
	DDRC = 0b01111111; // PC6 to PC0 are used for segment
	DDRD = 0b00001111; // Com Pins
	while (1) 
    {
		for (int thou = 0; thou <= 2; thou = thou + 1)
		{
			for (int hund = 0; hund <= 9; hund = hund + 1)
			{
				for (int tens = 0; tens <= 5; tens = tens + 1)
				{
					for (int ones = 0; ones <= 9; ones = ones + 1)
					{
						for (int repeat = 0; repeat <25; repeat = repeat + 1)
						{
							if (thou == 2 && hund == 3 && tens == 5 && ones == 9)
							{
								thou = hund = tens = ones = 0;
							}
							PORTD = 0b00001110;
							PORTC = gunjan_segment[ones];
							_delay_ms(10);
							PORTD = 0b00001101;
							PORTC = gunjan_segment[tens];
							_delay_ms(10);
							PORTD = 0b00001011;
							PORTC = gunjan_segment[hund];
							PORTC = PORTC | 0b10000000;
							_delay_ms(10);
							PORTD = 0b00000111;
							PORTC = gunjan_segment[thou];
							_delay_ms(10);
						}
					}
				}
			}
		}
    }
}

