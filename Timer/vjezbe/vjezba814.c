/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.4
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>


ISR(TIMER0_OVF_vect){ // prekidna rutina za timer0
	TCNT0 = 0; // poèetna vrijednost registra
	TOGGLE_PORT(PORTB, PB7);
}

ISR(TIMER1_OVF_vect){ // prekidna rutina za timer1
	TCNT1 = 0; // poèetna vrijednost registra za
	TOGGLE_PORT(PORTB, PB7);
}

ISR(TIMER2_OVF_vect){ // prekidna rutina za timer2
	TCNT2 = 0; // poèetna vrijednost registra za
	TOGGLE_PORT(PORTB, PB7);
}


void inicijalizacija(){
	
	output_port(DDRB,PB6); // pin PB7 postavljen kao izlazni
	set_port(PORTB,PB6,1); // poèetno stanje crvene LED diode
	output_port(DDRB,PB6); // pin PB6 postavljen kao izlazni
	set_port(PORTB,PB6,1); // poèetno stanje žute LED diode
	output_port(DDRB,PB5); // pin PB5 postavljen kao izlazni
	set_port(PORTB,PB5,1); // poèetno stanje zelene LED diode
	
	lcd_init();
	
	// inicijalizacija svih tajmera
	timer0_init();
	timer1_init();
	timer2_init();
	
	sei(); // globalno omoguæenje prekida
	TCNT0 = 0;
	TCNT1 = 0; // poèetna vrijednost registra za 50 ms
	TCNT2 = 0;
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