/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.2.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	output_port(DDRB,PB7); // PB7 postavljen kao izlazni pin
	output_port(DDRB,PB6); // PB6 postavljen kao izlazni pin
	output_port(DDRB,PB5); // PB5 postavljen kao izlazni pin
	output_port(DDRB,PB4); // PB4 postavljen kao izlazni pin

	input_port(DDRB,PB3); // PB3 postavljen kao ulazni pin
	input_port(DDRB,PB2); // PB2 postavljen kao ulazni pin
	input_port(DDRB,PB1); // PB1 postavljen kao ulazni pin
	input_port(DDRB,PB0); // PB0 postavljen kao ulazni pin
	
	set_port(PORTB,PB3,1); // ukljuèivanje priteznog otpornika na PB3
	set_port(PORTB,PB2,1); // ukljuèivanje priteznog otpornika na PB2
	set_port(PORTB,PB1,1); // ukljuèivanje priteznog otpornika na PB1
	set_port(PORTB,PB0,1); // ukljuèivanje priteznog otpornika na PB0	
}

int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	while (1)
	{
		
		if(get_pin(PINB,PB3) == 0){ // ako je pin PB3 u niskom stanju
		set_port(PORTB, PB7, 1);	// ukljuèi crvenu LED diodu
		}
		else{
		set_port(PORTB, PB7, 0);	// iskljuèi crvenu LED diodu
		}
		
		// nastavite za ostala tipkala
	}

	return 0;
	
}