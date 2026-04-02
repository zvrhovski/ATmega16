/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>


void inicijalizacija(){
	
	}

int main(void){
	
	inicijalizacija();
	
	char a = 'A';
	
	while (1)
	{
		lcd_clrscr();
		lcd_home(); 
		
		lcd_print("Veliko slovo: %c\n", a); 
		lcd_print("Malo slovo: "); // popravite argument funkcije lcd_print 
		
		_delay_ms(1000);
		
		if (++a > 'Z')
		a = 'A';
		
	}
	
	return 0;	
}