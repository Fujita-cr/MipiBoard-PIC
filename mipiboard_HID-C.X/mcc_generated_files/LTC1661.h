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
#ifndef LTC1661_H
#define	LTC1661_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "spi1.h"
#include "pin_manager.h"
#define FCY 16000000UL 
#include <libpic30.h>


// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

/*
 * File:   ltc1661.c
 * Author: thaya
 *
 * Created on December 31, 2019, 7:08 AM
 * 
 *   funcは以下の３個
 * 
 *   #define  BACK_LIGHT     1
 *   #define  IRLED_LEFT     2
 *   #define  IRLED_RIGHT    3
 * 
 * 　da_dataは１０ビットの出力値　0から1024
 *   リターン値は正常=0 funcが範囲外=-1
 * 
 * 
 */

//#define  BACK_LIGHT     1
//Change 2020/02/26 バックライト制御無し
#define  IRLED_LEFT     2
#define  IRLED_RIGHT    3


int16_t Spi_LT1661_Set(uint16_t func, uint16_t da_data);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */


#endif	/* LTC1661_H */
