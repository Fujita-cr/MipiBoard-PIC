/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ64GB004
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/

#define Camera_R_Reset_SetHigh()          _LATA10 = 1
#define Camera_R_Reset_SetLow()           _LATA10 = 0

#define Camera_C_Reset_SetHigh()          _LATC8 = 1
#define Camera_C_Reset_SetLow()           _LATC8 = 0

#define Camera_L_Reset_SetHigh()          _LATA4 = 1
#define Camera_L_Reset_SetLow()           _LATA4 = 0

#define TC358870_Reset_SetHigh()          _LATA7 = 1
#define TC358870_Reset_SetLow()           _LATA7 = 0

#define BackLight_ON_SetHigh()          _LATA8 = 1
#define BackLight_ON_SetLow()           _LATA8 = 0

#define SPI_CS_DA_IR_SetHigh()          _LATA9 = 1
#define SPI_CS_DA_IR_SetLow()           _LATA9 = 0

#define LCD_Reset_SetHigh()          _LATB4 = 1
#define LCD_Reset_SetLow()           _LATB4 = 0

#define PW_ON1N_SetHigh()          _LATC4 = 1
#define PW_ON1N_SetLow()           _LATC4 = 0

#define PW_ON2N_SetHigh()          _LATC5 = 1
#define PW_ON2N_SetLow()           _LATC5 = 0

#define PW_ON3N_SetHigh()          _LATC6 = 1
#define PW_ON3N_SetLow()           _LATC6 = 0

#define PW_ON4N_SetHigh()          _LATC3 = 1
#define PW_ON4N_SetLow()           _LATC3 = 0


void PIN_MANAGER_Initialize (void);


#endif
