/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 11.1.1
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include <avr/interrupt.h>

uint16_t brojac_int0, brojac_int1, brojac_int2;

ISR(INT0_vect) // prekidna rutina za INT0
{
	brojac_int0++;
}

ISR(INT1_vect) // prekidna rutina za INT1
{
	brojac_int1++;
}

ISR(INT2_vect) // prekidna rutina za INT2
{
	brojac_int2++;
}

void inicijalizacija(){
	
	// oba brida generiraju prekid INT0
	set_bit_reg(MCUCR,ISC00); // ISC00 = 1
	reset_bit_reg(MCUCR,ISC01); // ISC01 = 0
	// rastuæi brid generira prekid INT1
	set_bit_reg(MCUCR,ISC10); // ISC10 = 1
	set_bit_reg(MCUCR,ISC11); // ISC11 = 1
	// rastuæi brid generira prekid INT2
	reset_bit_reg(MCUCSR,ISC2); // ISC2 = 0

	set_bit_reg(GICR,INT0); // omoguæen vanjski prekid INT0
	set_bit_reg(GICR,INT1); // omoguæen vanjski prekid INT1
	set_bit_reg(GICR,INT2); // omoguæen vanjski prekid INT2
	
	sei(); // globalno omoguæenje prekida
	
	input_port(DDRD,PD2); // pin PD2 postavljen kao ulazni 
	set_port(PORTD,PD2,1); // ukljuèen pritezni otpornik na PD2
	input_port(DDRD,PD3); // pin PD3 postavljen kao ulazni 
	set_port(PORTD,PD3,1); // ukljuèen pritezni otpornik na PD3
	input_port(DDRB,PB2); // pin PB2 postavljen kao ulazni 
	set_port(PORTB,PB2,1); // ukljuèen pritezni otpornik na PB2
	
	lcd_init();
}

int main(void){
	
	inicijalizacija();
		
	while(1)
	{	
		lcd_clrscr();
		lcd_home();
		lcd_print("INT0=%d,INT1=%d\n", brojac_int0, brojac_int1);
		lcd_print("INT2=%d", brojac_int2);
		_delay_ms(200);
	}
	
	return 0;
}