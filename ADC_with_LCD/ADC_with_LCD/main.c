/*
 * ADC_with_LCD.c
 *
 * Created: 20-09-2022 10:46:20 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>

void LCD_config(uint8_t cmd){
	PORTC &= ~(0b00000001);// RS = 0
	PORTC = (PORTC & 0x0F) | (cmd & 0xF0);
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF UPPER NIBBLE (4bit) OF COMMAND
	PORTC &= ~(0b00000001);// RS = 0
	PORTC = (PORTC & 0x0F) | ((cmd<<4) & 0xF0);
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF LOWER NIBBLE (4bit) OF COMMAND
}
void LCD_char(char data){
	PORTC |= (0b00000001);// RS = 1
	PORTC = (PORTC & 0x0F) | (data & 0xF0);
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF UPPER NIBBLE (4bit) OF DATA
	PORTC |= (0b00000001);// RS = 1
	PORTC = (PORTC & 0x0F) | ((data<<4) & 0xF0);
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF LOWER NIBBLE (4bit) OF DATA
}
void LCD_initiate(){
	_delay_ms(300);
	//LCD_config(0x38);// 8 bit mode
	LCD_config(0x33);LCD_config(0x32); // to sync the UPPER PORT OF LCDs and turn off LOWER PORT
	LCD_config(0x28);// 4-bit 16 character 2 row mode
	LCD_config(0x0E);
	LCD_config(0x01);
	_delay_ms(1);
	LCD_config(0x06);
	LCD_config(0x80);
}

void LCD_Print(char *str)
{
	while (*str != '\0')
	{
		LCD_char(*str);
		str++;
	}
}


int main(void)
{
   DDRA = 0b00000000; // ADC Input on PORTA
   DDRC = 0b11111111;// LCD on PORTC
   ///// ADC Setting ////////
   ADMUX = 0b01000011; // ADC: Single Ended MOde on ADC3, LSB-MSB, Ext Ref Volt
   ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64
   LCD_initiate();
   char array[16];
   while (1)
   {
	   ADCSRA = ADCSRA | 0b01000000;
	   while ((ADCSRA & 0b00010000)==0)
	   {/*until the flag is 0, wait here*/}
	/*
	  printf("data %d", variable);
	  char array[16];
	   sprintf(<array>,<"data %d">,<variable>)
	
	*/
		sprintf(array,"ADC: %d  ",ADC);
		LCD_config(0x80); LCD_Print(array);
   }
}

