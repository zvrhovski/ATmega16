/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.2.4
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>


void inicijalizacija(){
	// s obzirom da znamo funkciju svih digitalnih pinova na portu B,
	// inicijalizacija se može izvesti na sljedeæi naèin:
	DDRB = 0xF0; 
	PORTB = 0x0F;
}


int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	while (1)
	{
		
		if(debounce(&PINB, PB3, 0) == 0){ // funkcija debounce filtrira smetnje
		set_port(PORTB, PB7, 1);				  
		}
		else{
		set_port(PORTB, PB7, 0);
		}
		
		if(debounce(&PINB, PB2, 0) == 0){ // funkcija debounce filtrira smetnje
		set_port(PORTB, PB6, 1);				 
		}
		else{
		set_port(PORTB, PB6, 0);
		}
		
		if(debounce(&PINB, PB1, 0) == 0){ // funkcija debounce filtrira smetnje
		set_port(PORTB, PB5, 1);				  
		}
		else{
		set_port(PORTB, PB5, 0);
		}
	
		if(debounce(&PINB, PB0, 0) == 0){ // funkcija debounce filtrira smetnje
		set_port(PORTB, PB4, 1);				  
		}
		else{
		set_port(PORTB, PB4, 0);
		}

	}

	return 0;
	
}