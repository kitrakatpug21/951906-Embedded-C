/*
 * Gunjan_Project.c
 *
 * Created: 13-09-2022 11:05:59 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_config(uint8_t cmd)
{	// cmd = command
	PORTB = 0b00000000; // PC0 AND PC1 ARE FOR RS(0 FOR CONFIGURATION MODE=LOCATION OF DATA &1 FOR DATA) & E(ENABLE= FOR GIVE CLOCK AS 010 WITH SOME DELAY)
	//HERE |^ RS = 0 FOR CONFIG MODE & EN = 0
	PORTA = cmd;
	PORTB = 0b00000010; //EN =1 FOR CLOCK
	_delay_ms(10);
	PORTB = 0b00000000; // EN = 0 FOR CLOCK AS 0-1-0
	_delay_ms(10);
}
void LCD_char(char data)
{
	PORTB = 0b00000001;//RS = 1 FOR DATA & EN = 0
	PORTA = data;
	PORTB = 0b00000011;//RS = 1 & EN = 1
	_delay_ms(10);
	PORTB = 0b00000001;//RS = 1 & EN = 0
	_delay_ms(10);
}
void LCD_initiate()
{
	_delay_ms(300);//DELAY IS MUST TO BOOT UP THE LCD
	LCD_config(0x38);//THIS COMMAND IS FOR (16 CHARACTER, 8- BIT, 2 ROW MODE)
	LCD_config(0x0E);//FOR SOLID CURSOR
	LCD_config(0x01);//TO CLEAR THE LCD
	_delay_ms(1);//AFTER CLEARING DELAY IS MANDATORY
	LCD_config(0x06);//FOR LEFT TO RIGHT DATA
	LCD_config(0x80);//STARTING LOCATION FOR DATA....
	//1ST ROW FROM (0x80)...UPTO....(0x8F){IN HEXADECIMAL FORM}
	//2ND ROW FROM (0xC0)...UPTO....(0xCF)
}
void LCD_print(char *str)
{
	while(*str != '\0')
	{
		LCD_char(*str);
		str++;
	}
}
void clockwise_angles()
{
	PORTC = 0b00000010;//45 degree   A is ON
	LCD_config(0x80);
	LCD_print("+45 degree");
	_delay_ms(1000);
	PORTC = 0b00000011;//90 degree   A  and B are ON
	LCD_config(0x80);LCD_print("+90 degree");
	_delay_ms(1000);
	PORTC = 0b00000001;//135 degree  B is ON
	LCD_config(0x80);LCD_print("+135 degree");
	_delay_ms(1000);
	PORTC = 0b01000001;//180 degree   B  and C are ON
	LCD_config(0x80);LCD_print("+180 degree");
	_delay_ms(1000);
	PORTC = 0b01000000;//225 degree  C is ON
	LCD_config(0x80);LCD_print("+225 degree");
	_delay_ms(1000);
	PORTC = 0b11000000;//270 degree  C  and D are ON
	LCD_config(0x80);LCD_print("+270 degree");
	_delay_ms(1000);
	PORTC = 0b10000000;//315 degree  D is ON
	LCD_config(0x80);LCD_print("+315 degree");
	_delay_ms(1000);
	PORTC = 0b10000010;//0 degree    A  and D are ON
	LCD_config(0x80);LCD_print("0 degree");
	_delay_ms(1000);
}

void anti_clockwise_angles()
{
	PORTC = 0b10000010;//0 degree (0 degree)   A  and D are ON
	_delay_ms(1000);
	PORTC = 0b10000000;//315 degree (-45 degree)  D is ON
	_delay_ms(1000);
	PORTC = 0b11000000;//270 degree (-90 degree)  C  and D are ON
	_delay_ms(1000);
	PORTC = 0b01000000;//225 degree (-135 degree)  C is ON
	_delay_ms(1000);
	PORTC = 0b01000001;//180 degree  (-180 degree)  B  and C are ON
	_delay_ms(1000);
	PORTC = 0b00000001;//135 degree (-225 degree)  B is ON
	_delay_ms(1000);
	PORTC = 0b00000011;//90 degree  (-270 degree)  A  and B are ON
	_delay_ms(1000);
	PORTC = 0b00000010;//45 degree  (-315 degree)  A is ON
	_delay_ms(1000);
}

int main(void)
{
	DDRC = 0b11000011;
	DDRA = 0b11111111;
	DDRB = 0b00000011;
	LCD_initiate();
 
	while(1)
	{
		clockwise_angles();/*
		anti_clockwise_angles();
		LCD_config(0x80);
		LCD_print("+315 degree");
		_delay_ms(1000);
		LCD_print("+270 degree");
		_delay_ms(1000);
		LCD_print("+225 degree");
		_delay_ms(1000);
		LCD_print("+180 degree");
		_delay_ms(1000);
		LCD_print("+135 degree");
		_delay_ms(1000);
		LCD_print("+90 degree");
		_delay_ms(1000);
		LCD_print("+45 degree");
		_delay_ms(1000);
		LCD_print("0 degree");
		_delay_ms(1000);
 
		anti_clockwise_angles();
		LCD_print("-45 degree");
		_delay_ms(1000);
		LCD_print("-90 degree");
		_delay_ms(1000);
		LCD_print("-135 degree");
		_delay_ms(1000);
		LCD_print("-180 degree");
		_delay_ms(1000);
		LCD_print("-225 degree");
		_delay_ms(1000);
		LCD_print("-270 degree");
		_delay_ms(1000);
		LCD_print("-315 degree");
		_delay_ms(1000);
		LCD_print("0 degree");
		_delay_ms(1000);*/ 
		clockwise_angles();
	}
}