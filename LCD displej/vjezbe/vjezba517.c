/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.7
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
		
		while (1)
		{
			lcd_clrscr();
			lcd_home();		
			
			// nastavite ...
		}

	return 0;
}