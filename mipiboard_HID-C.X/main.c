//////////////////////////////////////////////////////////////////////////////////////
// 　　　　　　　　　　　　　 プロジェクトを開くときの注意
//////////////////////////////////////////////////////////////////////////////////////
// 最初にmipiboard_HID-C.Xを開く。
// 次にbootloaderフォルダ内のexp16_pic24fj64gb004_pim.xを開く
// mipiboard_HIDを右クリックしてSet as main projectする。
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
// 　　　　　　　　　　　　　 バージョン変更時の注意
//////////////////////////////////////////////////////////////////////////////////////
// バージョン変更時は、下記の手順で行う
// １．main.cのバージョン履歴に変更点の説明を書く
// ２．main.cのm_versionのバージョン番号を書き換える（変数定義の最後辺り）
// ３．git commitする
// ４．「app boot」のコンフィグに設定する
// ５．「mipiboard_HID」のプロジェクトを右クリックして「Clean and build」
// ６．出力されたHexファイルの日付時刻を確認する。
//////////////////////////////////////////////////////////////////////////////////////

//******************************************************************************
//***************************** バージョン履歴 **********************************
//******************************************************************************
//
//2021年1月 V01・・・初期バージョン
//2023年6月 V02・・・加速度センサー無し対応
//20231026 V10・・・USBでのファームウェア書き込みに対応した。（ここから篠田担当）
//                  USBサスペンド信号でPICがスリープしないようにした。（スリープからの復帰後にI2C通信できなくなる対策）
//                  サーバ資料「13.不具合対策」→「20231027_ボードの応答停止問題」を参照。
//20240208 V11・・・V12と同様の修正だが、EDIDを間違ったので欠番。
//20240208 V12・・・NUC13でオーディオを認識しない問題に対応。EDIDをモノラル1CHから2CHに変更した。
//                  サーバ資料「13.不具合対策」→「20240208_オーディオ認識の問題」を参照。
//                  3/14出荷分から適用
//20240330 V13・・・3300,3400基板でRGB(30,30,30）の画像を表示したときに液晶表示が乱れる問題に対応。EDIDのEQを無効にした。(V02からEQが有効になっていた）
//                  サーバ資料「13.不具合対策」→「20240330_液晶の乱れ」を参照。
//20240416 V14・・・NUC13で音が鳴らない問題の対策。メインループ前に12秒のウェイト追加。NUCのBIOSが起動しない問題あり。
//                  USB通信も止めてしまっているのが問題と思われる。
//                  サーバ資料「13.不具合対策」→「20240417_NUC13サウンド不具合対策」を参照。
//20240416 V15・・・V14でNUCのBIOSが起動しない問題の対策。USB通信は止めずに、HDMIの処理開始まで12秒待つようにした。
//                  サーバ資料「13.不具合対策」→「20240417_NUC13サウンド不具合対策」を参照。
//20240425 V16・・・HDMI切断直後の再接続で画面が表示されない問題の対策。HDMIステータス確認の間隔200ms→10ms。
//                  NUC11のHDMIのサウンド不具合対策で、HDMIの処理開始の待ち時間を20秒に変更。
//                  サーバ資料「13.不具合対策」→「20240427_液晶が表示されない不具合ほかの調査および対策」を参照。
//                  2024/5/10クリュート承認　6/14出荷分から適用
//20240613 V17(リリース無し）・・・画面非表示とサウンド問題の対策として下記の対応
//                  ・SYNC信号OFFの場合にS3→S1に戻す。
//                  ・接続ステータスを割り込みイベントと現在のステータスの両方で確認する。
//                  ・ステータス確認の間隔は10ms（念のためV16と同じ設定とする）
//                  ・起動時の待ち時間は30秒（NUC11での液晶非表示・サウンド不具合の対策）
//                  ・ミュートの追加（NUC13で起動時のスピーカー異音対策）
//                  ・HDMIスタートコマンドの追加。（待ち時間経過する前にHDMI接続を開始したいときに使用）
//                  下記はプロジェクトの変更
//                  ・不要なコメントを一部削除
//                  ・Git対応
//                  ・出力するHEXファイル名の変更。プロジェクトのフォルダ名でファイル名をつけるようにした。ビルド前に古いHEXファイルを削除するように変更。
//                    HEXファイルの名前付け処理の変更の関係で、プロジェクトのフォルダ名の付け方を変更。
//20250912 V1601（テスト用）・・・サスペンド処理の無効化
//20260227 V1602・・・V17をベースに下記の点を変更
//					・DDC5VがOFFになったときにS1に戻すように変更
//                  ・カラーバー表示から戻るときはICリセットが必要なので、従来通りの処理とした。
//                  ・HDMIRxリセットコマンドを実行した場合、S0から再開する処理とした。（ICリセットは不要）
//					・HDMIスタートコマンドは削除
//					・シャットダウン割り込み発生時に、1ms後に再確認するように変更。終了処理をより安全な方法に変更。
//					・起動時の待ち時間は20秒でV16と同じ
//                  ・従来は不明なUSBコマンド受信時にバックライトOFFにする処理が入っていたが不要なので削除し、不明なコマンドとして応答するように変更。
//                  ・（V17から引継ぎ）SYNC信号OFFの場合にS3→S1に戻す。
//                  ・（V17から引継ぎ）接続ステータスを割り込みイベントと現在のステータスの両方で確認する。
//                  ・（V17から引継ぎ）ステータス確認の間隔は10ms（V16と同じ設定とする）
//                  ・（V17から引継ぎ）ミュートの追加（NUC13で起動時のスピーカー異音対策）
//					・未接続のLED制御など不要なコードを削除。ポート初期化処理もそれに合わせて整理。
//                  ・コンパイルエラーになる場合があるのを修正。（ヘッダへの関数定義追加）
//                  ・MCCのGUI設定と実際のコード上の設定内容が違っていて混乱するのでMCC側を修正（ポート設定など）
//                  ・不要なコメントを一部削除
//                  下記はプロジェクトの設定変更
//                  ・Git対応
//                  ・出力するHEXファイル名の変更。プロジェクトのフォルダ名でファイル名をつけるようにした。ビルド前に古いHEXファイルを削除するように変更。
//20260227 V19・・・V1602をベースにV18の新基板向けカメラリセット機能を追加。
//******************************************************************************

