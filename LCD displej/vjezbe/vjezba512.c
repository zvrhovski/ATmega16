/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.2
 */ 

#include "AVR lib/AVR_lib.h"
#include "LCD/lcd.h"
#include <avr/io.h>

void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
}

int main(void){
	
	inicijalizacija();
	// deklaracija podataka
	int a = -123;
	float b = 3.14;
	
	lcd_clrscr(); 
	lcd_home();
	lcd_print("int: %d \n", a);
	lcd_print("float: %f ", b);
	
	return 0;
}