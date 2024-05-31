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
#ifndef ADXL350_TMP120_H
#define	ADXL350_TMP120_H


#include <xc.h> // include processor files - each processor file is guarded. 


//#include "./mcc_generated_files/i2c1.h"


// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// ADXL350 I2C SLAVE ADDRESS
#define ADXL350ADDR     0x53 //SDO/ALT ADDRESS = L
// TMP102 I2C SLAVE ADDRESS
#define TMP102ADDR     0x49 //ADD0 = H

/* ADXL350 レジスタ・マップ*/
/*      Name            Addr   R/W RESET VALUE Description */
#define DEVID           0x00 //R 11100101 Device ID.
#define DEVID_VALUE     0xE5 //固定のデバイスIDコードの内容
//0x01 to 0x01C Reserved Reserved. Do not access.
#define THRESH_TAP      0x1D //R/W 00000000 Tap threshold.
#define OFSX            0x1E //R/W 00000000 X-axis offset.
#define OFSY            0x1F //R/W 00000000 Y-axis offset.
#define OFSZ            0x20 //R/W 00000000 Z-axis offset.
#define DUR             0x21 //R/W 00000000 Tap duration.
#define Latent          0x22 //R/W 00000000 Tap latency.
#define Window          0x23 //R/W 00000000 Tap window.
#define THRESH_ACT      0x24 //R/W 00000000 Activity threshold.
#define THRESH_INACT    0x25 //R/W 00000000 Inactivity threshold.
#define TIME_INACT      0x26 //R/W 00000000 Inactivity time.
#define ACT_INACT_CTL   0x27 //R/W 00000000 Axis enable control for activity and inactivity detection.
#define THRESH_FF       0x28 //R/W 00000000 Free-fall threshold.
#define TIME_FF         0x29 //R/W 00000000 Free-fall time.
#define TAP_AXES        0x2A //R/W 00000000 Axis control for tap/double tap.
#define ACT_TAP_STATUS  0x2B //R   00000000 Source of tap/double tap.
#define BW_RATE         0x2C //R/W 00001010 Data rate and power mode control.
#define POWER_CTL       0x2D //R/W 00000000 Power-saving features control.
#define INT_ENABLE      0x2E //R/W 00000000 Interrupt enable control.
#define INT_MAP         0x2F //R/W 00000000 Interrupt mapping control.
#define INT_SOURCE      0x30 //R   00000010 Source of interrupts.
#define DATA_FORMAT     0x31 //R/W 00000000 Data format control.
#define DATAX0          0x32 //R   00000000 X-Axis Data 0.
#define DATAX1          0x33 //R   00000000 X-Axis Data 1.
#define DATAY0          0x34 //R   00000000 Y-Axis Data 0.
#define DATAY1          0x35 //R   00000000 Y-Axis Data 1.
#define DATAZ0          0x36 //R   00000000 Z-Axis Data 0.
#define DATAZ1          0x37 //R   00000000 Z-Axis Data 1.
#define FIFO_CTL        0x38 //R/W 00000000 FIFO control.
#define FIFO_STATUS     0x39 //R   00000000 FIFO status.

/* レジスタ・マップ終わり*/
void tmp102_init(void);
int16_t adxl350_init(void);
int16_t adxl350_xyz_read(int16_t *X,int16_t *Y,int16_t *Z);

int16_t tmp102_read_temp(int16_t *tmp);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* ADXL350_TMP120_H */