/**
  Section: Included Files
*/
#include "extern_val.h"
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/ADXL350_TMP102.h"
#include "mcc_generated_files/adc1.h"
#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/tmr5.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/ext_int.h"
#include "mcc_generated_files/thd_i2c1.h"
#include "mcc_generated_files/thd_i2c2.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/traps.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/power_reset.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/TC358870.h"
#include "app_device_custom_hid.h"
#include "mcc_generated_files/LTC1661.h"
#include "mcc_generated_files/oc1.h"
#include "mcc_generated_files/oc2.h"
#include "mcc_generated_files/oc3.h"

// TC358870 State
#define S0      0
#define S1      1
#define S2      2
#define S3      3
#define RS1     4
#define RS2     5
#define RS3     6
#define RS4     7
#define RS5     8
#define RS_DO   9

uint16_t    BL_AD_Val = 0;
uint16_t    CDS_AD_Val = 0;
int16_t     TMP102_Val = 0;
int16_t     ADXL350_X_Val= 0;
int16_t     ADXL350_Y_Val = 0;
int16_t     ADXL350_Z_Val = 0;


// Average Calc Buffer
uint16_t    ad_arry[10];
uint16_t    sort_arry[10];
uint16_t    ad_val_tmp = 0;
int16_t     tmp102_tmp = 0;
int32_t     tmp102_sum = 0;
int16_t     x_val = 0;
int16_t     y_val = 0;
int16_t     z_val = 0;
int16_t     ADXL350_ari = 0;    //20230605 加速度センサあり

uint16_t    m_brightness = 0;

uint16_t TC_State;
bool m_bSuspendflg = false;

uint16_t TC358870_BootCount;         //HDMI起動待ち用のカウンタ
uint16_t TC358870_CheckAll = 0;      //HDMI接続チェック時にバックライト制御などを行うか

#define TC358870_BOOT_WAIT 10     //PCが起動するまでの待ち時間 100に設定したときは10msタイマーx20回(TC358870_CheckAll)x100回=20000ms(20秒)
                                  //TC358870_BOOT_WAIT=0のときは、最初の1回(200ms)だけ待ってHDMIの初期化が始まる

