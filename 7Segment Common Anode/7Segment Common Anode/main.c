/*
 * 7Segment Common Anode.c
 *
 * Created: 30-08-2022 11:12:25 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRC = 0b01111111;
	DDRD = 0b00000011;
    uint8_t gunjan_segment[10] = {	0b11000000,//0b00111111,//0
									0b11111001,//0b00000110,//1
									0b10100100,//0b01011011,//2
									0b10110000,//0b01001111,//3
									0b10011001,//0b01100110,//4
									0b10010010,//0b01101101,//5
									0b10000010,//0b01111101,//6
									0b11111000,//0b00000111,//7
									0b10000000,//0b01111111,//8
									0b10010000,//0b01101111 //9
    };
	DDRA = 0b00000111;
	while(1)
	{
		for (int tens = 0; tens <=9; tens = tens +1 )
		{
			for (int ones = 0; ones <=9; ones = ones + 1)
			{
				for (int repeat = 0; repeat <= 10; repeat = repeat + 1)
				{
					PORTD = 0b00000001;
					PORTC = gunjan_segment[tens];
					_delay_ms(10);
					PORTD = 0b00000010;
					PORTC = gunjan_segment[ones];
					_delay_ms(10);
				}
			}
		}
	}
}


