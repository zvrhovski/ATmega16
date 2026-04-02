/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 9.1.2
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>

void inicijalizacija(){
	
	// pinovi PD7, PD6, PD5 i PD4 postavljeni kao izlazni
	DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4); 
	// pinovi PD7, PD6, PD5 i PD4 postavljeni u nisko stanje
	// omoguæen je prikaz znamenaka na svim numerièkim displejima
	PORTD &= ~((1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4));
	
	DDRC = 0xFF; // svi pinovi na port C postavljeni kao izlazni
	PORTC = 0xFF; // inicijalno ukljuèeni svi pinovi/iskljuèeni segmenti
}

int main(void){
	
	inicijalizacija();
	
	//u PORTC upisati vrijednost koja æe ostvariti prikaz zadanih znakova
	
return 0;
}