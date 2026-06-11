/*
 * File:   BH1750.c
 * Author:
 *
 * Created on
 */

#include "BH1750.h"

#define FCY 16000000UL
#include <libpic30.h>

#include "thd_i2c1.h"

#define ACK     0
#define NOACK   1

#define RW_0    0
#define RW_1    1

/*
 BH1750 初期化

 Continuous H-Resolution Mode
 測定時間：約120ms

 戻り値
 0  = 正常
 1  = ACKエラー
 -1 = バス衝突
 -2 = タイムアウト
*/
void bh1750_init(void)
{
    int16_t retVal;

    // Power On
    retVal = I2C1_Start(BH1750ADDR, RW_0);

    if(retVal == 0)
    {
        I2C1_Send(BH1750_POWER_ON);
    }

    I2C1_Stop();

    __delay_ms(10);

    // Continuous H-Resolution Mode
    retVal = I2C1_Start(BH1750ADDR, RW_0);

    if(retVal == 0)
    {
        I2C1_Send(BH1750_CONT_H_RES_MODE);
    }

    I2C1_Stop();

    /*
     初回測定待ち
     データシート上 Typical 120ms
     */
    __delay_ms(180);
}

/*
 BH1750より照度データを読み出す

 戻り値
 0  = 正常
 1  = ACKエラー
 -1 = バス衝突
 -2 = タイムアウト
*/
int16_t bh1750_read_lux(uint16_t *lux)
{
    int16_t retVal;
    int16_t receiveRet;

    uint8_t data[2];

    retVal = I2C1_Start(BH1750ADDR, RW_1);

    if(retVal != 0)
    {
        I2C1_Stop();
        return retVal;
    }

    data[0] = (uint8_t)I2C1_Receive(ACK, &receiveRet);

    if(receiveRet != 0)
    {
        I2C1_Stop();
        return receiveRet;
    }

    data[1] = (uint8_t)I2C1_Receive(NOACK, &receiveRet);

    I2C1_Stop();

    if(receiveRet != 0)
    {
        return receiveRet;
    }

    *lux = ((uint16_t)data[0] << 8) | data[1];

    return 0;
}