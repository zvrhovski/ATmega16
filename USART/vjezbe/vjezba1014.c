/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 10.1.4
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "USART/USART.h"
#include "ADC/adc.h"
#include "timer/timer.h"

uint16_t ADC5;

ISR(TIMER1_OVF_vect){
	TCNT1 = 0;
	
	// slanje vrijednosti analogno digitalne pretvorbe
}




void inicijalizacija(){
	
	// PB7,PB6,PB5,i PB4 postavljeni kao izlazni pinovi
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4);

	lcd_init();
	adc_init();
	usart_init(19200);
	// F_CPU/64, normalan naèin rada, omoguæen prekid tajmera 1
	timer1_init(); 
	TCNT1 = 0;
	sei(); // globalno omoguæenje prekida
}

int main(void){
	
	inicijalizacija();
	
	while (1){
		
		if(usart_read_all() == 1){
			
			lcd_clrscr();
			lcd_home();
			lcd_print("%s", usart_buffer);
			
			if(usart_buffer[0] == 'P' && usart_buffer[1] == 'B'){
				
				set_port(PORTB, usart_buffer[2] - 48, usart_buffer[3] - 48);
				
			}
		}
	}
	
	return 0;
}