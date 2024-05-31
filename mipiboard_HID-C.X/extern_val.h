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
#ifndef EXTERN_VAL_H
#define	EXTERN_VAL_H

#include <xc.h> // include processor files - each processor file is guarded.  
// TODO Insert appropriate #include <>

//液晶タイプ設定 リセットの初期化等が異なるので

#define ORTUSTECH   1
#define SANTEK      0
#define LCD_TYPE    SANTEK


#define BL_SENSOR_SCAN_TIME     20  //BL_SENSORは20x10ms=200ms更新
#define CDS_SENSOR_SCAN_TIME    20  //CSS_SENSORは20X10ms=200ms更新
#define TMP102_SCAN_TIME        20  //TMP102温度は20X10ms=200ms更新
#define ADXL350_SCAN_TIME       2   //ADX350_SCAN_TIME 2X10ms=20ms更新
#define TC358870_SCAN_TIME      20

//ブートローダモード
#define SYSMEM_ADR  6       
#define BOOTFLAG_OFFSET 8   //SYSMEM_ADRから8バイトオフセットした位置がブートローダモードのフラグ
#define BOOTFLAG 0x00FF     //ブートローダモード識別フラグ

extern uint8_t  BL_Timer;          //BLセンサースキャンタイマー
extern uint8_t  CDS_Timer;         //CDセンサースキャンタイマー
extern uint8_t  TMP102_Timer;      //TMP102温度センサスキャンタイマー
extern uint8_t  ADXL350_Timer;     //ADXL350加速度センサースキャンタイマー
extern uint16_t BL_AD_Val;         //BLセンサーの値
extern uint16_t CDS_AD_Val;        //CDSセンサーの値
extern int16_t  TMP102_Val;       //温度センサーの値
extern int16_t  ADXL350_X_Val;    //Gセンサーの値
extern int16_t  ADXL350_Y_Val;
extern int16_t  ADXL350_Z_Val;
extern uint16_t BackLight_Status;   //HDMI信号ロスト時のバックライト点灯状態
extern uint16_t BackLight_Kido;     //バックライトのLTC1661の値
extern uint8_t TC358870_Timer;

extern int16_t  tc358870_interrupt;    //TC358870 external interrput flag

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* EXTERN_VAL_H */

