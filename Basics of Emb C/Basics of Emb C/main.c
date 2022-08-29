/*
 * Basics of Emb C.c
 *
 * Created: 24-08-2022 05:50:08 PM
 * Author : kartik.iot
 */ 

// all work will be done for a micro-controller environment
// no CONSOLE will be used in this case

// for a normal C-file, we use the header 
// #include <stdio.h>
// we are not working on a computer rather we need to program a micro-controller
// so for that we will be using a library which works for the ATmega16 microcontroller env

#include <avr/io.h>
// mention the frequency of the Micro-controller
#define F_CPU 8000000UL

int main(void)
{
    DDRA = 0b01101011;
	// we are setting PA6,5,3,1 and 0 as OUTPUT
	// and PA7,4 and 2 as INPUT
	//PORTA = 0b01000011;
	// we are generating +5V on PA6,1 and 0
	// and 0V on PA5 and PA3
	// also PA7,4 and 2 are INPUTs so cannot generate any output on these pins
	
	PORTA = 0b01101011;// all leds will be connected to +5V
}