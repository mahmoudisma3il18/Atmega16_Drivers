/*
 * I2C.h
 *
 * Created: 9/2/2023 2:15:01 AM
 *  Author: Mahmoud Ismail
 */ 


#ifndef I2C_H_
#define I2C_H_


#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"

/*----------------------------------- Defines ----------------------------*/
#define   I2C_SCLK_SM_50K            50000UL
#define   I2C_SCLK_SM_100K           100000UL
#define   I2C_SCLK_FM_400k           400000UL
#define   I2C_START_SENT             0x08     /* Start has been sent */
#define   I2C_REP_START_SENT         0x10     /* Repeated Start */
#define   I2C_SLA_W_ACK              0x18     /* Master transmit ( slave address + Write request ) to slave + Ack received from slave */
#define   I2C_SLA_W_NACK             0x20     /* Master transmit ( slave address + Write request ) to slave + NAck received from slave */
#define   I2C_DATA_SENT_ACK          0x28     /* Master transmit data and ACK has been received from Slave. */
#define   I2C_DATA_SENT_NACK         0x30     /* Master transmit data and NACK has been received from Slave. */
#define   I2C_ARBITRATION_LOST       0x38     /* Lost Arbitration */
#define   I2C_SLA_R_ACK              0x40     /* Master transmit ( slave address + Read request ) to slave + Ack received from slave */
#define   I2C_SLA_R_NACK             0x48     /* Master transmit ( slave address + Read request ) to slave + Ack received from slave */
#define   I2C_DATA_RECEIVED_ACK      0x50     /* Master received data and send ACK to slave */
#define   I2C_DATA_RECEIVED_NACK     0x58     /* Master received data and send NACK to slave */
#define   I2C_BUS_ERROR              0x00


/*----------------------------------- Typedefs --------------------------*/
/* Device address when it acts as slave */
typedef uint8_t  I2C_Slave_Address;

/*
Specifies the clock frequency of the I2C
interface. This parameter must be set to
one of the values defined in I2C_SCLK_
macro.
*/
typedef uint32_t I2C_SCL_Freq;

/*
Specifies whether the general call
address is enabled or disabled. This
parameter can be set to either
I2C_ENGC_Enable or
I2C_ENGC_Disable.
*/
typedef enum {
	I2C_ENGC_Disable,
	I2C_ENGC_Enable
}I2C_General_Call_Address_Detection;

/*
Specifies whether the I2C interface will
acknowledge or not the received data
byte. This parameter can be set to either
I2C_Ack_Enable or I2C_Ack_Disable.
*/
	
typedef struct {
	I2C_SCL_Freq       scl_Freq;
	I2C_Slave_Address  slave_Address;
	I2C_General_Call_Address_Detection general_Call_Address_Detection;
}I2C_config;	

/*-------------------------------- Function Prototypes --------------------*/

/* Initialize I2C */
void I2C_init(I2C_config *i2c_config_ptr);

/* Deinit I2C */
void I2C_deinit(void);

/* Generate Start condition */
void I2C_generateStart(void);

/* Generate Stop Condition */
void I2C_generateStop(void);

/* Write Data on Bus */
void I2C_masterWrite(uint8_t data);

/* Read data with ACK */
uint8_t I2C_masterReadWithACK(void);

/* Read data with NACK */
uint8_t I2C_masterReadWithNACK(void);

/* Get I2C Status */
uint8_t I2C_getStatus(void);








#endif /* I2C_H_ */