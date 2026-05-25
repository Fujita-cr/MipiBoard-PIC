#ifndef DAC082S085_H
#define DAC082S085_H

#include <stdint.h>

//--------------------------------------
// 既存互換（func指定）
//--------------------------------------
#define IRLED_LEFT     2
#define IRLED_RIGHT    3

//--------------------------------------
// API
//--------------------------------------
// func : IRLED_LEFT / IRLED_RIGHT
// val  : 0～255
// 戻り値: 正常=0 / 異常=-1
//--------------------------------------
int16_t DAC082S085_Set(uint16_t func, uint16_t val);

#endif // DAC082S085_H