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
//  set 16MHz:          avrdude -c avrispv2 -P usb -p m88 -U lfuse:w:0xFF:m -U hfuse:w:0xDF:m
//  read current:       avrdude -v -c avrispv2 -P usb -p m88
//  ATmega88
//------------------------------------------------------------------------------
#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
// LCD
#include <stdlib.h>
#include <avr/pgmspace.h>

#define LOOP_CYCLES     10      //Number of cycles that the loop takes

/* ds18b20 Connections (At your choice) */
#define ds18b20_PORT           PORTB
#define ds18b20_DDR            DDRB
#define ds18b20_PIN            PINB
#define ds18b20_DQ             PB0

/* Utils */
#define ds18b20_INPUT_MODE()      ds18b20_DDR &= ~(1 << ds18b20_DQ)
#define ds18b20_OUTPUT_MODE()		ds18b20_DDR |= (1 << ds18b20_DQ)
#define ds18b20_LOW()             ds18b20_PORT &= ~(1 << ds18b20_DQ)
#define ds18b20_HIGH()            ds18b20_PORT |= (1 << ds18b20_DQ)

#define ds18b20_CMD_CONVERTTEMP   0x44
#define ds18b20_CMD_RSCRATCHPAD   0xbe
#define ds18b20_CMD_WSCRATCHPAD   0x4e
#define ds18b20_CMD_CPYSCRATCHPAD 0x48
#define ds18b20_CMD_RECEEPROM     0xb8
#define ds18b20_CMD_RPWRSUPPLY    0xb4
#define ds18b20_CMD_SEARCHROM     0xf0
#define ds18b20_CMD_READROM       0x33
#define ds18b20_CMD_MATCHROM      0x55
#define ds18b20_CMD_SKIPROM       0xcc
#define ds18b20_CMD_ALARMSEARCH   0xec

float ds18b20_read_temperature();
