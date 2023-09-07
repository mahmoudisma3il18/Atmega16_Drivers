/*
 * internal_eeprom.h
 *
 * Created: 9/4/2023 5:10:24 PM
 *  Author: Mahmoud Ismail
 */ 


#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

/*------------------------------ Includes -------------------------------*/
#include <avr/io.h>
#include "common_macros.h"

/*--------------------------- Function Prototypes -----------------------*/

/* Write byte to specified address */
void EEPROM_writeByte(uint16_t address , uint8_t data);

/* Return Byte at specified address */
uint8_t EEPROM_readByte(uint16_t address);

/* Check if byte equals to new byte exist in same address , it wont overwrite it */
void EEPROM_updateByte(uint16_t address , uint8_t data);

/* Write 2 Bytes to specified location */
void EEPROM_writeWord(uint16_t address , uint16_t data);

/* Return 2 Byte at specified address */
uint16_t EEPROM_readWord(uint16_t address);

/* Check if byte equals to new byte exist in same address , it wont overwrite it */
void EEPROM_updateWord(uint16_t address , uint16_t data);

/* Write arrays of bytes with start address and size */
void EEPROM_writePage(uint16_t address , uint8_t *data , uint16_t size);

/* Read array of bytes with start address and size */
void EEPROM_readPage(uint16_t address , uint8_t * data , uint16_t size);

/* Dont write if arealdy same data exists in same place */
void EEPROM_updatePage(uint16_t address , uint8_t *data , uint16_t size);




#endif /* INTERNAL_EEPROM_H_ */