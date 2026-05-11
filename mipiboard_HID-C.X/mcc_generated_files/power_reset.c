/*
 * File:   power_reset.c
 * Author: thaya
 *
 * Created on December 30, 2019, 11:03 PM
 */


#include "xc.h"
#define FCY 16000000UL 
#include <libpic30.h>
#include "pin_manager.h"
#include "power_reset.h"

void Power_Reset_Init(void){
    //Cypress カメラICはすべてリセット状態
    Camera_L_Reset_SetLow();
    Camera_R_Reset_SetLow();
   //TC358870 MIPI IC初期状態はリセット状態
    TC358870_Reset_SetLow();
   //LCD　初期リセット状態
    LCD_Reset_SetLow();
   //すべての電源はOFF
    PW_ON1N_SetHigh();
    PW_ON2N_SetHigh();
    PW_ON3N_SetHigh();
    PW_ON4N_SetHigh();
   //IOはOFF状態
    BackLight_ON_SetLow();
    //SPIのCS選択はH状態
    SPI_CS_DA_IR_SetHigh();   
}

void Power_On(void) {
    PW_ON1N_SetLow();
    __delay_us(100);
    PW_ON2N_SetLow();
    __delay_us(100);
    PW_ON3N_SetLow();
    //__delay_us(100);
    __delay_ms(200);
    TC358870_Reset_SetHigh(); //MIPI IC リセット解除
    __delay_ms(1);
    PW_ON4N_SetLow();
    __delay_ms(2);
    LCD_Reset_SetHigh();  //LCD リセット解除
    Camera_L_Reset_SetHigh(); //左カメラリセット解除
    Camera_R_Reset_SetHigh(); //右カメラリセット解除
    __delay_ms(240); //LCDリセット用のウェイト？
}
void Power_Off(void){
    
    BackLight_ON_SetLow(); //バックライトOFF
    Camera_L_Reset_SetLow();    //カメラリセット
    Camera_R_Reset_SetLow();
    LCD_Reset_SetLow();
    PW_ON4N_SetHigh();
    TC358870_Reset_SetLow();
    __delay_ms(100);
    PW_ON3N_SetHigh();
    PW_ON2N_SetHigh();
    PW_ON1N_SetHigh();
}
void Santek_LCD_Reset(void){
    LCD_Reset_SetHigh();
    __delay_ms(6);    
    LCD_Reset_SetLow();
    __delay_ms(2);
    LCD_Reset_SetHigh();
    __delay_ms(6);
}
void Ortustech_LCD_Reset(void){
    LCD_Reset_SetHigh();
    __delay_ms(10);  
    LCD_Reset_SetLow();
    __delay_ms(30);
    LCD_Reset_SetHigh();
    __delay_ms(150);
}
void TC358870_Reset(void){
    TC358870_Reset_SetHigh();
    __delay_ms(2);
    TC358870_Reset_SetLow();
    __delay_us(30);
    TC358870_Reset_SetHigh();
    __delay_ms(2);
}

void System_Shutdown(void)
{
    /* 外部電源OFF */
    Power_Off();

    /* 全タイマ停止 */
    T1CONbits.TON = 0;
    T2CONbits.TON = 0;
    T3CONbits.TON = 0;
    T4CONbits.TON = 0;
    T5CONbits.TON = 0;

    /* USB無効化 */
    U1CONbits.USBEN = 0;

    /* 割り込み禁止 */
    IEC0 = 0;
    IEC1 = 0;
    IEC2 = 0;

    /* 割り込みフラグクリア */
    IFS0 = 0;
    IFS1 = 0;
    IFS2 = 0;

    /* グローバル割り込み禁止 */
    __builtin_disable_interrupts();
    
    /* 永久停止 */
    while(1)
    {
        Sleep();
    }
}

void Camera_Reset(int camsel){
    switch(camsel){
        case 0:
          Camera_L_Reset_SetLow(); //左カメラリセット
          Camera_R_Reset_SetLow(); //右カメラリセット
          break;
        case 1:
          Camera_L_Reset_SetLow(); //左カメラリセット
          break;
        case 2:
          // //センターカメラは削除済み
          break;
        case 3:
          Camera_R_Reset_SetLow(); //右カメラリセット
          break;
    }
    __delay_ms(10);  //データシートでは1ms以上と記載あり
    switch(camsel){
        case 0:
          Camera_L_Reset_SetHigh(); //左カメラリセット
          Camera_R_Reset_SetHigh(); //右カメラリセット
          break;
        case 1:
          Camera_L_Reset_SetHigh(); //左カメラリセット
          break;
        case 2:
          // //センターカメラは削除済み
          break;
        case 3:
          Camera_R_Reset_SetHigh(); //右カメラリセット
          break;
    }
    __delay_ms(20);  //データシートでは5ms以上と記載あり
}