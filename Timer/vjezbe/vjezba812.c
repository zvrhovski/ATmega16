/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.2
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>


ISR(TIMER1_OVF_vect){ // prekidna rutina za timer1
	TCNT1 = 0; // poèetna vrijednost registra
	TOGGLE_PORT(PORTB, PB7);
}


void inicijalizacija(){
	
	output_port(DDRB,PB7); // pin PB7 postavljen kao izlazni
	set_port(PORTB,PB7,1); // poèetno stanje crvene LED diode
	
	lcd_init();
	
	//normalan naèin rada - timer1
	reset_bit_reg(TCCR1A,WGM10); // WGM10 = 0
	reset_bit_reg(TCCR1A,WGM11); // WGM11 = 0
	reset_bit_reg(TCCR1B,WGM12); // WGM12 = 0
	reset_bit_reg(TCCR1B,WGM13); // WGM13 = 0
	// F_CPU / 64
	set_bit_reg(TCCR1B,CS10); // CS10 = 1
	set_bit_reg(TCCR1B,CS11); // CS11 = 1
	reset_bit_reg(TCCR1B,CS12); // CS12 = 0
	// omoguæi prekid TOV1
	set_bit_reg(TIMSK,TOIE1); // TOIE1 = 1
	
	sei(); // globalno omoguæenje prekida
	TCNT1 = 0; // poèetna vrijednost registra
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