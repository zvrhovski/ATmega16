/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 12.1.3
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "ADC/adc.h"
#include <util/delay.h>


void inicijalizacija(){
	
	adc_init();
	lcd_init();
}

int main(void){
	
	inicijalizacija();

	uint16_t ADC5; // rezultat AD pretvorbe
	float Vout; // napon na pinu PA0
	float T; // temperatura u okolini senzora LM35
	const float VREF = 5.0; // AVCC
		
		while (1)
		{
		
			ADC5 = adc_read_10bit(0);
			Vout = ADC5 * VREF / 1023;
			
			T = Vout * 100;
			
			lcd_clrscr();
			lcd_home();
			lcd_print("T = %0.2f%cC", T, 178);
			_delay_ms(500);
		} 
	
return 0;	
}