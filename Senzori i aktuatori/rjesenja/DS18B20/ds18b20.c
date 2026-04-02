//------------------------------------------------------------------------------
//   AVR-Temp Sensor
//   bitman@bitmania.de
//   www.bitmania.de
//------------------------------------------------------------------------------
// Based on the publication:
//              Using DS18B20 digital temperature sensor on AVR microcontrollers
//              Description and application, Version 1.0 (Preliminary)
//              by Gerard Marull Paretas, September 2007
//------------------------------------------------------------------------------
// Fuses

//  ATmega88
//------------------------------------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include <stdlib.h>

#include "ds18b20.h"

uint8_t ds18b20_reset() {
	uint8_t i;
	// Pull line low and wait for 480uS
	ds18b20_LOW();
	ds18b20_OUTPUT_MODE();
	_delay_us(480);

	
	//Release line and wait for 60uS
	ds18b20_INPUT_MODE();
	_delay_us(60);
	
	//Store line value and wait until the completion of 480uS period
	i= (ds18b20_PIN & (1 << ds18b20_DQ));
	_delay_us(420);
	
	//Return the value read from the presence pulse (0=OK, 1=WRONG)
	return i;
}

void ds18b20_write_bit(uint8_t bit){
	//Pull line low for 1uS
	
	ds18b20_LOW();
	ds18b20_OUTPUT_MODE();
	
	_delay_us(1);

	//If we want to write 1, release the line (if not will keep low)
	
	if(bit) ds18b20_INPUT_MODE();
	//Wait for 60uS and release the line
	_delay_us(60);
	
	ds18b20_INPUT_MODE();
}

uint8_t ds18b20_read_bit(void){
	
	uint8_t bit=0;
	
	//Pull line low for 1uS
	ds18b20_LOW();
	ds18b20_OUTPUT_MODE();
	_delay_us(1);
	
	//Release line and wait for 14uS
	ds18b20_INPUT_MODE();
	_delay_us(14);

	//Read line value
	if(ds18b20_PIN & (1 << ds18b20_DQ)) bit=1;
	
	//Wait for 45uS to end and return read value
	_delay_us(45);
	
	return bit;
}

uint8_t ds18b20_read_byte(void){
	
	uint8_t i = 8, n = 0;
	
	while(i--){
		
		//Shift one position right and store read value
		n >>= 1;
		n |= (ds18b20_read_bit()<<7);
	}
	
	return n;
}

void ds18b20_write_byte(uint8_t byte){
	uint8_t i = 8;
	while(i--){
		 
		//Write actual bit and shift one position right to make the next bit ready
		ds18b20_write_bit(byte & 1);
		byte >>= 1;
	}
}



float ds18b20_read_temperature(){

	// Buffer length must be at least 12bytes long! ["+XXX.XXXX C"]
	uint8_t temperature[2];
	int16_t temp_int = 0;
	float temp;
	
	//Reset, skip ROM and start temperature conversion
	ds18b20_reset();
	ds18b20_write_byte(ds18b20_CMD_SKIPROM);
	ds18b20_write_byte(ds18b20_CMD_CONVERTTEMP);
	
	//Wait until conversion is complete
	while(!ds18b20_read_bit());
	
	//Reset, skip ROM and send command to read Scratchpad
	ds18b20_reset();
	ds18b20_write_byte(ds18b20_CMD_SKIPROM);
	ds18b20_write_byte(ds18b20_CMD_RSCRATCHPAD);
	
	//Read Scratchpad (only 2 first bytes)
	temperature[0] = ds18b20_read_byte();
	temperature[1] = ds18b20_read_byte();
	ds18b20_reset();
	
	//Store temperature integer digits and decimal digits
	temp_int=(temperature[1] << 8) | temperature[0];
	temp = temp_int / 16.0;
	return temp;
	
	//Format temperature into a string [+XXX.XXXX C]
}
