/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 4.1.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include <util/delay.h>


void inicijalizacija(){
	
	DDRB |= (1 << PB7); // PORTB7 postavljen kao izlazni port
	PORTB |= (1 << PB7); // postavljanje PORT7 u logièku jedinicu

}

int main(void){
	
	
	inicijalizacija(); // inicijalizacija mikrokontrolera
	
	
	
	while (1) // beskonaèna petlja u kojoj mikrokontroler ostaje dok god ima napajanja te dok nije u RESET-u
	{
	
	_delay_ms(1000); // funkcija kašnjenja koja kao argument prima vrijeme u ms
	
	TOGGLE_PORT(PORTB,PB7); // promijeni stanje PB7
	
	}
	
	return 0;
	
}