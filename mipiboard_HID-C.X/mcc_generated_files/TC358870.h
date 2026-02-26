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
#ifndef TC358870_H
#define	TC358870_H

#include <xc.h> // include processor files - each processor file is guarded.  
#define FCY 16000000UL 
#include <libpic30.h>
#include <stdbool.h>


// TODO Insert appropriate #include <>

/*
 TC358870のエクセルファイルから出力されたコード記述を変更するマクロ
 */

#define Waitx1us    __delay_us
#define Waitx1ms    __delay_ms

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code.

void tc358870_init(void);
void tc358870(bool bCheckAll);
void tc358870_dsi_reset();

void test(void);

uint16_t Check_DDC();

//void HDMI_TimChk(uint8_t *ptr)
//Data Offset difinition

#define PX_FREQ0 0
#define	PX_FREQ1 1

#define	H_SIZE0 2
#define	H_SIZE1 3
#define	DE_HPOS0 4
#define	DE_HPOS1 5
#define	DE_HWID0 6
#define	DE_HWID1 7

#define	V_SIZE0 8
#define	V_SIZE1 9
#define	DE_POS_A0 10
#define	DE_POS_A1 11
#define	DE_POS_B0 12
#define	DE_POS_B1 13
#define	DE_VWID0 14
#define	DE_VWID1 15
#define	VI_STATUS1 16


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* TC358870_H */

