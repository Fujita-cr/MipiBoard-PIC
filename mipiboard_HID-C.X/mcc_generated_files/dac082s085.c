#include <xc.h>
#include <stdint.h>
#include "spi1.h"
#include "pin_manager.h"

#define FCY 16000000UL
#include <libpic30.h>

#include "DAC082S085.h"

//--------------------------------------
// 内部DACチャネル
//--------------------------------------
#define DAC_CH_A   0
#define DAC_CH_B   1

//--------------------------------------
// コマンド（Write & Update）
//--------------------------------------
#define DAC_CMD_WRITE_UPDATE  0x1

//--------------------------------------
// 16bit送信
//--------------------------------------
static void SPI_Write16(uint16_t data)
{
    SPI_CS_DA_IR_SetLow();  // IR LED DAC選択（DAC082S085）
    SPI_Send_16(data);   // 16bit送信
    SPI_CS_DA_IR_SetHigh();  // IR LED DAC選択解除（DAC082S085）
}

//--------------------------------------
// API（既存互換）
//--------------------------------------
int16_t DAC082S085_Set(uint16_t func, uint8_t val)
{
    uint8_t ch;

    // func → DACチャネル変換
    if (func == IRLED_LEFT) {
        ch = DAC_CH_A;
    }
    else if (func == IRLED_RIGHT) {
        ch = DAC_CH_B;
    }
    else {
        return -1;
    }

    // フレーム生成
    // [15:14] Address (2bit)
    // [13:12] Command (2bit)
    // [11:4]  Data (8bit)
    // [3:0]   Don't care
    uint16_t frame = 0;
    frame |= (ch << 14);
    frame |= (DAC_CMD_WRITE_UPDATE << 12);
    frame |= ((uint16_t)val << 4);

    // 送信
    SPI_Write16(frame);

    return 0;
}