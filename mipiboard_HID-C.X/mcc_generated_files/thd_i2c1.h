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
 * File: thd_i2c1.h   
 * Author: T. Hayakawa
 * Comments: Support I2C1 channel functions
 * Revision history: 2019/12/28
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef THD_I2C1_H
#define	THD_I2C1_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "thd_i2c1.h"
// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

#define I2C1_CON            I2C1CON
#define I2C1_STAT           I2C1STAT
#define I2C1_TRN            I2C1TRN
#define I2C1_RCV            I2C1RCV
#define I2C1_BRG            I2C1BRG
#define I2C1_MIF            _MI2C1IF
#define I2C1_MIE            _MI2C1IE
#define I2C1_MIP            _MI2C1IP
#define I2C1_STAT_BCL       I2C1STATbits.BCL
#define I2C1_STAT_RBF       I2C1STATbits.RBF
#define I2C1_STAT_ACKSTAT   I2C1STATbits.ACKSTAT
#define I2C1_CON_DISSLW     I2C1CONbits.DISSLW
#define I2C1_CON_SEN        I2C1CONbits.SEN
#define I2C1_CON_RSEN       I2C1CONbits.RSEN
#define I2C1_CON_PEN        I2C1CONbits.PEN
#define I2C1_CON_RCEN       I2C1CONbits.RCEN
#define I2C1_CON_ACKDT      I2C1CONbits.ACKDT
#define I2C1_CON_ACKEN      I2C1CONbits.ACKEN


/*******************************************************************************
* I2C1_Initialize(void)                                                        
*    Ｉ２Ｃ通信のマスターモードで初期化を行う処理                              
*******************************************************************************/
void I2C1_Initialize(void);
/*******************************************************************************
*  ans = I2C1_Start(adrs,rw)                                                   
*    スレーブにスタートコンディションを発行する処理                            
*                                                                              
*    adrs : スレーブのアドレスを指定します                                     
*    rw   : スレーブに対する動作の指定をします                                 
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         
*    ans  : 0=正常                                                             
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  
*******************************************************************************/
int16_t I2C1_Start (uint16_t adrs,uint16_t rw);
/*******************************************************************************
*  ans = I2C1_rStart(adrs,rw)                                                  
*    スレーブにリピート・スタートコンディションを発行する処理                  
*                                                                              
*    adrs : スレーブのアドレスを指定します                                     
*    rw   : スレーブに対する動作の指定をします                                 
*           0=スレーブに書込みなさい要求　1=スレーブに送信しなさい要求         
*    ans  : 0=正常                                                             
*           1=異常(相手からACKが返ってこない) -1=他のマスターとのバス衝突発生  
*******************************************************************************/
int16_t I2C1_rStart(uint16_t adrs,uint16_t rw);
/*******************************************************************************
*  ans = I2C1_Stop()                                                           
*    スレーブにストップコンディションを発行する処理                            
*    ans  :  0=正常                                                            
*           -1=他のマスターとのバス衝突発生                                    
*******************************************************************************/
int16_t I2C1_Stop(void);
/*******************************************************************************
*  ans = I2C1_Send(dt)                                                         
*    スレーブにデータを１バイト送信する処理                                    
*                                                                              
*    dt  : 送信するデータを指定します                                          
*    ans  : 0=正常                                                             
*           1=異常(相手からACKが返ってこない又はNOACKを返した)                 
*          -1=他のマスターとのバス衝突発生                                     
*******************************************************************************/
int16_t I2C1_Send(uint8_t dt);
/*******************************************************************************
*  ans = I2C1_Receive(ack)                                                     
*    スレーブからデータを１バイト受信する処理                                  
*                                                                              
*    ack  : スレーブへの返答データを指定します                                 
*           0:ACKを返す　1:NOACKを返す(受信データが最後なら1)                  
*    ans  : 受信したデータを返す                                               
*           -1=他のマスターとのバス衝突発生                                    
*******************************************************************************/
int16_t I2C1_Receive(uint16_t ack, int16_t* ret);
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
int16_t I2C1_SlaveRead(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu);
/*******************************************************************************
*  ans = I2C1_SlaveWrite(slv_adrs,reg_adrs,*data,kosu)                         
*  スレーブのデバイスに指定個数のデータを書き込む処理                          　　
*  マルチマスターに対応しています。                                               
*                                                                              
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             
*    reg_adrs : 書出すデータのレジスターアドレスを指定する                     
*               連続的に書出す場合は、書出すレジスターの先頭アドレスを指定     
*    *data    : 書出すデータの格納先を指定する                                
*    kosu     : 書出すデータのバイト数を指定する                              
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                     
*              -1=他のマスターとのバス衝突が発生してリトライオーバー          
*******************************************************************************/
int16_t I2C1_SlaveWrite(uint16_t slv_adrs,uint8_t reg_adrs,uint8_t *data,uint8_t kosu);
/*******************************************************************************
*  ans = I2C1_EEPROM_Read(mem_adrs,*data,kosu)                          
*  EEPROMの指定mem_adrsから指定個数のデータを読み込む処理 
*  EEPROMのI2Cスレーブアドレスは 0x57                       
*  マルチマスターに対応しています。                                            
*                                                                              
*    slv_adrs : スレーブのデバイスアドレスを指定します(7bitで指定)             
*    mem_adrs : 読出すデータの開始メモリアドレスを指定します                        
*    *data    : 読出したデータの格納先を指定します                             
*    kosu     : 読出すデータのバイト数を指定します                             
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                      
*              -1=他のマスターとのバス衝突が発生してリトライオーバー           
*******************************************************************************/
int16_t I2C1_EEPROM_Read(uint16_t mem_adrs,uint8_t *data,uint8_t kosu);
/*******************************************************************************
*  ans = I2C1_EEPROMWrite(mem_adrs,*data,kosu)                         
*  EEPROMの指定アドレスから指定個数のデータを書き込む処理    
*  EEPROMのI2Cスレーブアドレスは 0x57                       　　
*  マルチマスターに対応しています。                                               
*                                                                                          
*    mem_adrs : 書出すデータの開始メモリーアドレスを指定する                          
*    *data    : 書出すデータの格納先を指定する                                
*    kosu     : 書出すデータのバイト数を指定する                              
*    ans      : 0=正常　1=異常(相手からACKが返ってこない)                     
*              -1=他のマスターとのバス衝突が発生してリトライオーバー          
*******************************************************************************/
int16_t I2C1_EEPROM_Write(uint16_t mem_adrs,uint8_t *data,uint8_t kosu);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* THD_I2C1_H */