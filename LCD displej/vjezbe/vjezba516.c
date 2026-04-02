/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.6
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"


void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
	lcd_define_char(); //definiranje novih znakova
}

int main(void){
	
	inicijalizacija();
	
	lcd_clrscr(); 
	lcd_home(); 
	lcd_char(0x00);
	lcd_print("%c%c%c%c%c%c%c", 0x01,0x02,0x03,0x04,0x05,0x06,0x07);

	return 0;
}