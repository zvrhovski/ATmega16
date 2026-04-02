/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Zadatak 3 - PWM
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include "ADC/adc.h"

void inicijalizacija(){
	
	lcd_init();
	adc_init();
	
	//Phase Correct PWM naèin rada - 10 bitni (0 - 1023) - idealan za potenciometar
	set_bit_reg(TCCR1A,WGM10); //WGM10 = 1
	set_bit_reg(TCCR1A,WGM11); //WGM11 = 1
	set_bit_reg(TCCR1B,WGM12); //WGM12 = 1
	reset_bit_reg(TCCR1B,WGM13); //WGM13 = 0
	// F_CPU/1
	set_bit_reg(TCCR1B,CS10); // CS10 = 1
	reset_bit_reg(TCCR1B,CS11); // CS11 = 0
	reset_bit_reg(TCCR1B,CS12); // CS12 = 0
	
	//neinvertirajuæi PWM za oba kanala
	reset_bit_reg(TCCR1A,COM1A0); // COM1A0 = 0
	set_bit_reg(TCCR1A,COM1A1); // COM1A1 = 1

	reset_bit_reg(TCCR1A,COM1B0); // COM1B0 = 0
	set_bit_reg(TCCR1A,COM1B1); // COM1B1 = 1
		
	output_port(DDRD,PD4); // pin PD4 postavljen kao izlazni pin
	output_port(DDRD,PD5); // pin PD5 postavljen kao izlazni pin
	
}
		

int main(void){

	inicijalizacija(); 
	
	uint32_t ADC5;			

	while(1)
	{
		ADC5 = adc_read_10bit(5);
	
		// ostvarite promjenu širine impulsa pomoæu potenciometra - pogledati vježba819.c
		OCR1A = ADC5;
		OCR1B = ADC5;
		
		lcd_clrscr();
		lcd_home();
		lcd_print("PWM freq:%luHz\n", F_CPU / 1 / 256);
		lcd_print("TD/T:%u%%", ADC5 * 100 / 1023);
		_delay_ms(500);
	}
	
	return 0;
}