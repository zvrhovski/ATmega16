/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.2.2
 */ 


#include "AVR lib/AVR_lib.h"
#include <avr/io.h>


void inicijalizacija(){
	
	// PB7,PB6,PB5,i PB4 postavljeni kao izlazni pinovi
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4); 
	// PB3,PB2,PB1,i PB0 postavljeni kao izlazni pinovi
	DDRB &= ~((1 << PB3) | (1 << PB2) | (1 << PB1) | (1 << PB0)); 
	// pritezni otpornici ukljuèeni na pinovima PB3,PB2,PB1,i PB0
	PORTB |= (1 << PB3) | (1 << PB2) | (1 << PB1) | (1 << PB0);
}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	while (1)
	{
		
		if((PINB & 0x08) == 0x00){ // ako je pin PB3 u logièkoj nuli
		PORTB |= (1 << PB7);       // ukljuèi crvenu LED diodu
		}
		else{
		PORTB &= ~(1 << PB7);	   // inaèe je iskljuèi
		}
		
		if((PINB & 0x04) == 0x00){	// ako je pin PB2 u logièkoj nuli
			PORTB |= (1 << PB6);	// ukljuèi žutu LED diodu
		}
		else{
			PORTB &= ~(1 << PB6);	// inaèe je iskljuèi
		}
		
		
		if((PINB & 0x02) == 0x00){	// ako je pin PB1 u logièkoj nuli
			PORTB |= (1 << PB5);	// ukljuèi zelenu LED diodu
		}
		else{
			PORTB &= ~(1 << PB5);	// inaèe je iskljuèi
		}

	
		if((PINB & 0x01) == 0x00){	// ako je pin PB0 u logièkoj nuli
			PORTB |= (1 << PB4);	// ukljuèi vijelu LED diodu
		}
		else{
			PORTB &= ~(1 << PB4);	// inaèe je iskljuèi
		}

	}

	return 0;
	
}