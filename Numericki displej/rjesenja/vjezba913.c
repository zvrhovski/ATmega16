/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 9.1.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija(){
	
	// pinovi PD7, PD6, PD5 i PD4 postavljeni kao izlazni
	DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4); 
	// pinovi PD7, PD6, PD5 i PD4 postavljeni u visoko stanje
	// onemoguæen je prikaz znamenaka na svim numerièkim displejima
	PORTD |= ((1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4));
	
	DDRC = 0xFF; // svi pinovi na port C postavljeni kao izlazni
	PORTC = 0xFF; // inicijalno ukljuèeni svi pinovi/iskljuèeni segmenti
	
	input_port(DDRB,PB0); // pin PB0 postavljen kao ulazni pin
	set_port(PORTB, PB0, 1); // ukljuèen pritezni otpornik na PB0
	
}

int main(void){
	
	inicijalizacija();
	
	while (1)
	{
		
		set_port(PORTD, PD7, 1); // onemoguæi DISP4
		set_port(PORTD, PD4, 0); // omoguæi DISP1
		PORTC = 0xB7; // 1
		_delay_ms(5);
		
		set_port(PORTD, PD4, 1); // onemoguæi DISP1
		set_port(PORTD, PD5, 0); // omoguæi DISP2
		PORTC = 0xC1; // 2
		_delay_ms(5);

		set_port(PORTD, PD5, 1); // onemoguæi DISP2
		set_port(PORTD, PD6, 0); // omoguæi DISP3
		PORTC = 0xA1; // 3
		_delay_ms(5);
		
		set_port(PORTD, PD6, 1); // onemoguæi DISP3
		set_port(PORTD, PD7, 0); // omoguæi DISP4
		PORTC = 0xB2; // 4
		_delay_ms(5);
		
		
		if (get_pin(PINB, PB0) == 0)
		{
			_delay_ms(2000);
		}
		
	}
	
return 0;
}