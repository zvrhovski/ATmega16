/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 12.1.1
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	output_port(DDRA,PA3); // pin PA3 postavljen kao izlazni
	
	input_port(DDRB,PB1); // pin PB1 postavljen kao ulazni
	set_port(PORTB,PB1,1); // ukljuèen pritezni otpornik na PB1
}

int main(void){
	
	inicijalizacija();
	
	while (1){
		
		set_port(PORTA,PA3,!get_pin(PINB,PB1));
		
	}
	
	return 0;
}