/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.2.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	output_port(DDRB,PB7); // PB7 postavljen kao izlazni pin

	input_port(DDRB,PB3); // PB3 postavljen kao ulazni pin
	
	set_port(PORTB,PB3,1); // ukljuèen pritezni otpornik na PB3
}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	int pinb3 = 1; // stara vrijednost ulaznog pina PB3
	
	while (1)
	{
		// na padajuæi brid pina PB3 promijeni stanje crvene LED diode
		if(pinb3 == 1 && debounce(&PINB, PB3, 0) != pinb3){
			TOGGLE_PORT(PORTB,PB7);
			pinb3 = 0;
		}
		
		if(get_pin(PINB,PB3))
		pinb3 = 1;
		
		// nastavite za ostala tipkala
	}
	
	return 0;
}