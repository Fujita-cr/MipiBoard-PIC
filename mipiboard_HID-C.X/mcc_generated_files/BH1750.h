/*
 * File:   BH1750.h
 * Author:
 *
 * Created on
 */

#ifndef BH1750_H
#define	BH1750_H

#include <xc.h>
#include <stdint.h>

// BH1750 I2C SLAVE ADDRESS
#define BH1750ADDR     0x23

// BH1750 Command
#define BH1750_POWER_DOWN        0x00
#define BH1750_POWER_ON          0x01
#define BH1750_RESET             0x07

#define BH1750_CONT_H_RES_MODE   0x10
#define BH1750_CONT_H_RES2_MODE  0x11
#define BH1750_CONT_L_RES_MODE   0x13

void bh1750_init(void);

int16_t bh1750_read_lux(uint16_t *lux);

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* BH1750_H */