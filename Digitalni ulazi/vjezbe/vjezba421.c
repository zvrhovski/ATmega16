/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.2.1
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	output_port(DDRB,PB7); // PB7 postavljen kao izlazni pin
	output_port(DDRB,PB6); // PB6 postavljen kao izlazni pin
	output_port(DDRB,PB5); // PB5 postavljen kao izlazni pin
	output_port(DDRB,PB4); // PB4 postavljen kao izlazni pin

	input_port(DDRB,PB0); // PB0 postavljen kao ulazni pin
	set_port(PORTB,PB0,1); // ukljuèenje priteznog otpornika na PB0
	
}

int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	while (1)
	{
		if((PINB & 0x01) == 0x00){ // ako je pin PB0 u logièkoj nuli
		PORTB |= 0xF0;       // ukljuèi sve led diode
		}
		else{
		PORTB &= ~0xF0;	   // inaèe ih iskljuèi
		}
		
	}

	return 0;
}