/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Zadatak 2 - PWM
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include "ADC/adc.h"

void inicijalizacija(){
	
	lcd_init();
	adc_init();
	
	//Phase Correct PWM naèin rada
	set_bit_reg(TCCR0,WGM00); //WGM00 = 1
	reset_bit_reg(TCCR0,WGM01); //WGM01 = 0
	// F_CPU/1
	set_bit_reg(TCCR0,CS00); // CS00 = 1
	reset_bit_reg(TCCR0,CS01); // CS01 = 0
	reset_bit_reg(TCCR0,CS02); // CS02 = 0
	
	//neinvertirajuæi PWM
	reset_bit_reg(TCCR0,COM00); // COM00 = 0
	set_bit_reg(TCCR0,COM01); // COM01 = 1
	
	output_port(DDRB,PB3); // pin PB3 postavljen kao izlazni pin
	
}
		

int main(void){

	inicijalizacija(); 
	
	uint32_t ADC5;			

	while(1)
	{
		ADC5 = adc_read_10bit(5);
	
		// ostvarite promjenu širine impulsa pomoæu potenciometra - pogledati vježba819.c
		OCR0 = ADC5 * 255 / 1023;
		
		lcd_clrscr();
		lcd_home();
		lcd_print("PWM freq:%luHz\n", F_CPU / 1 / 256);
		lcd_print("TD/T:%u%%", ADC5 * 100 / 1023);
		_delay_ms(500);
	}
	
	return 0;
}