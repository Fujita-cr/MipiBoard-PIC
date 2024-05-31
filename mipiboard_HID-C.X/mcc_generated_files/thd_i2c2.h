/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef THD_I2C2_H
#define	THD_I2C2_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate


#define I2C2_CON            I2C2CON
#define I2C2_STAT           I2C2STAT
#define I2C2_TRN            I2C2TRN
#define I2C2_RCV            I2C2RCV
#define I2C2_BRG            I2C2BRG
#define I2C2_MIF            _MI2C2IF
#define I2C2_MIE            _MI2C2IE
#define I2C2_MIP            _MI2C2IP
#define I2C2_STAT_BCL       I2C2STATbits.BCL
#define I2C2_STAT_RBF       I2C2STATbits.RBF
#define I2C2_STAT_ACKSTAT   I2C2STATbits.ACKSTAT
#define I2C2_CON_DISSLW     I2C2CONbits.DISSLW
#define I2C2_CON_SEN        I2C2CONbits.SEN
#define I2C2_CON_RSEN       I2C2CONbits.RSEN
#define I2C2_CON_PEN        I2C2CONbits.PEN
#define I2C2_CON_RCEN       I2C2CONbits.RCEN
#define I2C2_CON_ACKDT      I2C2CONbits.ACKDT
#define I2C2_CON_ACKEN      I2C2CONbits.ACKEN

void I2C2_Initialize(void);
int16_t I2C2_Start (uint16_t adrs,uint16_t rw);
int16_t I2C2_rStart(uint16_t adrs,uint16_t rw);
int16_t I2C2_Stop(void);
int16_t I2C2_Send(uint8_t dt);
int16_t I2C2_Receive(uint16_t ack);
int16_t I2C2_SlaveRead(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu);
int16_t I2C2_SlaveWrite(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu);
int16_t I2C2_TC358870_Read(uint16_t regadr,uint8_t *data,uint8_t kosu);
int16_t I2C2_TC358870_Write(uint16_t regadr,uint8_t *data,uint8_t kosu);

/*
 東芝のTC358870のエクセル出力関数に合わせた関数名
 */
uint8_t i2c2_uh2cd_read8(uint16_t regadr);
uint16_t i2c2_uh2cd_read16(uint16_t regadr);
uint32_t i2c2_uh2cd_read32(uint16_t regadr);
uint16_t i2c2_uh2cd_write8(uint16_t regadr,uint8_t val);
uint16_t i2c2_uh2cd_write16(uint16_t regadr,uint16_t val);
uint16_t i2c2_uh2cd_write32(uint16_t regadr,uint32_t val);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */


#endif	/* THD_I2C2_H */