/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>

uint8_t brojac = 0;

ISR(TIMER1_OVF_vect){ // prekidna rutina za timer1
	TCNT1 = 15536; 
	brojac++;
	switch (brojac)
	{
	case 1:
		set_port(PORTB,PB7,1);
		set_port(PORTB,PB4,0);
		break;
	case 2:
		set_port(PORTB,PB6,1);
		set_port(PORTB,PB7,0);
		break;
	case 3:
		set_port(PORTB,PB5,1);
		set_port(PORTB,PB6,0);
		break;
	case 4:
		set_port(PORTB,PB4,1);
		set_port(PORTB,PB5,0);
		brojac = 0;
		break;
	default:
		break;
	}
	
}


void inicijalizacija(){
	
	output_port(DDRB,PB7); // pin PB7 postavljen kao izlazni
	output_port(DDRB,PB6); // pin PB6 postavljen kao izlazni
	output_port(DDRB,PB5); // pin PB5 postavljen kao izlazni
	output_port(DDRB,PB4); // pin PB4 postavljen kao izlazni
		
	lcd_init();
	
	timer1_init();
	
	sei(); // globalno omoguæenje prekida
	TCNT1 = 15536; 
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