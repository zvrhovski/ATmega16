/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.4
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

	uint16_t ADC5; // rezultat AD pretvorbe
	float VPA5; // napon na pinu PA5
	const float VREF = 5.0; // AVCC
	float u, p;
	
	
	while(1){
	
		ADC5 = adc_read_10bit(5); 
	
		VPA5 = ADC5 * VREF / 1023; 
		
		u = VPA5;
	
		if (u <= 2.0)
		{		
			p = 9 * u / 2 + 1; 
		}
		else
		{
			p = 5 * u / 3 + 20.0 / 3;
		}

		lcd_clrscr(); 
		lcd_home(); 

		lcd_print("VPA5 = %.3fV", u);
		lcd_print("\nTlak = %.3fbar", p);
		_delay_ms(1000);
	
	
	}	

	return 0;
	
}