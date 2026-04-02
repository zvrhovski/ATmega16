/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Zadatak 4 - PWM
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include "ADC/adc.h"

void inicijalizacija(){
	
	lcd_init();
	adc_init();
	

	
}
		

int main(void){

	inicijalizacija(); 
	
	uint32_t ADC5;			

	while(1)
	{
		ADC5 = adc_read_10bit(5);
	
		// ostvarite promjenu širine impulsa pomoæu potenciometra
		//OCR1A = 
		//OCR1B = 
		
		lcd_clrscr();
		lcd_home();
		lcd_print("PWM freq:%luHz\n", F_CPU / 1 / 256);
		lcd_print("TD/T:%u%%", ADC5 * 100 / 1023);
		_delay_ms(500);
	}
	
	return 0;
}