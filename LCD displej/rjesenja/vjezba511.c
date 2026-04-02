/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.1
 */ 

#include "AVR lib/AVR_lib.h"
#include "LCD/lcd.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
}

int main(void){
	
	inicijalizacija();
	
	while(1){
	
	lcd_clrscr();  // brisanje LCD displeja
	lcd_home();    // pozicioniranje kursora na poèetak 
	lcd_print("     Ivica     \n      Ivic"); 
	_delay_ms(2000); 
	
	lcd_clrscr(); 
	lcd_home();
	lcd_gotoxy(0,1); 
	lcd_print("Visoka tehnicka"); 
	lcd_gotoxy(1,6); 
	lcd_print("skola u Bj"); 
	_delay_ms(2000); 
	
	}
	return 0;
	
}