/*
 Naslov: MIKRORAÈUNALA - Programiranje mikrokontrolera porodice 
 Atmel u programskom okruženju Atmel Studio 6
 Autori: Zoran Vrhovski, Marko Miletiæ
 
 Vježba 6.1.1
 */ 

#include "AVR lib/AVR_lib.h"
#include <avr/io.h>
#include "LCD/lcd.h"
#include <avr/eeprom.h>

int8_t cijeli8_t;
int16_t cijeli16_t;
int32_t cijeli32_t;
float realan;

void inicijalizacija(){
	
	input_port(DDRB,PB0);
	set_port(PORTB,PB0,1);
	
	cijeli8_t = eeprom_read_byte(0);
	cijeli16_t = eeprom_read_word(1);
	cijeli32_t = eeprom_read_dword(3);
	realan = eeprom_read_float(7);
	
	lcd_init();
	
}

int main(void){
	
	inicijalizacija();
	
	uint8_t pinb0 = 1;
	
	while(1)
	{
		
		cijeli8_t++;
		cijeli16_t +=2;
		cijeli32_t +=3;
		realan = 1.1 * cijeli8_t;
		
		// ispitivanje padajuæeg brida na PB0		
		if(pinb0 == 1 && debounce(&PINB, PB0, 0) != pinb0){
			eeprom_write_byte(0,cijeli8_t);
			eeprom_write_word(1,cijeli16_t);
			eeprom_write_dword(3,cijeli32_t);
			eeprom_write_float(7,realan);
			pinb0 = 0;
		}
		
		if(get_pin(PINB,PB0))
		pinb0 = 1;
		
		lcd_clrscr();
		lcd_home();
		lcd_print("C8: %d,C16: %d", cijeli8_t, cijeli16_t);
		lcd_print("\nC32: %ld,R: %.2f", cijeli32_t, realan);
		_delay_ms(1000);
		
	}
	
	return 0;
}