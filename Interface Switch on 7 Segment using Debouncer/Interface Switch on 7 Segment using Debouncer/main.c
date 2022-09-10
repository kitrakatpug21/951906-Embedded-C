/*
 * Interface Switch on 7 Segment using Debouncer.c
 *
 * Created: 31-08-2022 11:22:58 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    DDRA = 0b00000000; // PA0 and PA7 as INPUT
	DDRC = 0b01111111; // PC0 to PC6 as 7 Segment output
	uint8_t gunjan_segment[10] = {~0b00111111,//0
									~0b00000110,//1
									~0b01011011,//2
									~0b01001111,//3
									~0b01100110,//4
									~0b01101101,//5
									~0b01111101,//6
									~0b00000111,//7
									~0b01111111,//8
									~0b01101111 //9
	};
	int counter = 0;
	while (1) 
    {
		if (PINA == 0b00000001)
		{
			while (PINA == 0b00000001)
			{
				_delay_ms(10);// wait here till switch is released
			}
			if (counter == 9)
				counter = 0;
			else
				counter = counter + 1;
		}
		else if (PINA == 0b10000000)
		{
			while (PINA == 0b10000000)
			{
				_delay_ms(10);// wait here till switch is released
			}
			if (counter == 0)
				counter = 9;
			else
				counter = counter - 1;
		}
		PORTC = gunjan_segment[counter];
    }
}

