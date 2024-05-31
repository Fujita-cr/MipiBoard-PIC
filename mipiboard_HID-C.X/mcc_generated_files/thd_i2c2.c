/*
 * File:   thd_i2c2.c
 * Author: thaya
 *
 * Created on December 29, 2019, 7:46 PM
 */


#include <xc.h>
#include "thd_i2c2.h"
#define FCY 16000000UL 
#include <libpic30.h>
#define ACK     0
#define NOACK   1
#define RW_0    0
#define RW_1    1

#define BUS_COLLISION_RETRY 15


/*******************************************************************************
*  skI2Clib - Ｉ２Ｃ関数ライブラリ(１６ビットＭＣＵ専用)                       *
*             このライブラリはI2Cデバイス(RTC/EEPROM等)と接続を行う為の関数集  *
*                                                                              *
*    _MI2CxInterrupt- Ｉ２Ｃ関連のマスター割り込み処理                         *
*    InitI2C_Master - Ｉ２Ｃ通信のマスターモードで初期化を行う処理             *
*    I2C_Start      - スレーブにスタートコンディションを発行する処理           *
*    I2C_rStart     - スレーブにリピート・スタートコンディションを発行する処理 *
*    I2C_Stop       - スレーブにストップコンディションを発行する処理           *
*    I2C_Send       - スレーブにデータを１バイト送信する処理                   *
*    I2C_Receive    - スレーブからデータを１バイト受信する処理                 *
*                                                                              *
*    I2C_SlaveRead  - スレーブのデバイスから指定個数のデータを読み込む処理     *
*    I2C_SlaveWrite - スレーブのデバイスに指定個数のデータを書き込む処理       *
*                                                                              *
*    メモ：SDA/SCLピンは必ず「デジタル入力ピン」に設定を行って下さい。         *
*          通信クロックは100/400KHzでの初期化です。                            *
*          マルチマスター時にバス衝突が発生した場合は、"I2C_Start"から再送する *
*          I2C2を利用する場合は、skI2Clib.hに"#define I2C_MSSP2_USE"を宣言する *
*          "skI2Clib.h"に"#define FCY 16000000"が記述されている、              *
*          32MHz(16MIPS)以外のCPUクロックにする人は書き換えましょう。          *
* ============================================================================ *
*  VERSION DATE        BY                    CHANGE/COMMENT                    *
* ---------------------------------------------------------------------------- *
*  1.00    2015-07-27  きむ茶工房(きむしげ)  Create                            *
*  2.00    2016-07-15  きむ茶工房(きむしげ)  デバイスのレジスタ読書き関数を追加*
*  2.01    2017-02-22  きむ茶工房(きむしげ)  コメント追加                      *
*  3.00    2019-01-08  きむ茶工房(きむしげ)  FCYで通信速度を自動的に設定で変更 *
*                                            PIC24Fにも対応した                *
* ============================================================================ *
*  PIC24E(24EP256MC202) PIC24F(24FJ64GB002)                                    *
*  MPLAB X(v4.10)                                                              *
*  MPLAB(R) XC26 C Compiler Version 1.30                                       *
*******************************************************************************/

volatile int16_t IC2C2_AckCheck ;           // 相手からのACK待ち用フラグ変数
volatile int16_t IC2C2_CollisionCheck ;     // 他のマスターとのバス衝突検出用フラグ変数

