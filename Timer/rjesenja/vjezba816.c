/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 8.1.6
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "timer/timer.h"
#include <avr/interrupt.h>
#include "ADC/adc.h"


uint16_t ADC5; // rezultat AD pretvorbe
float VPA5; // napon na pinu PA5
const float VREF = 5.0; // AVCC

uint8_t uzorak_procitan = 0; // logièka varijabla
	

ISR(TIMER1_OVF_vect){ // prekidna rutina za timer1
	TCNT1 = 3036; 
	
	ADC5 = adc_read_10bit(5);
	VPA5 = ADC5 * VREF / 1023; 
	uzorak_procitan = 1;
		
}


void inicijalizacija(){
	
	input_port(DDRB,PB0); // pin PB0 pstavljen kao izlazni
	set_port(PORTB,PB0,1); // ukljuèen pritezni otpornik na PB0
	
	lcd_init();
	adc_init();

	//normalan naèin rada - timer1
	reset_bit_reg(TCCR1A,WGM10); // WGM10 = 0
	reset_bit_reg(TCCR1A,WGM11); // WGM11 = 0
	reset_bit_reg(TCCR1B,WGM12); // WGM12 = 0
	reset_bit_reg(TCCR1B,WGM13); // WGM13 = 0
	// F_CPU / 64
	set_bit_reg(TCCR1B,CS10); // CS10 = 1
	set_bit_reg(TCCR1B,CS11); // CS11 = 1
	reset_bit_reg(TCCR1B,CS12); // CS12 = 0
	
	sei(); // globalno omoguæenje prekida
	TCNT1 = 3036; 
}


int main(void){

	inicijalizacija();
	
	
	while(1)
	{

		if (uzorak_procitan == 1)
		{
			lcd_clrscr();
			lcd_home();
			lcd_print("Napon : %.2f V", VPA5);
			uzorak_procitan = 0;
		}

		if (get_pin(PINB,PB0) == 0)
		{
			set_bit_reg(TIMSK,TOIE1); // TOIE1 = 1
		}
		else
		{
			reset_bit_reg(TIMSK,TOIE1); // TOIE1 = 0
		}
		
	}
	
	return 0;
}