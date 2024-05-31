/*
 * File:   ADXL350_TMP102.c
 * Author: thaya
 *
 * Created on December 31, 2019, 8:26 AM
 */


#include "ADXL350_TMP102.h"
#define FCY 16000000UL 
#include <libpic30.h>
#include "../extern_val.h"
#include "thd_i2c1.h"


/*
 adxl350 初期化
 戻り値　0 = 正常 1=異常　相手からAck無し -1=バス衝突リトライオーバー
 BW_RATEが100Hzになっているので、10ms以下でサンプルすれば、データの破棄
 は発生しないので、タイマー割込みでフラグを立てて、動作させる方法が良い。
 I2Cで割込みを使用しているので、割込み処理中で、読み出しをしてはいけない
 */
int16_t adxl350_init(void){
    int16_t retVal;
    uint8_t data;
    
    retVal = I2C1_SlaveRead(ADXL350ADDR,DEVID,&data,1);
    if(data == DEVID_VALUE ){
        data = 0x00; // DATA_FORMAT レジスタの値 0x00
        retVal = I2C1_SlaveWrite(ADXL350ADDR,DATA_FORMAT,&data,1);
        if (retVal != 0)
            return retVal;
        data = 0x0A; // BW_RATE 100Hz
        retVal = I2C1_SlaveWrite(ADXL350ADDR,BW_RATE,&data,1);
        if (retVal !=0 )
            return retVal;
        data =0x08; // 測定モードにセット
        retVal = I2C1_SlaveWrite(ADXL350ADDR,POWER_CTL,&data,1);
        __delay_ms(2);
    } 
    else {
        retVal = -1;
    }
    return retVal;
}
/*
 adxl350 より x,y,zの加速度読み出し
 戻り値　0 = 正常 1=異常　相手からAck無し -1=バス衝突リトライオーバー
 BW_RATEが100Hzになっているので、10ms以下でサンプルすれば、データの破棄
 は発生しないので、タイマー割込みでフラグを立てて、動作させる方法が良い。
 I2Cで割込みを使用しているので、割込み処理中で、読み出しをしてはいけない。
 */
int16_t adxl350_xyz_read(int16_t *X,int16_t *Y,int16_t *Z){
    int16_t retVal;
    union {
    uint8_t c[6];
    int16_t w[3];
    }data;
    
    //このユニオンとアドレスの送り方は合っている？
    
    retVal= I2C1_SlaveRead(ADXL350ADDR,DATAX0,&data.c[0],6);
    *X = data.w[0];
    *Y = data.w[1];
    *Z = data.w[2];

    return retVal;
}
/*
 各軸の加速度を１００回読み出して平均値を返す。
 とりあえず、戻り値が０以外なら、どっかでエラーがあった。
 BW_RATEの周波数100Hzを考えると、この処理は意味が無いと思う。
 ので、実行して無い。
 */
//int16_t adxl350_avarage_xyz(int16_t *Ave_X,int16_t *Ave_Y,int16_t *Ave_Z){
//    int16_t x,y,z,i,count,ave_count;  //20230605 count ave_countを追加　100回正じゃない時
//    int16_t xl,yl,zl;
//    int16_t retVal;
//
//    count = 0;  //20230605 カウント初期化
//    ave_count = 0;  //20230605 
//    xl = 0;
//    yl = 0;
//    zl = 0;
//    retVal = 0;
//    
//    for (i=0; i<10; i++){   //20230606 100から10回に減少
//        retVal= adxl350_xyz_read(&x,&y,&z); //+ retVal 削除
//        if(retVal != 0){            //正じゃない時にカウントUP
//            count = count +1;
//        }
//        else{                      //正の時は足していく
//        xl = xl + x ;  // Ｘ軸
//        yl = yl + y ;  // Ｙ軸
//        zl = zl + z ;  // Ｚ軸
//        ave_count = ave_count +1;   //ave_count up
//        count = 0; //
//        }
//        
//        if(count > 5){     //5以上なら止める            
//        
//            break;
//        }
//        }
//
//        if(count > 5){
//            *Ave_X = 0 ; 
//            *Ave_Y = 0 ;
//            *Ave_Z = 0 ;
//            retVal = -1;
//        }
//        else{           
//        *Ave_X = xl / ave_count ;
//        *Ave_Y = yl / ave_count ;
//        *Ave_Z = zl / ave_count ;
//        retVal = 0;
//    }
//    return retVal;
//}


/*
 TMP102 初期化
 */
void tmp102_init(void){
    __delay_ms(30);
    /*
     TMP102はパワーオンから26ms経過してから温度変換開始する。
     */
}

/*
 TMP102より温度を読み出す。レジスタ0x00を選択した後２バイト読み出す。
 最初に読みだしたデータが温度の上位8bit、次の8bitの上位4bitが温度の
 下位4bit。
 戻り値　0 = 正常 1=異常　相手からAck無し -1=バス衝突リトライオーバー
 
 温度の更新周期は４Hz（２５０ｍｓ）なので、早く呼び出しても意味がない
 */
int16_t tmp102_read_temp(int16_t *tmp){
    int16_t retVal;
    uint8_t data[2];
    int16_t i;
    
    retVal= I2C1_SlaveRead(TMP102ADDR,0x00,&data[0],2);
    if ((data[0] & 0x80) !=0 ) {
        //温度がマイナス領域
        data[0] = data[0]^0xFF; //ビット反転
        data[1] = data[1]^0xFF; //ビット反転
        i = (data[0] << 8) | data[1];
        i = (i >> 4) & 0x0FFF;
        //uint_16の12bitsが温度データ
        //求めた温度に１を足して、さらに負の値にする
        *tmp = (i + 1) * (-1);
    } 
    else {
        //温度が＋領域の場合
        i = (data[0] << 8) | data[1];
        *tmp = (i >> 4) & 0x0FFF;  
        //uint_16の12bitsが温度データ
    }
    //ここで求めたTmp102_Temperatureに0.0625を掛けると摂氏温度になる。
    //温度（℃）＝　Tmp102_Temperature * 0.0625; 温度はdoubleになるので、
    //PICで小数点演算はプログラムサイズが大きいから
    //ここでは計算しないで、ホストで計算してもらう。
    return retVal;
}