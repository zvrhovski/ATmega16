/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.5
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "ADC/adc.h"

	
void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
	adc_init(); // inicijalizacija AD pretvorbe
}

int main(void){
	
	
	inicijalizacija();

	uint16_t ADC6; // rezultat AD pretvorbe
	float T;
	
	while(1)
	{	
		ADC6 = adc_read_10bit(6);
		T = 3435 / (log(ADC6 / (1024.0 - ADC6)) + 10.861) - 273.15; 
		
		lcd_clrscr();
		lcd_home();
		lcd_print("T = %.2f%cC", T, 178);
		
			if(T < 25.0){ // signalizacija po istom principu kao u daatoteci vjezba713.c
				
				set_port(PORTB,PB4,1);
				set_port(PORTB,PB5,0);
				set_port(PORTB,PB6,0);
				set_port(PORTB,PB7,0);
			}
			
			if(T >= 25.0 && T < 27.5){
				
				set_port(PORTB,PB4,1);
				set_port(PORTB,PB5,1);
				set_port(PORTB,PB6,0);
				set_port(PORTB,PB7,0);
			}

			if(T >= 27.5 && T < 30.0){
				
				set_port(PORTB,PB4,1);
				set_port(PORTB,PB5,1);
				set_port(PORTB,PB6,1);
				set_port(PORTB,PB7,0);
			}
			
			if(T >= 30.0){
				
				set_port(PORTB,PB4,1);
				set_port(PORTB,PB5,1);
				set_port(PORTB,PB6,1);
				set_port(PORTB,PB7,1);
			}

		_delay_ms(1000);

	}	

	return 0;
}