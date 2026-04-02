/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.1
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
	
	while(1)
	{
		lcd_clrscr(); 
		lcd_home(); 
	
		ADC5 = adc_read_10bit(5);
		VPA5 = ADC5 * VREF / 1024.0;
	
		lcd_print("ADC5 = %d", ADC5);
		lcd_print("\nVPA5 = %.2fV", VPA5);
		_delay_ms(1000);
	
	}	

	return 0;
}