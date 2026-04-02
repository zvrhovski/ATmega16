/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.1.6
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija(){
	
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4); // PB7, PB6, PB5 i PB4 izlazni pinovi
	PORTB |= (1 << PB7); // postavljanje PB7 u visoko stanje

}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	for (char i = 0; i < 50; i++){
		
	_delay_ms(100); // kašnjenje 100 ms
	
	TOGGLE_PORT(PORTB,PB7); // Promijeni stanje pina PB7
	
	TOGGLE_PORT(PORTB,PB6); // Promijeni stanje pina PB6
	
	_delay_ms(100); // kašnjenje 100 ms
	
	TOGGLE_PORT(PORTB,PB6); // Promijeni stanje pina PB6
	
	TOGGLE_PORT(PORTB,PB5); // Promijeni stanje pina PB5

	_delay_ms(100); // kašnjenje 100 ms
	
	TOGGLE_PORT(PORTB,PB5); // Promijeni stanje pina PB5
	
	TOGGLE_PORT(PORTB,PB4); // Promijeni stanje pina PB4

	_delay_ms(100); // kašnjenje 100 ms
	
	TOGGLE_PORT(PORTB,PB4); // Promijeni stanje pina PB4
	
	TOGGLE_PORT(PORTB,PB7); // Promijeni stanje pina PB7
	
	}
	
	// ovdje ugasiti crvenu LED diodu
	set_port(PORTB,PB7,0); // Stanje pina PB7 postavi u nisko
	
	return 0;
	
}