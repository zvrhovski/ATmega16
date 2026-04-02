/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.1.2
 */ 


#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija(){
	
	DDRB |= (1 << PB7); // pin PB7 postavljen kao izlazni port
	PORTB |= (1 << PB7); // postavljanje pina PB7 u logièku jedinicu

}



int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	
	_delay_ms(1000); // funkcija kašnjenja koja kao argument prima vrijeme u ms
		
	set_port(PORTB,PB7,0); // postavljanje PB7 u logièku nulu
	
	_delay_us(1000000); // funkcija kašnjenja koja kao argument prima vrijeme u us
	
	set_port(PORTB,PB7,1);
	
	_delay_ms(1000);
		
	PORTB &= 0x7F; // postavljanje PB7 u logièku nulu
		
	_delay_us(1000000);
		
	set_port(PORTB,PB7,1);
	
	_delay_ms(1000);
	
	PORTB &= ~(1 << PB7); // postavljanje PB7 u logièku nulu

	// zašto led dioda ne izmijenjuje stanja nakon ove linije koda?	
	// što napraviti ????	
	
return 0;
	
}