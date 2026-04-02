/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.7
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>

uint32_t brojac_prekida = 0;

ISR(TIMER0_OVF_vect){ // prekidna rutina za timer0
	brojac_prekida++;
}


void inicijalizacija(){
	
	input_port(DDRB,PB0); // pin PB0 postavljen kao ulazni
	set_port(PORTB,PB0,1); // ukljuèen pritezni otpornik na PB0
	
	lcd_init();
	
	//normalan naèin rada
	reset_bit_reg(TCCR0,WGM00); //WGM00 = 0
	reset_bit_reg(TCCR0,WGM01); //WGM01 = 0
	// broji rastuæe bridove
	set_bit_reg(TCCR0,CS00); // CS00 = 1
	set_bit_reg(TCCR0,CS01); // CS01 = 1
	set_bit_reg(TCCR0,CS02); // CS02 = 1
	// omoguæi prekid TOV0
	set_bit_reg(TIMSK,TOIE0); // TOIE0 = 1
	
	sei(); // globalno omoguæenje prekida
}
		

int main(void){

	inicijalizacija(); 
				
	while(1)
	{
		lcd_clrscr(); 
		lcd_home(); 
		lcd_print("Brojac: %lu", 256 * brojac_prekida + TCNT0);
		_delay_ms(1000); 	
	}
	      	
	return 0;
}