/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.1
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect){ // prekidna rutina za timer0
	TCNT0 = 60; // poèetna vrijednost registra
	TOGGLE_PORT(PORTB, PB7);
}


void inicijalizacija(){
	
	output_port(DDRB,PB7); // pin PB7 postavljen kao izlazni
	set_port(PORTB,PB7,1); // poèetno stanje crvene LED diode
	
	lcd_init();
	timer0_init();
	sei(); // globalno omoguæenje prekida
	TCNT0 = 60; // poèetna vrijednost registra
}
		

int main(void){

	inicijalizacija(); 
	
	uint16_t minute = 0;
			
	while(1)
	{
		lcd_clrscr(); 
		lcd_home(); 
		lcd_print("ON : %u min", minute++);
		_delay_ms(60000); // kašnjenje 60 s		
	}
	      	
	return 0;
}