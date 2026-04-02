/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 12.1.4
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include <util/delay.h>

void inicijalizacija(){
	
	lcd_init();
}

int main(void){
	
	inicijalizacija();

	float T; // temperatura u okolini senzora DS18B20
		
		while (1)
		{		
			// proraèun temperature T
			
			lcd_clrscr();
			lcd_home();
			lcd_print("T = %0.4f%cC", T, 178);
			_delay_ms(500);
		} 
	
return 0;	
}