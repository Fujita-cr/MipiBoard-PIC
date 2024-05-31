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
 * 
 * 
 * 
 */

#include "LTC1661.h"
#define FCY 16000000UL 
#include <libpic30.h>

uint16_t bitflip16(uint32_t a)
{
    uint32_t b;
     b = a;
     a = a & 0x55555555;
     b = b ^ a;
     a = a << 2;
     a = a | b;   //aba0

     b = a;
     a = a & (0x33333333<<1);
     b = b ^ a;
     a = a <<4;
     a = a | b;

     b = a;
     a = a & (0x0f0f0f0f<<3);
     b = b ^ a;
     a = a <<8;
     a = a | b;

     b = a;
     a = a & (0x00ff00ff<<7);
     b = b ^ a;
     a = a <<16;
     a = a | b;

     a = a >> 15;
    return (uint16_t)a;
}

int16_t Spi_LT1661_Set(uint16_t func, uint16_t da_data){
    
    int16_t returnVal;

    
    returnVal = 0;
    //戻り値は意味無し、一応funcが違う場合は-1で戻る
    
    switch(func){
// Change 2020/02/26 バックライト制御無し
//        case BACK_LIGHT:
//            SPI_CS_DA_BL_SetLow();      // BL用CS選択
//            __delay_us(10);
//            da_data = da_data << 2;
//            da_data = da_data & 0x0FFC;
//            da_data = da_data | 0x9000;   //Channel A
//            SPI_Send_16(da_data);
//            __delay_us(10);
//            SPI_CS_DA_BL_SetHigh(); //BL用CS解除
//            break;
        case IRLED_LEFT:
            SPI_CS_DA_IR_SetLow();  //IRLED用LTC1661選択
            __delay_us(10);
            da_data = da_data << 2;
            da_data = da_data & 0x0FFC;
            da_data = da_data | 0x9000;   //Channel A
            SPI_Send_16(da_data);
            __delay_us(10);
            SPI_CS_DA_IR_SetHigh(); //IRLED用CS解除
            break;
        case IRLED_RIGHT:
            SPI_CS_DA_IR_SetLow();  //IRLED用LTC1661選択
            __delay_us(10);
            da_data = da_data << 2;
            da_data = da_data & 0x0FFC;
            da_data = da_data | 0xA000;   //Channel A
            SPI_Send_16(da_data);
            __delay_us(10);
            SPI_CS_DA_IR_SetHigh(); //IRLED用CS解除
            break;
        default:
            returnVal = -1;
            break;
    }
    return (returnVal);
}
