/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 5.1.2
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
	
	// deklaracija podataka	
	int a = -123;
	float b = 3.14;
	int32_t c = -1234567;
	uint32_t d = 1234567;
	
	while (1)
	{
		lcd_clrscr();
		lcd_home();
		lcd_print("int: %d \n", a);
		lcd_print("float: %0.2f ", b);
		_delay_ms(2000);
		lcd_clrscr();
		lcd_home();
		lcd_print("int32_t:%ld\n", c);
		lcd_print("uint32_t:%luf", d);
		_delay_ms(2000);		
	
	}
	return 0;	
}