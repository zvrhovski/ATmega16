/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 9.1.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "timer/timer.h"
#include <avr/interrupt.h>
#include "SSD/SSD.h"
#include <util/delay.h>
#include "ADC/adc.h"

uint8_t brojac;
uint8_t z1, z2, z3, z4; // znamenke za prikaz

ISR(TIMER1_OVF_vect){ // prekidna rutina za timer1
	TCNT1 = 60536; // poèetna vrijednost registra za 50 ms
	
		switch (++brojac)
		{
			case 1:
			set_port(PORTD, PD7, 1); // onemoguæi DISP4
			set_port(PORTD, PD4, 0); // omoguæi DISP1
			PORTC = znakovi[z1];
			set_port(PORTC,PC7,0); // ukljuèenje toèke
			break;
			case 2:
			set_port(PORTD, PD4, 1); // onemoguæi DISP1
			set_port(PORTD, PD5, 0); // omoguæi DISP2
			PORTC = znakovi[z2];
			break;
			case 3:
			set_port(PORTD, PD5, 1); // onemoguæi DISP2
			set_port(PORTD, PD6, 0); // omoguæi DISP3
			PORTC = znakovi[z3];			
			break;
			case 4:
			set_port(PORTD, PD6, 1); // onemoguæi DISP3
			set_port(PORTD, PD7, 0); // omoguæi DISP4
			PORTC = znakovi[z4];			
			brojac = 0;
			break;
		}
}


void inicijalizacija(){
	
	adc_init();
	
	// pinovi PD7, PD6, PD5 i PD4 postavljeni kao izlazni
	DDRD |= (1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4);
	// pinovi PD7, PD6, PD5 i PD4 postavljeni u visoko stanje
	// onemoguæen je prikaz znamenaka na svim numerièkim displejima
	PORTD |= ((1 << PD7) | (1 << PD6) | (1 << PD5) | (1 << PD4));
	
	DDRC = 0xFF; // svi pinovi na port C postavljeni kao izlazni
	PORTC = 0xFF; // inicijalno ukljuèeni svi pinovi/iskljuèeni segmenti
	
	input_port(DDRB,PB0); // pin PB0 postavljen kao ulazni pin
	set_port(PORTB, PB0, 1); // ukljuèen pritezni otpornik na PB0
	
	//normalan naèin rada - timer1
	reset_bit_reg(TCCR1A,WGM10); // WGM10 = 0
	reset_bit_reg(TCCR1A,WGM11); // WGM11 = 0
	reset_bit_reg(TCCR1B,WGM12); // WGM12 = 0
	reset_bit_reg(TCCR1B,WGM13); // WGM13 = 0
	// F_CPU / 8
	reset_bit_reg(TCCR1B,CS10); // CS10 = 0
	set_bit_reg(TCCR1B,CS11); // CS11 = 1
	reset_bit_reg(TCCR1B,CS12); // CS12 = 0
	// omoguæi prekid TOV1
	set_bit_reg(TIMSK,TOIE1); // TOIE1 = 1
	
	sei(); // globalno omoguæenje prekida
	TCNT1 = 60536; // poèetna vrijednost registra za 50 ms
}


int main(void){

	inicijalizacija();
	
	uint32_t ADC5;
	uint32_t VADC5;
	
	while(1)
	{
		ADC5 = adc_read_10bit(5);
			
		VADC5 = ADC5 * 5000 / 1023;
			
		z1 = VADC5 / 1000; 
		z2 = (VADC5 / 100) % 10;
		z3 = (VADC5 / 10) % 10;
		z4 = VADC5 % 10;
	}
	
	return 0;
}
