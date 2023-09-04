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




#endif /* INTERNAL_EEPROM_H_ */