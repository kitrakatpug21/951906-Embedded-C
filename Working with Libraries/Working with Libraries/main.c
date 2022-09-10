/*
 * Working with Libraries.c
 *
 * Created: 07-09-2022 11:30:24 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LCD_4BIT.h"

int main(void)
{
	LCD_initiate();
    while (1) 
    {
		LCD_config(0x84);
		LCD_print("HELLO");
		LCD_config(0xC3);
		LCD_print("DEVANSHI");
    }
}

