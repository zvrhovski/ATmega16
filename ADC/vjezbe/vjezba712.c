/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 7.1.2
 */ 


#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"

void inicijalizacija(){
	
	lcd_init(); // inicijalizacija lcd displeja
	// inicijalizacija AD pretvorbe
}

int main(void){
	
	inicijalizacija();

	uint16_t ADC5; // rezultat AD pretvorbe
	float VPA5; // napon na pinu PA5
	const float VREF = 5.0; // AVCC
	
	while(1)
	{
		ADC5 = 0;
		
		for(uint8_t i = 0; i < 10; i++)
		{	
		// zbroj deset mjerenje u jednoj sekuni
		}	
	
		ADC5 = ADC5 / 10;
		
		// napon na pinu PA5

		lcd_clrscr();
		lcd_home();
		
		lcd_print("ADC5 = %d", ADC5);
		lcd_print("\nVPA5 = %.2fV", VPA5);

	}	

	return 0;
}