/*
 * ADC_Differential_Intf.c
 *
 * Created: 21-09-2022 10:45:36 AM
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
	LCD_config(0x33);LCD_config(0x32); // to sync the UPPER PORT OF LCDs and turn off LOWER PORT
	LCD_config(0x28);// 4-bit 16 character 2 row mode
	LCD_config(0x0C);
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
void ADC_Init_Gain()
{
	///// ADC Setting ////////
	ADMUX = 0b01001101; // ADC: Amp Gain Mode (ADC3-ADC2), LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64
}
void ADC_Init_Diff()
{
	///// ADC Setting ////////
	ADMUX = 0b01010000; // ADC: Differential Mode (ADC0-ADC1), LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64
}
void ADC_Init(uint8_t channel)
{
	///// ADC Setting ////////
	ADMUX = 0b01000000 | channel; // ADC: Single EndeD Mode, LSB-MSB, Ext Ref Volt
	ADCSRA = 0b10000110; // ADC: ADC Mode, Prescale by 64
}
int ADC_GetResult()
{
	ADCSRA = ADCSRA | 0b01000000;// STart bit is set to 1
	while ((ADCSRA & 0b00010000)==0)
	{/*until the flag is 0, wait here*/}
	return ADC;
}

int main(void)
{
	DDRA = 0b00000000; // ADC Input on PORTA
	DDRC = 0b11111111; // LCD on PORTC
	LCD_initiate();
	int volt_d=0;
	int volt_f=0;
	char array[16];
	while (1)
	{
		ADC_Init(0);
		volt_d = (int)(4.887*ADC_GetResult()) / 1000;
		volt_f = (int)(4.887*ADC_GetResult()) % 1000;
		sprintf(array,"ADC0_SE: %d.%dV  ",volt_d,volt_f);
		LCD_config(0x80); LCD_Print(array);
		ADC_Init_Diff();
		volt_d = (int)(4.887*ADC_GetResult()) / 1000;
		volt_f = (int)(4.887*ADC_GetResult()) % 1000;
		sprintf(array,"ADC0_DF: %d.%dV  ",volt_d,volt_f);
		LCD_config(0xC0); LCD_Print(array);	
		ADC_Init_Gain();
		volt_d = (int)(4.887*ADC_GetResult()) / 1000;
		volt_f = (int)(4.887*ADC_GetResult()) % 1000;
		sprintf(array,"ADC0_GN: %d.%dV  ",volt_d,volt_f);
		LCD_config(0x90); LCD_Print(array);
	}
}