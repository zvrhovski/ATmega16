/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>

uint8_t prazan_hod = 0;

ISR(TIMER2_OVF_vect){ // prekidna rutina za timer2
	TCNT2 = 61; // poèetna vrijednost registra
	prazan_hod++;
	if (prazan_hod == 4)
	{
		TOGGLE_PORT(PORTB, PB7);
		prazan_hod = 0;
	}	
}


void inicijalizacija(){
	
	output_port(DDRB,PB7); // pin PB7 postavljen kao izlazni
	set_port(PORTB,PB7,1); // poèetno stanje crvene LED diode
	
	lcd_init();
	
	//normalan naèin rada
	reset_bit_reg(TCCR2,WGM20); //WGM20 = 0
	reset_bit_reg(TCCR2,WGM21); //WGM21 = 0
	// F_CPU / 1024
	set_bit_reg(TCCR2,CS20); // CS20 = 1
	set_bit_reg(TCCR2,CS21); // CS21 = 1
	set_bit_reg(TCCR2,CS22); // CS22 = 1
	// omoguæi prekid TOV2
	set_bit_reg(TIMSK,TOIE2); // TOIE2 = 1
	
	sei();
	TCNT2 = 61; // poèetna vrijednost registra
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