/*
 * LCD_Motor HW.c
 *
 * Created: 07-09-2022 10:46:32 AM
 * Author : kartik.iot
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_config(uint8_t cmd){
	PORTC &= ~(0b00000001);// RS = 0
	PORTD = cmd;
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
}
void LCD_char(char data){
	PORTC |= (0b00000001);// RS = 1
	PORTD = data;
	PORTC |= (0b00000010); // EN = 1
	_delay_ms(10);
	PORTC &= ~(0b00000010); // EN = 0
	_delay_ms(10);
}
void LCD_initiate(){
	_delay_ms(300);
	LCD_config(0x38);
	LCD_config(0x0E);
	LCD_config(0x01);
	_delay_ms(1);
	LCD_config(0x06);
	LCD_config(0x80);
}

int main(void)
{ DDRD = 0b11111111;
	DDRC = 0b10010011;
	DDRA = 0b00000000;
	LCD_initiate();
	while(1){
		if(PINA == 0b00000001){
			PORTC |= 0b00010000;
			LCD_config(0x80);   LCD_char('M');
			LCD_config(0x81);   LCD_char('O');
			LCD_config(0x82);   LCD_char('T');
			LCD_config(0x83);   LCD_char('O');
			LCD_config(0x84);   LCD_char('R');
			LCD_config(0x85);   LCD_char('-');
			LCD_config(0x86);   LCD_char('1');
			
			LCD_config(0x88);   LCD_char('O');
			LCD_config(0x89);   LCD_char('N');
			LCD_config(0x8A);   LCD_char('_');
		}
		if(PINA == 0b00000100){
			PORTC &= ~0b00010000;
			LCD_config(0x80);   LCD_char('M');
			LCD_config(0x81);   LCD_char('O');
			LCD_config(0x82);   LCD_char('T');
			LCD_config(0x83);   LCD_char('O');
			LCD_config(0x84);   LCD_char('R');
			LCD_config(0x85);   LCD_char('-');
			LCD_config(0x86);   LCD_char('1');
			
			LCD_config(0x88);   LCD_char('O');
			LCD_config(0x89);   LCD_char('F');
			LCD_config(0x8A);   LCD_char('F');
		}
		if(PINA == 0b00010000){
			PORTC |= 0b10000000;
			LCD_config(0x80);   LCD_char('M');
			LCD_config(0x81);   LCD_char('O');
			LCD_config(0x82);   LCD_char('T');
			LCD_config(0x83);   LCD_char('O');
			LCD_config(0x84);   LCD_char('R');
			LCD_config(0x85);   LCD_char('-');
			LCD_config(0x86);   LCD_char('2');
			
			LCD_config(0x88);   LCD_char('O');
			LCD_config(0x89);   LCD_char('N');
			LCD_config(0x8A);   LCD_char('_');
		}
		if(PINA == 0b01000000){
			PORTC &= ~0b10000000;
			LCD_config(0x80);   LCD_char('M');
			LCD_config(0x81);   LCD_char('O');
			LCD_config(0x82);   LCD_char('T');
			LCD_config(0x83);   LCD_char('O');
			LCD_config(0x84);   LCD_char('R');
			LCD_config(0x85);   LCD_char('-');
			LCD_config(0x86);   LCD_char('2');
			
			LCD_config(0x88);   LCD_char('O');
			LCD_config(0x89);   LCD_char('F');
			LCD_config(0x8A);   LCD_char('F');
		}
	}
}