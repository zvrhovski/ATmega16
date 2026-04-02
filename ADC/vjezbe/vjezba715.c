/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "ADC/adc.h"

	
void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
	adc_init(); // inicijalizacija AD pretvorbe
}

int main(void){
	
	
	inicijalizacija();

	uint16_t ADC6; // rezultat AD pretvorbe
	float T;
	
	while(1)
	{	
		ADC6 = adc_read_10bit(6);
		
		// relacija za temperaturu
		
		lcd_clrscr();
		lcd_home();
		lcd_print("T = %.2f%cC", T, 178);
		
		// kod za signalizaciju
		
		_delay_ms(1000);

	}	

	return 0;
}