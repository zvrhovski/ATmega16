/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 10.1.3
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
// ukljuèite potrebna zaglavlja


void inicijalizacija(){
	// inicijalizacija za LCD, ADC i USART
	sei(); // globalno omoguæenje prekida
}

int main(void){
	
	inicijalizacija();

	uint16_t ADC5; // rezultat AD pretvorbe
	float VPA5; // napon na pinu PA5
	const float VREF = 5.0; // AVCC
		
		while (1)
		{
			if(usart_read_all() == true){
				
				lcd_clrscr();
				lcd_home();
				lcd_print("%s", usart_buffer);
			
				switch (usart_buffer[0]){
					case 'C':
					// poslati znak V
					break;
					case 'S':
					//poslati poruku Mikrokontroler ATmega16
					break;
					case 'I':
					//poslati broj 1023
					break;
					case 'R':
					//poslati broj 3.14
					break;
					case 'A':
					ADC5 = adc_read_10bit(5);
					//poslati varijablu ADC5
					break;
					case 'N':
					ADC5 = adc_read_10bit(5);
					usart_write("Napon: %0.4f V", ADC5*5.0/1024);
					break;
					default:
					usart_write_string("Neispravan znak!");
					break;
		
				}
			}
		} 
	
return 0;
}