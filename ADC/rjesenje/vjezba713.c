/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.3
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "ADC/adc.h"

	
void inicijalizacija(){
	
	//pinovi PB7, PB6, PB5 i PB4 postavljeni kao izlazni
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4);
	
	lcd_init(); // inicijalizacija lcd displeja
	adc_init(); // inicijalizacija AD pretvorbe
}

int main(void){
	
	
	inicijalizacija();

	uint16_t ADC5; // rezultat AD pretvorbe
	float VPA5; // napon na pinu PA5
	const float VREF = 5.0; // AVCC

	float yk; // y[k]
	float yk_1 = 0; // y[k-1]
	
	
	while(1)
	{
	
		ADC5 = adc_read_10bit(5);
		
		yk = 0.2 * yk_1 + 0.8 * ADC5;
		VPA5 = yk * VREF / 1023.0;
		
		lcd_clrscr();
		lcd_home();
		lcd_print("ADC5 = %.0f", yk);
		lcd_print("\nVPA5 = %.2fV", VPA5);
		
		_delay_ms(100);
		yk_1 = yk;		

		if(VPA5 < 1.25){
			
			set_port(PORTB,PB4,1);
			set_port(PORTB,PB5,0);
			set_port(PORTB,PB6,0);
			set_port(PORTB,PB7,0);
		}
		
		if(VPA5 >= 1.25 && VPA5 < 2.5){
			
			set_port(PORTB,PB4,1);
			set_port(PORTB,PB5,1);
			set_port(PORTB,PB6,0);
			set_port(PORTB,PB7,0);
		}

		if(VPA5 >= 2.5 && VPA5 < 3.75){
			
			set_port(PORTB,PB4,1);
			set_port(PORTB,PB5,1);
			set_port(PORTB,PB6,1);
			set_port(PORTB,PB7,0);
		}
		
		if(VPA5 >= 3.75){
			
			set_port(PORTB,PB4,1);
			set_port(PORTB,PB5,1);
			set_port(PORTB,PB6,1);
			set_port(PORTB,PB7,1);
		}

	}	

	return 0;
	
}