///////////////////////////////////////////////////////////////////////////////
//           プログラムのバージョン情報                                        //
//           プログラムを更新する場合に必ず書き換えること！                     //
///////////////////////////////////////////////////////////////////////////////
const uint16_t   m_version = 9906;  //プログラムのバージョン情報
uint8_t m_boardVersion;
///////////////////////////////////////////////////////////////////////////////

void I2C1_Device_init(void){

    tmp102_init();

    //初期化時に加速度センサー有り無し判定する
    ADXL350_ari = adxl350_init();
    //下の行で、再度加速度センサーありにしているが下記１行は削除でも良い。
    //その場合には、初期化処理に失敗したらセンサー無しと判断する。
    //初期化で失敗して、センサー有りにすると、初回の読取時に無しになる。
    ADXL350_ari = 0;
    //念のためデータも初期化しておく
    ADXL350_X_Val = 0;
    ADXL350_Y_Val = 0;
    ADXL350_Z_Val = 0;
    
    BL_Timer = 0;          //BLセンサースキャンタイマー
    CDS_Timer = 0;         //CDセンサースキャンタイマー
    TMP102_Timer = 0;      //TMP102温度センサスキャンタイマー
    ADXL350_Timer = 0;     //ADXL350加速度センサースキャンタイマー    
    TC358870_BootCount = 0;
    TC358870_CheckAll = 0;
}
void I2C1_Device_Check(void){
    int16_t retVal;
    int16_t tmp,x,y,z;
    int8_t  i;
    int8_t  j;
    
    if (BL_Timer > BL_SENSOR_SCAN_TIME){
        for (i = 0; i < 10; i++){
            ad_arry[i] =  ADC_BLSENSOR_Read() & 0x03FE;
        }
        for (i=0; i<10; ++i) {
            for (j=i+1; j<10; ++j) {
              if (ad_arry[i] > ad_arry[j]) {
                tmp =  ad_arry[i];
                ad_arry[i] = ad_arry[j];
                ad_arry[j] = tmp;
              }
            }
        }
        ad_val_tmp = 0;
        for(i= 2; i < 8; i++){
            ad_val_tmp = ad_val_tmp + ad_arry[i];
        }
        uint16_t BL_temp = ad_val_tmp / 6;
//        if (BL_temp > 0x398){ //920
//            BL_temp = 0x398;
//        }
        if (BL_temp > 0x3E8){   //1000
            BL_temp = 0x3E8;
        }
        BL_AD_Val = BL_temp;
        
        BL_Timer = 0;
        ad_val_tmp = 0;
    }
    if (CDS_Timer > CDS_SENSOR_SCAN_TIME){
        for (i = 0; i < 10; i++){
            ad_arry[i] =  ADC_CDS_Read() & 0x03FE;
        }
        for (i=0; i<10; ++i) {
            for (j=i+1; j<10; ++j) {
              if (ad_arry[i] > ad_arry[j]) {
                tmp =  ad_arry[i];
                ad_arry[i] = ad_arry[j];
                ad_arry[j] = tmp;
              }
            }
        }
        ad_val_tmp = 0;
        for(i= 2; i < 8; i++){
            ad_val_tmp = ad_val_tmp + ad_arry[i];
        }
        CDS_AD_Val = ad_val_tmp / 6;
        CDS_Timer = 0;
        ad_val_tmp = 0;
        //LED_R_ON_Toggle();
    }
    if (TMP102_Timer > TMP102_SCAN_TIME){
        tmp102_sum = 0;
        for(i = 0; i < 3; i++){
            retVal = tmp102_read_temp(&tmp102_tmp);
            tmp102_sum = tmp102_sum + (int32_t)tmp102_tmp;
        }
        TMP102_Val = (int16_t)(tmp102_sum / 3);
        TMP102_Timer = 0;
        //LED_G_ON_Toggle();
    }
    if ((ADXL350_Timer > ADXL350_SCAN_TIME) && (ADXL350_ari == 0)){
        j = 0;
        x_val = 0;
        y_val = 0;
        z_val = 0;
        
        for ( i = 0; i < 4; i++){
            if(adxl350_xyz_read(&x,&y,&z) == 0){
                x_val = x_val + x;
                y_val = y_val + y;
                z_val = z_val + z;
                j++;
            }
        }
        if( j == 0) {
            //一度もデータを読めない
            ADXL350_X_Val = 0;
            ADXL350_Y_Val = 0;
            ADXL350_Z_Val = 0;
            //加速度センサーは無い事にする
            ADXL350_ari = -1;
        }
        else {
            ADXL350_X_Val = x_val / j;
            ADXL350_Y_Val = y_val / j;
            ADXL350_Z_Val = z_val / j;            
        }
        ADXL350_Timer = 0;  
    }
    
}

