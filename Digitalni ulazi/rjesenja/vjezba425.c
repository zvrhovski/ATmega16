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
	output_port(DDRB,PB6); // PB6 postavljen kao izlazni pin
	output_port(DDRB,PB5); // PB5 postavljen kao izlazni pin
	output_port(DDRB,PB4); // PB4 postavljen kao izlazni pin

	input_port(DDRB,PB3); // PB3 postavljen kao ulazni pin
	input_port(DDRB,PB2); // PB2 postavljen kao ulazni pin
	input_port(DDRB,PB1); // PB1 postavljen kao ulazni pin
	input_port(DDRB,PB0); // PB0 postavljen kao ulazni pin
	
	set_port(PORTB,PB3,1); // ukljuèen pritezni otpornik na PB3
	set_port(PORTB,PB2,1); // ukljuèen pritezni otpornik na PB2
	set_port(PORTB,PB1,1); // ukljuèen pritezni otpornik na PB1
	set_port(PORTB,PB0,1); // ukljuèen pritezni otpornik na PB0
}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	int pinb3 = 1; // stara vrijednost ulaznog pina PB3
	int pinb2 = 1; // stara vrijednost ulaznog pina PB2
	int pinb1 = 1; // stara vrijednost ulaznog pina PB1
	int pinb0 = 1; // stara vrijednost ulaznog pina PB0
	
	while (1)
	{
		// na padajuæi brid pina PB3 promijeni stanje crvene LED diode
		if(pinb3 == 1 && debounce(&PINB, PB3, 0) != pinb3){
			TOGGLE_PORT(PORTB,PB7);
			pinb3 = 0;
		}
		
		if(get_pin(PINB,PB3))
		pinb3 = 1;
		
		// na padajuæi brid pina PB2 promijeni stanje žute LED diode
		if(pinb2 == 1 && debounce(&PINB, PB2, 0) != pinb2){
			TOGGLE_PORT(PORTB,PB6);
			pinb2 = 0;
		}
		
		if(get_pin(PINB,PB2))
		pinb2 = 1;

		// na padajuæi brid pina PB1 promijeni stanje zelene LED diode
		if(pinb1 == 1 && debounce(&PINB, PB1, 0) != pinb1){
			TOGGLE_PORT(PORTB,PB5);
			pinb1 = 0;
		}
		
		if(get_pin(PINB,PB1))
		pinb1 = 1;

		// na padajuæi brid pina PB0 promijeni stanje bijele LED diode
		if(pinb0 == 1 && debounce(&PINB, PB0, 0) != pinb0){
			TOGGLE_PORT(PORTB,PB4);
			pinb0 = 0;
		}
		
		if(get_pin(PINB,PB0))
		pinb0 = 1;
	}
	
	return 0;
}