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

void EEPROM_writeWord(uint16_t address , uint16_t data) {
	
	EEPROM_writeByte(address,(data & 0x00FF));        /* Least significant byte at least address */
		
	address++;
		
	EEPROM_writeByte(address,((data & 0xFF00)>>8)); /* Most significant byte at next address */
}

uint16_t EEPROM_readWord(uint16_t address) {
	
	uint16_t data; /* Variable to hold data */
		
	data = (uint16_t)(EEPROM_readByte(address)) | (uint16_t)((EEPROM_readByte(address + 1))<<8); /* Return data and shift to put everybit at its place */
		
	/* Return data */
	return data;
}

void EEPROM_updateWord(uint16_t address , uint16_t data) {
	
	if (data != EEPROM_readWord(address)) /* Check if old data isnt equal to new one then it will be written in meomry */
	{
		EEPROM_writeWord(address,data);
	}
}

void EEPROM_writePage(uint16_t address , uint8_t *data , uint16_t size) {
	
	for (int i = 0 ; i < size ; i++)
	{
		EEPROM_writeByte(address+i,data[i]); /* Loop on every element in array and store it */
	}
}

void EEPROM_readPage(uint16_t address , uint8_t * data , uint16_t size) {
	
	for (int i = 0 ; i < size ; i++)
	{
		data[i] = EEPROM_readByte(address+i);
	}
}


void EEPROM_updatePage(uint16_t address , uint8_t *data , uint16_t size) {
	
	for (int i = 0 ; i < size ; i++)   /* Loop over all elements of array */
	{
		if (data[i] != EEPROM_readByte(address+i)) /* Check if new data same as one in old place */
		{
			EEPROM_writeByte(address+i , data[i]);   /* Write if data not the same */
		}
	}
}
