/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.8
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "timer/timer.h"
#include <util/delay.h>

void inicijalizacija(){
	
	//Fast PWM naèin rada
	set_bit_reg(TCCR0,WGM00); //WGM00 = 1
	set_bit_reg(TCCR0,WGM01); //WGM01 = 1
	// F_CPU/8
	reset_bit_reg(TCCR0,CS00); // CS00 = 0
	set_bit_reg(TCCR0,CS01); // CS01 = 1
	reset_bit_reg(TCCR0,CS02); // CS02 = 0
	
	//neinvertirajuæi PWM
	reset_bit_reg(TCCR0,COM00); // COM00 = 0
	set_bit_reg(TCCR0,COM01); // COM01 = 1
	
	output_port(DDRB,PB3); // pin PB3 postavljen kao izlazni pin
	
	OCR0 = 0; // duty cycle
	
}
		

int main(void){

	inicijalizacija(); 
				
	while(1)
	{
		_delay_ms(1000); // kašnjenje 1 s
	}
	
	return 0;
}