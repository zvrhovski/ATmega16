/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Zadatak 1 - PWM
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "timer/timer.h"
#include <util/delay.h>

void inicijalizacija(){
	
	//Phase Correct PWM naèin rada
	set_bit_reg(TCCR0,WGM00); //WGM00 = 1
	reset_bit_reg(TCCR0,WGM01); //WGM01 = 0
	// F_CPU/1

	
	//neinvertirajuæi PWM

	
	output_port(DDRB,PB3); // pin PB3 postavljen kao izlazni pin
	
	// namjestiti OCR0 tako da duty cycle bude 20%
	OCR0 = 0; 
	
}
		

int main(void){

	inicijalizacija(); 
				
	while(1)
	{
		_delay_ms(1000); // kašnjenje 1 s
	}
	
	return 0;
}