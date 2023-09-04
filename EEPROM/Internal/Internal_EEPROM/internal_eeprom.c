/*
 * internal_eeprom.c
 *
 * Created: 9/4/2023 5:09:58 PM
 *  Author: Mahmoud Ismail
 */ 

#include "internal_eeprom.h"

void EEPROM_writeByte(uint16_t address , uint8_t data) {
	
	/* Check for address as it must not exceed 511 and not be negative */
	if (address >= 0 && address <= 511 )
	{
		/* Wait for completion of previous write */
		while(BIT_IS_SET(EECR,EEWE));
		
		/* Set up address and data registers */
		EEAR = address & 0x1FF; /* Bit Masking */
		EEDR = data;
		
		/* Write logical one to EEMWE */
		EECR |= (1<<EEMWE);
		/* Start eeprom write by setting EEWE */
		EECR |= (1<<EEWE);
	}
}

uint8_t EEPROM_readByte(uint16_t address) {
	
	/* Check for address as it must not exceed 511 and not be negative */
	if (address >= 0 && address <= 511)
	{
		/* Var to hold data */
		uint8_t ret_var = 0;
		
		/* Wait for completion of previous write */
		while(BIT_IS_SET(EECR,EEWE));
		
		/* Set up address register */
		EEAR = address & 0x1FF; /* Bit Masking */
		/* Start eeprom read by writing EERE */
		EECR |= (1<<EERE);
		/* Return data from data register */
	    ret_var = EEDR;
		return ret_var;
	}
	else
	    return 0;
}

void EEPROM_updateByte(uint16_t address , uint8_t data) {
	
	/* Check for address as it must not exceed 511 and not be negative */
	if ((address >= 0) && (address <= 511))
	{
		/* Check if data isn't eqaul it will overwrite */
		if (data != EEPROM_readByte(address))
		{
			EEPROM_writeByte(address,data);
		}
	}
}
