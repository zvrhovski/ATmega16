/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 12.1.3
 */

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include "ADC/adc.h"
#include <util/delay.h>


void inicijalizacija(){
	
	// konfigurirajte ADC i LCD
}

int main(void){
	
	inicijalizacija();

	uint16_t ADC5; // rezultat AD pretvorbe
	float Vout; // napon na pinu PA0
	float T; // temperatura u okolini senzora LM35
	const float VREF = 5.0; // AVCC
		
		while (1)
		{
		// izraèunajte i ispišite temperaturu na LCD
		} 
	
return 0;	
}