// アイドル状態のチェック
// ACKEN RCEN PEN RSEN SEN TRSTAT RBF TBF が全て０ならＯＫ
void I2C2_IdleCheck(uint16_t mask)
{
     while (( I2C2_CON & 0x1F ) | (I2C2_STAT & mask)) ;
}
/*******************************************************************************
* I2C2_Initialize(void)                                                        *
*    Ｉ２Ｃ通信のマスターモードで初期化を行う処理                              *
*******************************************************************************/
void I2C2_Initialize(void)
{
    // initialize the hardware
    // Baud Rate Generator Value: I2CBRG 157;   
    I2C2BRG = 0x9D;
    // ACKEN disabled; STREN disabled; GCEN disabled; SMEN disabled; DISSLW enabled; 
    //I2CSIDL disabled; ACKDT Sends ACK; SCLREL Holds; RSEN disabled; IPMIEN disabled;
    //A10M 7 Bit; PEN disabled; RCEN disabled; SEN disabled; I2CEN enabled; 
    I2C2CON = 0x8000;
    // BCL disabled; P disabled; S disabled; I2COV disabled; IWCOL disabled; 
    I2C2STAT = 0x00;

    /* MI2C2 - I2C2 Master Events */
    // clear the master interrupt flag
    IFS3bits.MI2C2IF = 0;
    // enable the master interrupt
    IEC3bits.MI2C2IE = 1;
}
/*******************************************************************************
*  _MI2C2Interrupt( void )                                                     *
*    Ｉ２Ｃ(マスターモード)関連の割り込み処理                                  *
*******************************************************************************/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _MI2C2Interrupt ( void )
{
     if (IC2C2_AckCheck == 1) IC2C2_AckCheck = 0 ;
     if (I2C2_STAT_BCL == 1) IC2C2_CollisionCheck = 1 ;  // バスの衝突が発生した
     I2C2_MIF = 0 ;                                // フラグクリア
}
/*******************************************************************************
*  ans = I2C2_Start(adrs,rw)                                                   *
*    スレーブにスタートコンディションを発行する処理                            *
*                                                                              *
*    adrs : スレーブのアドレスを指定します                                     *
*    rw   : スレーブに対する動作の指定をします                                 *
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  *
*******************************************************************************/
int16_t I2C2_Start (uint16_t adrs,uint16_t rw)
{
     IC2C2_CollisionCheck = 0 ;
     // スタート(START CONDITION)
     I2C2_IdleCheck(0x4003) ;
     I2C2_CON_SEN = 1 ;
     // [スレーブのアドレス]を送信する
     I2C2_IdleCheck(0x4003) ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     IC2C2_AckCheck = 1 ;
     I2C2_TRN = (uint8_t)((adrs<<1)+rw) ;   // アドレス + R/Wを送信
     while (IC2C2_AckCheck) ;                 // 相手からのACK返答を待つ
     if (IC2C2_CollisionCheck == 1) return -1 ;
     return I2C2_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C2_rStart(adrs,rw)                                                  *
*    スレーブにリピート・スタートコンディションを発行する処理                  *
*                                                                              *
*    adrs : スレーブのアドレスを指定します                                     *
*    rw   : スレーブに対する動作の指定をします                                 *
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  *
*******************************************************************************/
int16_t I2C2_rStart(uint16_t adrs,uint16_t rw)
{
     IC2C2_CollisionCheck = 0 ;
     // リピート・スタート(REPEATED START CONDITION)
     I2C2_IdleCheck(0x4003) ;
     I2C2_CON_RSEN = 1 ;
     // [スレーブのアドレス]を送信する
     I2C2_IdleCheck(0x4003) ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     IC2C2_AckCheck = 1 ;
     I2C2_TRN = (uint8_t)((adrs<<1)+rw) ;   // アドレス + R/Wを送信
     while (IC2C2_AckCheck) ;                 // 相手からのACK返答を待つ
     if (IC2C2_CollisionCheck == 1) return -1 ;
     return I2C2_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C2_Stop()                                                           *
*    スレーブにストップコンディションを発行する処理                            *
*    ans  :  0=正常                                                            *
*           -1=他のマスターとのバス衝突発生                                    *
*******************************************************************************/
int16_t I2C2_Stop(void)
{
     IC2C2_CollisionCheck = 0 ;
     // ストップ(STOP CONDITION)
     I2C2_IdleCheck(0x4003) ;
     I2C2_CON_PEN = 1 ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     else                     return  0 ;
}
/*******************************************************************************
*  ans = I2C2_Send(dt)                                                         *
*    スレーブにデータを１バイト送信する処理                                    *
*                                                                              *
*    dt  : 送信するデータを指定します                                          *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない又はNOACKを返した)                 *
*          -1=他のマスターとのバス衝突発生                                     *
*******************************************************************************/
int16_t I2C2_Send(uint8_t dt)
{
     IC2C2_CollisionCheck = 0 ;
     I2C2_IdleCheck(0x4001) ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     IC2C2_AckCheck = 1 ;
     I2C2_TRN = dt ;                // データを送信
     while (IC2C2_AckCheck) ;            // 相手からのACK返答を待つ
     if (IC2C2_CollisionCheck == 1) return -1 ;
     return I2C2_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C2_Receive(ack)                                                     *
*    スレーブからデータを１バイト受信する処理                                  *
*                                                                              *
*    ack  : スレーブへの返答データを指定します                                 *
*           0:ACKを返す　1:NOACKを返す(受信データが最後なら1)                  *
*    ans  : 受信したデータを返す                                               *
*           -1=他のマスターとのバス衝突発生                                    *
*******************************************************************************/
int16_t I2C2_Receive(uint16_t ack)
{
     uint16_t dt ;

     IC2C2_CollisionCheck = 0 ;
     I2C2_IdleCheck(0x4002) ;
     I2C2_CON_RCEN = 1 ;            // 受信を許可する
     // 受信を待つ
     while( (I2C2_STAT_RBF != 1) | (I2C2_CON_RCEN != 0) ) ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     dt = I2C2_RCV ;                // データの受信
     I2C2_IdleCheck(0x2) ;
     if (IC2C2_CollisionCheck == 1) return -1 ;
     I2C2_CON_ACKDT = ack ;         // ACKデータのセット
     I2C2_CON_ACKEN = 1 ;           // ACKデータを返す
     return dt ;
}
/*******************************************************************************
*  ans = I2C2_SlaveRead(slv_adrs,reg_adrs,*data,kosu)                          *
*  スレーブのデバイスから指定個数のデータを読み込む処理                        *
*  マルチマスターに対応しています。                                            *
*                                                                              *
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             *
*    reg_adrs : 読出すデータのレジスターアドレスを指定します                   *
*               連続的に読出す場合は、読出すレジスターの先頭アドレスを指定     *
*    *data    : 読出したデータの格納先を指定します                             *
*    kosu     : 読出すデータのバイト数を指定します                             *
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      *
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           *
*******************************************************************************/
int16_t I2C2_SlaveRead(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , ack , j ;

     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C2_Start(slv_adrs,RW_0);              // スタートコンディションを発行する
          if (ans == 0) {
               I2C2_Send(reg_adrs) ;                    // レジスタアドレスを指定
               ans = I2C2_rStart(slv_adrs,RW_1) ;       // リピート・スタートコンディションを発行する
               if (ans == 0) {
                    for (i=1 ; i<=kosu ; i++) {
                         if (i==kosu) ack = NOACK ;     //最後の読み出しでNOAK
                         else         ack = ACK ;
                         *data = I2C2_Receive(ack);     // 指定個数分読み出す(受信する)
                         data++ ;
                    }
               }
          }
          I2C2_Stop() ;                                 // ストップコンディションを発行する
          if (ans != -1) break ;                       // バスの衝突以外なら終了
          else {
               __delay_ms(100) ;                       // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}
/*******************************************************************************
*  ans = I2C2_SlaveWrite(slv_adrs,reg_adrs,*data,kosu)                         *
*  スレーブのデバイスに指定個数のデータを書き込む処理                          *
*  マルチマスターに対応しています。                                            *
*                                                                              *
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             *
*    reg_adrs : 書出すデータのレジスターアドレスを指定する                     *
*               連続的に書出す場合は、書出すレジスターの先頭アドレスを指定     *
*    *data    : 書出すデータの格納先を指定する                                 *
*    kosu     : 書出すデータのバイト数を指定する                               *
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      *
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           *
*******************************************************************************/
int16_t I2C2_SlaveWrite(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , j ;

     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C2_Start(slv_adrs,RW_0);         // スタートコンディションを発行する
          if (ans == 0) {
               I2C2_Send(reg_adrs) ;               // レジスタアドレスを指定
               for (i=0 ; i<kosu ; i++) {
                    I2C2_Send(*data) ;             // 指定個数分書き込む(送信する)
                    data++ ;
               }
          }
          I2C2_Stop() ;                            // ストップコンディションを発行する
          if (ans != -1) break ;                  // バスの衝突以外なら終了
          else {
               __delay_ms(100) ;                  // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}

/*******************************************************************************
*  ans = I2C2_TC358870_Read(regadr,*data,kosu)                          
*  TC358870の指定regadrから指定個数のデータを読み込む処理                        
*  マルチマスターに対応しています。                                           
*                                                                              
*    スレーブのデバイスアドレスはTC350078_ADRで直接関数内にあります。        
*    regadr   : 読出すデータのregadr                        
*    *data    : 読出したデータの格納先を指定します                             
*    kosu     : 読出すデータのバイト数を指定します                             
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           
*******************************************************************************/
#define TC358870_ADR    0x0F

int16_t I2C2_TC358870_Read(uint16_t regadr,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , ack , j ;
     uint8_t low_adrs,high_adrs;

     low_adrs = (uint8_t)regadr & 0xFF;
     high_adrs = (uint8_t)(regadr >> 8);
     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C2_Start(TC358870_ADR,RW_0);        // スタートコンディションを発行する
          if (ans == 0) {
               I2C2_Send(high_adrs);               // レジスタアドレス送信
               I2C2_Send(low_adrs);
               ans = I2C2_rStart(TC358870_ADR,RW_1) ; // リピート・スタートコンディションを発行する
               if (ans == 0) {
                    for (i=1 ; i<=kosu ; i++) {
                         if (i==kosu) ack = NOACK ;  //最後の読み出しでNOACK
                         else         ack = ACK ;
                         *data = I2C2_Receive(ack); // 指定個数分読み出す(受信する)
                         data++ ;
                    }
               }
          }
          I2C2_Stop() ;          // ストップコンディションを発行する
          if (ans != -1) break ; // バスの衝突以外なら終了
          else {
               __delay_ms(100) ; // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}
/*******************************************************************************
*  ans = I2C2_TC358870_Write(regadr,*data,kosu)                         
*  TC358870の指定レジスタに指定個数のデータを書き込む処理    
*  スレーブのデバイスアドレスはTC358870_ADRで直接関数内にあります。                      　　
*  マルチマスターに対応しています。                                               
*                                                                                          
*    regadr   : 書出すデータの指定レジスタを指定する                          
*    *data    : 書出すデータの格納先を指定する                                
*    kosu     : 書出すデータのバイト数を指定する                              
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                     
*              -1=他のマスターとのバス衝突が発生してリトライオーバー          
*******************************************************************************/
int16_t I2C2_TC358870_Write(uint16_t regadr,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , j ;
     uint8_t low_adrs,high_adrs;
    
     low_adrs = (uint8_t)regadr & 0xFF;
     high_adrs = (uint8_t)(regadr >> 8);   
     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C2_Start(TC358870_ADR,RW_0); // スタートコンディションを発行する
          if (ans == 0) {
               I2C2_Send(high_adrs);       // レジスタアドレス送信
               I2C2_Send(low_adrs);
               for (i=0 ; i<kosu ; i++) {
                    I2C2_Send(*data) ;     // 指定個数分書き込む(送信する)
                    data++ ;
               }
          }
          I2C2_Stop() ;                    // ストップコンディションを発行する
          if (ans != -1) break ;           // バスの衝突以外なら終了
          else {
               __delay_ms(100) ;           // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}

/*
 * 指定したTC358870のレジスタより1バイト読み込む
 * 読み込み動作時の戻り値については判定していない
 * 関数の戻り値は読み込んだデータ
 */
uint8_t i2c2_uh2cd_read8(uint16_t regadr)
{
    int16_t ans;
    uint8_t data;
    
    ans = I2C2_TC358870_Read(regadr,&data,1);
    return data;
}
/*
 * 指定したTC358870のレジスタより2バイト読み込む
 * 読み込み動作時の戻り値については判定していない
 * 関数の戻り値は読み込んだデータ
 */
uint16_t i2c2_uh2cd_read16(uint16_t regadr)
{
    int16_t ans,retVal,low_tmp;
    uint8_t data[2];
    
    ans = I2C2_TC358870_Read(regadr,&data[0],2);
    retVal = (uint16_t)data[1];
    retVal = ((retVal << 8) & 0xFF00);  //data[0]=[7:0] data[1]=[15:8]
    low_tmp = (uint16_t)data[0];
    low_tmp = low_tmp & 0x00FF;
    retVal = retVal | low_tmp;
    return retVal;    
}
/*
 * 指定したTC358870のレジスタより4バイト読み込む
 * 読み込み動作時の戻り値については判定していない
 * 関数の戻り値は読み込んだデータ
 */
uint32_t i2c2_uh2cd_read32(uint16_t regadr)
{
    int16_t ans;
    uint8_t data[4];
    int32_t retVal,h_tmp,m_tmp,l_tmp,low_tmp;
    
    ans = I2C2_TC358870_Read(regadr,&data[0],4);
    h_tmp = (uint32_t)data[3];
    h_tmp = ((h_tmp << 24) & 0xFF000000); //data[3]=[31-24]
    m_tmp = (uint32_t)data[2];
    m_tmp = ((m_tmp << 16) & 0x00FF0000); //data[2]=[23-16]
    l_tmp = (uint32_t)data[1];
    l_tmp = ((l_tmp << 8) & 0x0000FF00); //data[1]=[15:8]
    low_tmp = (uint32_t)data[0];
    low_tmp = low_tmp & 0x000000FF;   //data[1]=[7:0]
    retVal = (h_tmp | m_tmp | l_tmp | low_tmp);
    return retVal;
} 
/*
 * 指定したTC358870のレジスタに1バイト書き込む
 * 読み込み動作時の戻り値は　 0=正常　1=異常(相手からACKが返ってこない)
 * 　　　　　　　　　　　　　-1=他のマスターとのバス衝突が発生してリトライオーバー   
 */
uint16_t i2c2_uh2cd_write8(uint16_t regadr,uint8_t val)
{
    int16_t ans;
    uint8_t data;
    
    data = val;
    ans = I2C2_TC358870_Write(regadr,&data,1);
    return ans;   
}
/*
 * 指定したTC358870のレジスタに1ワード書き込む
 * 読み込み動作時の戻り値は　 0=正常　1=異常(相手からACKが返ってこない)
 * 　　　　　　　　　　　　　-1=他のマスターとのバス衝突が発生してリトライオーバー   
 */
uint16_t i2c2_uh2cd_write16(uint16_t regadr,uint16_t val)
{
    int16_t ans;
    uint8_t data[2];
    
    data[0] = (uint8_t)(val & 0x00FF);
    data[1] = (uint8_t)((val >> 8) & 0x00FF);
    ans = I2C2_TC358870_Write(regadr,&data[0],2);
    return ans;  
}
/*
 * 指定したTC358870のレジスタに1ロングワード書き込む
 * 読み込み動作時の戻り値は　 0=正常　1=異常(相手からACKが返ってこない)
 * 　　　　　　　　　　　　　-1=他のマスターとのバス衝突が発生してリトライオーバー   
 */
uint16_t i2c2_uh2cd_write32(uint16_t regadr,uint32_t val)
{
    int16_t ans;
    uint8_t data[4];
    
    data[0] = (uint8_t)(val & 0x000000FF);              //data[0]=[7:0]
    data[1] = (uint8_t)((val >> 8) & 0x000000FF);       //data[1]=[15-8]
    data[2] = (uint8_t)((val >> 16) & 0x000000FF);      //data[2]=[23-16]
    data[3] = (uint8_t)((val >> 24) & 0x000000FF);      //data[3]=[31-24]
    ans = I2C2_TC358870_Write(regadr,&data[0],4);
    return ans;
}