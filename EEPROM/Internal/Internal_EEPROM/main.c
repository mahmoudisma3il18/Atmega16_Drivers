/*
 * Internal_EEPROM.c
 *
 * Created: 9/4/2023 5:09:14 PM
 * Author : modyb
 */ 

#include <avr/io.h>
#include "internal_eeprom.h"
#include <avr/eeprom.h>

uint8_t data1;
uint8_t data2;


int main(void)
{
    /* Replace with your application code */
	
	EEPROM_writeByte(0x01,0x55);
	EEPROM_updateByte(0x01,0xC8);
	eeprom_write_byte((uint8_t*)0x01,0xAA);
	data1 = EEPROM_readByte(0x01);
	EEPROM_writeByte(0x01,0x59);
	EEPROM_updateByte(0x01,0xBB);
	eeprom_write_byte((uint8_t*)0x01,0xEA);
    while (1) 
    {
    }
}

