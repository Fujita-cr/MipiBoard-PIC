/*
 * File:   thd_i2c1.c
 * Author: thaya
 *
 * Created on December 29, 2019, 5:12 PM
 */


#include <xc.h>
#include "thd_i2c1.h"
#define FCY 16000000UL 
#include <libpic30.h>

#define ACK     0
#define NOACK   1
#define RW_0    0
#define RW_1    1

#define BUS_COLLISION_RETRY 15

#define I2C_RECEIVE_TIMEOUT 10000

/*
EEPROM ADDRESS　EEPROMアクセス関数は、このモジュールに記述 
 */
#define EEPROM_ADR  0x57

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
*  MPLAB(R) XC16 C Compiler Version 1.30                                       *
*******************************************************************************/

volatile int16_t IC2C1_AckCheck ;           // 相手からのACK待ち用フラグ変数
volatile int16_t IC2C1_CollisionCheck ;     // 他のマスターとのバス衝突検出用フラグ変数

// アイドル状態のチェック
// ACKEN RCEN PEN RSEN SEN TRSTAT RBF TBF が全て０ならＯＫ
int16_t I2C1_IdleCheck(uint16_t mask)
{
    int tout_count = 0;
    while (( I2C1_CON & 0x1F ) | (I2C1_STAT & mask)){
        if (tout_count > I2C_RECEIVE_TIMEOUT){
           return 1;  //タイムアウトエラー
        }
        ++tout_count;
    }
    return 0;
}
/*******************************************************************************
* I2C1_Initialize(void)                                                        *
*    Ｉ２Ｃ通信のマスターモードで初期化を行う処理                              *
*******************************************************************************/
void I2C1_Initialize(void)
{
    // initialize the hardware
    // Baud Rate Generator Value: I2CBRG 157;   
    I2C1BRG = 0x9D;
    // ACKEN disabled; STREN disabled; GCEN disabled; SMEN disabled; DISSLW enabled; 
    //I2CSIDL disabled; ACKDT Sends ACK; SCLREL Holds; RSEN disabled; IPMIEN disabled;
    //A10M 7 Bit; PEN disabled; RCEN disabled; SEN disabled; I2CEN enabled; 
    I2C1CON = 0x8000;
    // BCL disabled; P disabled; S disabled; I2COV disabled; IWCOL disabled; 
    I2C1STAT = 0x00;
    /* MI2C1 - I2C1 Master Events */
    // clear the master interrupt flag
    IFS1bits.MI2C1IF = 0;
    // enable the master interrupt
    IEC1bits.MI2C1IE = 1;
}
/*******************************************************************************
*  _MI2C1Interrupt( void )                                                     *
*    Ｉ２Ｃ(マスターモード)関連の割り込み処理                                  *
*******************************************************************************/
void __attribute__ ( ( interrupt, no_auto_psv ) ) _MI2C1Interrupt ( void )
{
     if (IC2C1_AckCheck == 1) IC2C1_AckCheck = 0 ;
     if (I2C1_STAT_BCL == 1) IC2C1_CollisionCheck = 1 ;  // バスの衝突が発生した
     I2C1_MIF = 0 ;                                // フラグクリア
}
/*******************************************************************************
*  ans = I2C1_Start(adrs,rw)                                                   *
*    スレーブにスタートコンディションを発行する処理                            *
*                                                                              *
*    adrs : スレーブのアドレスを指定します                                     *
*    rw   : スレーブに対する動作の指定をします                                 *
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  *
*******************************************************************************/
int16_t I2C1_Start (uint16_t adrs,uint16_t rw)
{
     IC2C1_CollisionCheck = 0 ;
     // スタート(START CONDITION)
     if (I2C1_IdleCheck(0x4003) == 1) return -2;
     I2C1_CON_SEN = 1 ;
     // [スレーブのアドレス]を送信する
     if (I2C1_IdleCheck(0x4003) == 1) return -2;
     if (IC2C1_CollisionCheck == 1) return -1 ;
     IC2C1_AckCheck = 1 ;
     I2C1_TRN = (uint8_t)((adrs<<1)+rw) ;   // アドレス + R/Wを送信
     while (IC2C1_AckCheck) ;                 // 相手からのACK返答を待つ
     if (IC2C1_CollisionCheck == 1) return -1 ;
     return I2C1_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C1_rStart(adrs,rw)                                                  *
*    スレーブにリピート・スタートコンディションを発行する処理                  *
*                                                                              *
*    adrs : スレーブのアドレスを指定します                                     *
*    rw   : スレーブに対する動作の指定をします                                 *
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  *
*******************************************************************************/
int16_t I2C1_rStart(uint16_t adrs,uint16_t rw)
{
     IC2C1_CollisionCheck = 0 ;
     // リピート・スタート(REPEATED START CONDITION)
     if (I2C1_IdleCheck(0x4003) == 1) return -2;
     I2C1_CON_RSEN = 1 ;
     // [スレーブのアドレス]を送信する
     if (I2C1_IdleCheck(0x4003) == 1) return -2;
     if (IC2C1_CollisionCheck == 1) return -1 ;
     IC2C1_AckCheck = 1 ;
     I2C1_TRN = (uint8_t)((adrs<<1)+rw) ;   // アドレス + R/Wを送信
     while (IC2C1_AckCheck) ;                 // 相手からのACK返答を待つ
     if (IC2C1_CollisionCheck == 1) return -1 ;
     return I2C1_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C1_Stop()                                                           *
*    スレーブにストップコンディションを発行する処理                            *
*    ans  :  0=正常                                                            *
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生     *
*******************************************************************************/
int16_t I2C1_Stop(void)
{
     IC2C1_CollisionCheck = 0 ;
     // ストップ(STOP CONDITION)
     if (I2C1_IdleCheck(0x4003) == 1) return -2;
     I2C1_CON_PEN = 1 ;
     if (IC2C1_CollisionCheck == 1) return -1 ;
     else                     return  0 ;
}
/*******************************************************************************
*  ans = I2C1_Send(dt)                                                         *
*    スレーブにデータを１バイト送信する処理                                    *
*                                                                              *
*    dt  : 送信するデータを指定します                                          *
*    ans  : 0=正常                                                             *
*           1=異常(相手からACKが返ってこない又はNOACKを返した)                 *
*          -1=他のマスターとのバス衝突発生                                     *
*******************************************************************************/
int16_t I2C1_Send(uint8_t dt)
{
     IC2C1_CollisionCheck = 0 ;
     if (I2C1_IdleCheck(0x4001) == 1) return -2;
     if (IC2C1_CollisionCheck == 1) return -1 ;
     IC2C1_AckCheck = 1 ;
     I2C1_TRN = dt ;                // データを送信
     while (IC2C1_AckCheck) ;            // 相手からのACK返答を待つ
     if (IC2C1_CollisionCheck == 1) return -1 ;
     return I2C1_STAT_ACKSTAT ;
}
/*******************************************************************************
*  ans = I2C1_Receive(ack)                                                     *
*    スレーブからデータを１バイト受信する処理                                  *
*                                                                              *
*    ack  : スレーブへの返答データを指定します                                 *
*           0:ACKを返す　1:NOACKを返す(受信データが最後なら1)                  *
*    ans  : 受信したデータを返す                                               *
*           -1=他のマスターとのバス衝突発生                                    *
*******************************************************************************/
int16_t I2C1_Receive(uint16_t ack, int16_t* ret)
{
     uint16_t dt ;
     *ret = 0;
     IC2C1_CollisionCheck = 0 ;
     if (I2C1_IdleCheck(0x4002) == -2) {
         *ret = -2;
         return -1;  //タイムアウトエラー
     }
     I2C1_CON_RCEN = 1 ;            // 受信を許可する
     // 受信を待つ
     int tout_count = 0;
     while( (I2C1_STAT_RBF != 1) | (I2C1_CON_RCEN != 0) ){
         if (tout_count > I2C_RECEIVE_TIMEOUT){
            *ret = -2;
            return -1;  //タイムアウトエラー
         }
         ++tout_count;
     };
     if (IC2C1_CollisionCheck == 1) {
         *ret = -1;
         return -1 ;
     }
     dt = I2C1_RCV ;                // データの受信
     if (I2C1_IdleCheck(0x2) == -2){
         *ret = -2;
         return -1;  //タイムアウトエラー
     }
     if (IC2C1_CollisionCheck == 1) {
         *ret = -1;
         return -1 ;
     }
     I2C1_CON_ACKDT = ack ;         // ACKデータのセット
     I2C1_CON_ACKEN = 1 ;           // ACKデータを返す
     return dt ;
}
/*******************************************************************************
*  ans = I2C1_SlaveRead(slv_adrs,reg_adrs,*data,kosu)                          
*  スレーブのデバイスから指定個数のデータを読み込む処理                        
*  マルチマスターに対応しています。                                            
*                                                                              
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             
*    reg_adrs : 読出すデータのレジスターアドレスを指定します                   
*               連続的に読出す場合は、読出すレジスターの先頭アドレスを指定     
*    *data    : 読出したデータの格納先を指定します                             
*    kosu     : 読出すデータのバイト数を指定します                             
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           
*******************************************************************************/
int16_t I2C1_SlaveRead(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , ack , j, ret;

     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C1_Start(slv_adrs,RW_0);        // スタートコンディションを発行する
          if (ans == 0) {
            ans = I2C1_Send(reg_adrs) ;              // レジスタアドレスを指定
            if (ans == 0){
                ans = I2C1_rStart(slv_adrs,RW_1) ; // リピート・スタートコンディションを発行する
                if (ans == 0) {
                     for (i=1 ; i<=kosu ; i++) {
                          if (i==kosu) ack = NOACK ;
                          else         ack = ACK ;
                          *data = I2C1_Receive(ack, &ret); // 指定個数分読み出す(受信する)
                          if (ret == 0){
                              //正常
                             data++ ;
                          }else if (ret == -1){
                              //バス衝突
                              ans = -1;
                              break;
                          }else if (ret == -2){
                              //タイムアウト
                              ans = -2;
                              break;
                          }
                     }
                }
            }
          }
          I2C1_Stop() ;          // ストップコンディションを発行する
          if (ans == -1){
              // バスの衝突が発生した100ms後にリトライする
              __delay_ms(100) ;
          }else if (ans == -2){
              //タイムアウトはI2C1_Initializeしてリトライしても、変な温度データが返ってくるので
              //リトライせずに0を返す
              *data = 0;
              break;
          }else{
              //終了
              break ;
          }
     }
     return ans ;
}
/*******************************************************************************
*  ans = I2C1_SlaveWrite(slv_adrs,reg_adrs,*data,kosu)                         
*  スレーブのデバイスに指定個数のデータを書き込む処理                          　　
*  マルチマスターに対応しています。 
*  kosuは３２バイトMAXです。                                              
*                                                                              
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             
*    reg_adrs : 書出すデータのレジスターアドレスを指定する                     
*               連続的に書出す場合は、書出すレジスターの先頭アドレスを指定     
*    *data    : 書出すデータの格納先を指定する                                
*    kosu     : 書出すデータのバイト数を指定する                              
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                     
*              -1=他のマスターとのバス衝突が発生してリトライオーバー          
*******************************************************************************/
int16_t I2C1_SlaveWrite(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , j ;

     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C1_Start(slv_adrs,RW_0); // スタートコンディションを発行する
          if (ans == 0) {
               I2C1_Send(reg_adrs) ;       // レジスタアドレスを指定
               for (i=0 ; i<kosu ; i++) {
                    I2C1_Send(*data) ;     // 指定個数分書き込む(送信する)
                    data++ ;
               }
          }
          I2C1_Stop() ;                    // ストップコンディションを発行する
          if (ans != -1) break ;           // バスの衝突以外なら終了
          else {
               __delay_ms(100) ;           // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}
/*******************************************************************************
*  ans = I2C1_EEPROM_Read(mem_adrs,*data,kosu)                          
*  EEPROMの指定mem_adrsから指定個数のデータを読み込む処理 
*  EEPROMのI2Cスレーブアドレスは 0x57                       
*  マルチマスターに対応しています。 
*  kosuは３２バイトMAXです。                                          
*                                                                              
*    スレーブのデバイスアドレスはEEPROM_ADRで直接関数内にあります。        
*    mem_adrs : 読出すデータの開始メモリアドレスを指定します                        
*    *data    : 読出したデータの格納先を指定します                             
*    kosu     : 読出すデータのバイト数を指定します                             
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           
*******************************************************************************/

int16_t I2C1_EEPROM_Read(uint16_t mem_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , ack , j, ret ;
     uint8_t low_adrs,high_adrs;

     low_adrs = (uint8_t)mem_adrs & 0xFF;
     high_adrs = (uint8_t)(mem_adrs >> 8);
     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C1_Start(EEPROM_ADR,RW_0);        // スタートコンディションを発行する
          if (ans == 0) {
               I2C1_Send(high_adrs);               // メモリアドレス送信
               I2C1_Send(low_adrs);
               ans = I2C1_rStart(EEPROM_ADR,RW_1) ; // リピート・スタートコンディションを発行する
               if (ans == 0) {
                    for (i=1 ; i<=kosu ; i++) {
                         if (i==kosu) ack = NOACK ;
                         else         ack = ACK ;
                         *data = I2C1_Receive(ack, &ret); // 指定個数分読み出す(受信する)
                         if (ret == 0){
                             //正常
                            data++ ;
                         }else if (ret == -1){
                             //バス衝突
                             ans = -1;
                             break;
                         }else if (ret == -2){
                             //タイムアウト
                             ans = -2;
                             break;
                         }
                    }
               }
          }
          I2C1_Stop() ;          // ストップコンディションを発行する
          if (ans == -1){
              // バスの衝突が発生した100ms後にリトライする
              __delay_ms(100) ;
          }else if (ans == -2){
              //タイムアウトはI2C1_Initializeしてリトライしても無理
              //(EEPROMでは未確認)
              *data = 0;
              break;
          }else{
              //終了
              break ;
          }
     }
     return ans ;
}
/*******************************************************************************
*  ans = I2C1_EEPROMWrite(mem_adrs,*data,kosu)                         
*  EEPROMの指定アドレスから指定個数のデータを書き込む処理    
*  スレーブのデバイスアドレスはEEPROM_ADRで直接関数内にあります。                      　　
*  マルチマスターに対応しています。                                               
*                                                                                          
*    mem_adrs : 書出すデータの開始メモリーアドレスを指定する                          
*    *data    : 書出すデータの格納先を指定する                                
*    kosu     : 書出すデータのバイト数を指定する                              
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                     
*              -1=他のマスターとのバス衝突が発生してリトライオーバー          
*******************************************************************************/
int16_t I2C1_EEPROM_Write(uint16_t mem_adrs,uint8_t *data,uint8_t kosu)
{
     int16_t  ans , i , j ;
     uint8_t low_adrs,high_adrs;
    
     low_adrs = (uint8_t)mem_adrs & 0xFF;
     high_adrs = (uint8_t)(mem_adrs >> 8);   
     for (j=0 ; j<BUS_COLLISION_RETRY ; j++) {
          ans = I2C1_Start(EEPROM_ADR,RW_0); // スタートコンディションを発行する
          if (ans == 0) {
               I2C1_Send(high_adrs);       // メモリーアドレス送信
               I2C1_Send(low_adrs);
               for (i=0 ; i<kosu ; i++) {
                    I2C1_Send(*data) ;     // 指定個数分書き込む(送信する)
                    data++ ;
               }
          }
          I2C1_Stop() ;                    // ストップコンディションを発行する
          if (ans != -1) break ;           // バスの衝突以外なら終了
          else {
               __delay_ms(100) ;           // バスの衝突が発生した100ms後にリトライする
          }
     }
     return ans ;
}
