
#ifndef LCD_4BIT_H_
#define LCD_4BIT_H_

#define LCD_PORT PORTC
#define LCD_DDR  DDRC

void LCD_config(uint8_t cmd){
	LCD_PORT &= ~(0b00000001);// RS = 0
	LCD_PORT = (LCD_PORT & 0x0F) | (cmd & 0xF0);
	LCD_PORT |= (0b00000010); // EN = 1
	_delay_ms(10);
	LCD_PORT &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF UPPER NIBBLE (4bit) OF COMMAND
	LCD_PORT &= ~(0b00000001);// RS = 0
	LCD_PORT = (LCD_PORT & 0x0F) | ((cmd<<4) & 0xF0);
	LCD_PORT |= (0b00000010); // EN = 1
	_delay_ms(10);
	LCD_PORT &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF LOWER NIBBLE (4bit) OF COMMAND
}
void LCD_char(char data){
	LCD_PORT |= (0b00000001);// RS = 1
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
	LCD_PORT |= (0b00000010); // EN = 1
	_delay_ms(10);
	LCD_PORT &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF UPPER NIBBLE (4bit) OF DATA
	LCD_PORT |= (0b00000001);// RS = 1
	LCD_PORT = (LCD_PORT & 0x0F) | ((data<<4) & 0xF0);
	LCD_PORT |= (0b00000010); // EN = 1
	_delay_ms(10);
	LCD_PORT &= ~(0b00000010); // EN = 0
	_delay_ms(10);
	// END OF LOWER NIBBLE (4bit) OF DATA
}
void LCD_initiate(){
	LCD_DDR = 0b11110011;//Setup the DDR Register
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

void LCD_print(char *str)
{
	while (*str != '\0')
	{
		LCD_char(*str);
		str++;
	}
}



#endif /* LCD_4BIT_H_ */