void BOARD_VERSION_Initialize(void)
{
    m_boardVersion =
        (VERBIT3_GetValue() << 3) |
        (VERBIT2_GetValue() << 2) |
        (VERBIT1_GetValue() << 1) |
        (VERBIT0_GetValue() << 0);
}

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    PIN_MANAGER_Initialize();
    BOARD_VERSION_Initialize();
    Power_Reset_Init(); //ピンのlow/highを設定　初期化時にされているはずだが
    Power_On();     //電源投入TC358870とLCDリセット解除 USBカメラリセット解除
    INTERRUPT_Initialize();
    CLOCK_Initialize(); 
    //下記のSYSTEM_Initilizeでは何もしていない
    SYSTEM_Initialize(SYSTEM_STATE_USB_START);
    USBDeviceInit();
    USBDeviceAttach();
    SPI1_Initialize();
    I2C1_Initialize();
    ADC1_Initialize();
    // Add 2020/02/26 PWM
    OC1_Initialize();
    OC2_Initialize();
    OC3_Initialize();
    TMR2_Initialize();
    TMR5_Initialize();
    I2C2_Initialize();
    EXT_INT_Initialize();
    INTERRUPT_GlobalEnable();
    I2C1_Device_init(); 
    tc358870_init();  
    TMR5_Start(); 

    OC2_PrimaryValueSet(0x3E80);    //起動時に100%でFANを駆動
    OC3_PrimaryValueSet(0x3E80);
    
    //起動時にブートローダモードならOFFにする
    uint8_t boot_flag[2];
    uint8_t mem_buffer[2];
    int16_t ret = I2C1_EEPROM_Read(SYSMEM_ADR + BOOTFLAG_OFFSET,&mem_buffer[0],2);
    boot_flag[0] = (BOOTFLAG >> 8);   //ブートローダ起動フラグ
    boot_flag[1] = (BOOTFLAG & 0xFF);   //ブートローダ起動フラグ
    bool boot = (mem_buffer[0] == boot_flag[0]) && (mem_buffer[1] == boot_flag[1]);
    if (boot){
        mem_buffer[0] = 0;
        mem_buffer[1] = 0;
        ret = I2C1_EEPROM_Write(SYSMEM_ADR + BOOTFLAG_OFFSET,&mem_buffer[0],2);
        ret = I2C1_EEPROM_Read(SYSMEM_ADR + BOOTFLAG_OFFSET,&mem_buffer[0],2);
    }
    
    while (1)
    {
//IRLEDのテスト用コード
//OC1_PrimaryValueSet(150);
//Spi_LT1661_Set(1, 500);
//__delay_ms(100);
//        Spi_LT1661_Set(2, 1023);    //IRLED_L
//        __delay_ms(100);
//        Spi_LT1661_Set(3, 1023);    //IRLED_R
//        __delay_ms(100);
        
        I2C1_Device_Check();
        APP_DeviceCustomHIDTasks();
        if(TC358870_Timer >= 1){    //10ms毎にチェックする。これを長くするとHDMIの瞬断で画面が映らなくなるので注意。
            TC358870_CheckAll++;
            if (TC358870_CheckAll > 20){    //200ms毎に処理
                //起動待ち用のカウント
                //NUC13のBIOSが起動するのに7秒ぐらい。
                //待たないとHDMIの音が出ない場合があるので、20秒待ってから処理する。
                if (TC358870_BootCount > TC358870_BOOT_WAIT){
                    tc358870(true); //バックライト制御などは200msに1回
                }else if (TC358870_BootCount <= TC358870_BOOT_WAIT){
                    TC358870_BootCount++;   //200msで1カウント
                }
                TC358870_CheckAll = 0;
            }else{
                if (TC358870_BootCount > TC358870_BOOT_WAIT){
                    tc358870(false);    //HDMI周りは10msごとに処理
                }
            }
            TC358870_Timer = 0;
        }
        if(m_bSuspendflg){
            BackLight_ON_SetLow();
        }
    }
    return 1;
}

/**
 End of File
*/

