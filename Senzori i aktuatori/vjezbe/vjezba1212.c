/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 12.1.2
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include <avr/interrupt.h>

uint16_t broj_impulsa = 0;

ISR(INT0_vect) // prekidna rutina za INT0
{
	// ako je brid rastuæi
	if(get_pin(PIND,PD2) == 1){
		TCNT1 = 0; // t1 = 0
	}
	else // ako je brid padajuæi
	{
		broj_impulsa = TCNT1; // t2 = TCNT1
	}
}

void inicijalizacija(){
	
	lcd_init();
	
	// oba brida generiraju prekid INT0
	set_bit_reg(MCUCR,ISC00);
	reset_bit_reg(MCUCR,ISC01);
	
	set_bit_reg(GICR,INT0); // omoguæenje vanjskog prekida INT0
	
	//F_CPU/8 za timer1
	reset_bit_reg(TCCR1B,CS10);
	set_bit_reg(TCCR1B,CS11);
		
	output_port(DDRB,PB4); // pin PB4 postavljen kao izlazni
	input_port(DDRD,PD2); // PD2 postavljen kao ulazni
	sei(); // globalno omoguæenje prekida
}

int main(void){
	
	inicijalizacija();
	
	float d;
	
	while (1){
		
		set_port(PORTB, PB4, 1);
		_delay_us(20); // trigger impuls
		set_port(PORTB, PB4, 0);
		_delay_ms(500);
		
		// relacija za proraèun udaljenosti u cm
		
		// ispis udaljenosti na LCD displej
	}
	
	return 0;
}