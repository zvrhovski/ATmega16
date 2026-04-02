/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 10.1.2
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "USART/USART.h"


void inicijalizacija(){
	
	// PB7,PB6,PB5,i PB4 postavljeni kao izlazni pinovi
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4);

	lcd_init();
	usart_init(38400);
	sei(); // globalno omoguæenje prekida
}

int main(void){
	
	inicijalizacija();
	
	uint8_t i;
	uint16_t slider = 0;

	
	while (1){
		
		if(usart_read_all() == 1){
			
			lcd_clrscr();
			lcd_home();
			lcd_print("%s", usart_buffer);

			slider = 0;
			for(i = 0; i < 4; i++){
					
				if(usart_buffer[i] == '\0') break;
						
				slider = slider * 10 + (usart_buffer[i] - 48);
								
			}

			if (slider == 0){
				
				set_port(PORTB,PB7,0);
				set_port(PORTB,PB6,0);
				set_port(PORTB,PB5,0);
				set_port(PORTB,PB4,0);		
			}
			
			if (slider > 0 && slider < 2500){
				
				set_port(PORTB,PB7,1);
				set_port(PORTB,PB6,0);
				set_port(PORTB,PB5,0);
				set_port(PORTB,PB4,0);
			}
			
			if (slider >= 2500 && slider < 5000){
				
				set_port(PORTB,PB7,1);
				set_port(PORTB,PB6,1);
				set_port(PORTB,PB5,0);
				set_port(PORTB,PB4,0);
			}

			if (slider >= 5000 && slider < 7500){
				
				set_port(PORTB,PB7,1);
				set_port(PORTB,PB6,1);
				set_port(PORTB,PB5,1);
				set_port(PORTB,PB4,0);
			}
			
			if (slider >= 7500){
				
				set_port(PORTB,PB7,1);
				set_port(PORTB,PB6,1);
				set_port(PORTB,PB5,1);
				set_port(PORTB,PB4,1);
			}
			
		}
	}
	
	return 0;
}
	
