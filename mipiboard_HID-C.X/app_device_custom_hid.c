/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

/** INCLUDES *******************************************************/
#include "mcc_generated_files/usb/usb.h"
#include "mcc_generated_files/usb/usb_device_hid.h"
#include <string.h>
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/dac082s085.h"
#include "mcc_generated_files/thd_i2c1.h"
#include "mcc_generated_files/thd_i2c2.h"
#include "mcc_generated_files/oc1.h"
#include "mcc_generated_files/oc2.h"
#include "mcc_generated_files/oc3.h"
#include "extern_val.h"
#include "mcc_generated_files/tmr2.h"
#include "mcc_generated_files/TC358870.h"
#include "mcc_generated_files/santek_qhd_lcd.h"
#include "mcc_generated_files/power_reset.h"

/** VARIABLES ******************************************************/
/* Some processors have a limited range of RAM addresses where the USB module
 * is able to access.  The following section is for those devices.  This section
 * assigns the buffers that need to be used by the USB module into those
 * specific areas.
 */

#if defined(FIXED_ADDRESS_MEMORY)
    #if defined(COMPILER_MPLAB_C18)
        #pragma udata HID_CUSTOM_OUT_DATA_BUFFER = HID_CUSTOM_OUT_DATA_BUFFER_ADDRESS
        unsigned char ReceivedDataBuffer[64];
        #pragma udata HID_CUSTOM_IN_DATA_BUFFER = HID_CUSTOM_IN_DATA_BUFFER_ADDRESS
        unsigned char ToSendDataBuffer[64];
        #pragma udata

    #elif defined(__XC8)
        unsigned char ReceivedDataBuffer[64] HID_CUSTOM_OUT_DATA_BUFFER_ADDRESS;
        unsigned char ToSendDataBuffer[64] HID_CUSTOM_IN_DATA_BUFFER_ADDRESS;
    #endif
#else
    unsigned char ReceivedDataBuffer[64];
    unsigned char ToSendDataBuffer[64];

#endif
    

volatile USB_HANDLE USBOutHandle;    
volatile USB_HANDLE USBInHandle;

uint8_t mem_buffer[32];       //EEPROM用メモリバッファ
uint16_t da_data;
int16_t index_retVal;
uint16_t mem_adr;
uint8_t  mem_num;
uint16_t BackLight_Status = 0;
uint16_t BackLight_Kido = 0;

uint16_t fan_data;
uint16_t fan2_data;

uint8_t tc_sys_status; 
uint8_t tc_video_input_status; 
uint8_t tc_video_input_status1; 
uint8_t tc_audio_status0; 

extern uint16_t    m_brightness;
extern bool m_bSuspendflg;
extern uint16_t TC_State;
extern uint16_t m_version;
extern uint16_t m_boardVersion;

bool m_bColorBar_Req  = false;  //カラーバー表示要求
bool m_bColorBar_Show = false;  //カラーバー表示中

/** DEFINITIONS ****************************************************/
typedef enum
{
    COMMAND_GET_STATUS = 0x01,      //ホストからステータス要求
    COMMAND_SET_BACKLIGHT= 0x02,    //バックライト指定出力点灯
    COMMAND_SET_IRLED = 0x03,       //IRLE指定出力点灯
    COMMAND_SET_FAN = 0x04,         //FANのON-OFF
    COMMAND_SET_FAN2 = 0x05,         //FANのON-OFF
    COMMAND_SET_LED = 0x06,         //LEDのON-OFF
    COMMAND_SYSMEM_WRITE = 0x07,    //システムデータ書き込み
    COMMAND_SYSMEM_READ = 0x08,     //システムデータ読み込み
    COMMAND_USRMEM_READ = 0x09,     //ユーザデータ読み込み
    COMMAND_USRMEM_WRITE = 0x0A,    //ユーザデータ書き込み
    COMMAND_BL_ON = 0x0B,           //メモリ値でバックライトON OFF
    COMMAND_IRLED_ON = 0x0C,        //メモリ値でIRLED ON OFF
    COMMAND_FAN_ON = 0x0D,          //指定温度でFAN ON OFF
    COMMAND_BL_NAVI = 0x0E,         //バックライト安定化制御
    COMMAND_GET_VER = 0x0F,         //バージョン情報取得
    COMMAND_BOOTLOADER = 0x10,      //ブートローダー起動
    COMMAND_HDMIRST = 0x11,         //HDMI RXのリセット
    COMMAND_DSIRST = 0x12,          //DSI TXのリセット
    COMMAND_COLORBAR = 0x13,        //カラーバー表示     
    COMMAND_GET_SYSSTS = 0x14,      //システムステータス取得
    COMMAND_CAMERA_RESET = 0x15,       //カメラのリセット
    COMMAND_UNKNOWN= 0xFF,          //不明なコマンド
} CUSTOM_HID_DEMO_COMMANDS;

/** FUNCTIONS ******************************************************/

/*********************************************************************
* Function: void APP_DeviceCustomHIDInitialize(void);
*
* Overview: Initializes the Custom HID demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCustomHIDInitialize()
{
    //initialize the variable holding the handle for the last
    // transmission
    USBInHandle = 0;

    //enable the HID endpoint
    USBEnableEndpoint(CUSTOM_DEVICE_HID_EP, USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

    //Re-arm the OUT endpoint for the next packet
    USBOutHandle = (volatile USB_HANDLE)HIDRxPacket(CUSTOM_DEVICE_HID_EP,(uint8_t*)&ReceivedDataBuffer[0],64);
}

/*********************************************************************
* Function: void APP_DeviceCustomHIDTasks(void);
*
* Overview: Keeps the Custom HID demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceCustomHIDInitialize() and APP_DeviceCustomHIDStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/

void APP_DeviceCustomHIDTasks()
{   
    /* If the USB device isn't configured yet, we can't really do anything
     * else since we don't have a host to talk to.  So jump back to the
     * top of the while loop. */
    
    
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    /* If we are currently suspended, then we need to see if we need to
     * issue a remote wakeup.  In either case, we shouldn't process any
     * keyboard commands since we aren't currently communicating to the host
     * thus just continue back to the start of the while loop. */
    if( USBIsDeviceSuspended()== true )
    {
        return;
    }
    
    //Check if we have received an OUT data packet from the host
    if(HIDRxHandleBusy(USBOutHandle) == false)
    {   
        //We just received a packet of data from the USB host.
        //Check the first uint8_t of the packet to see what command the host
        //application software wants us to fulfill.
        if(ReceivedDataBuffer[0] == 0x05){
            if(m_bSuspendflg){
                BackLight_ON_SetLow();
            }
            switch(ReceivedDataBuffer[1])				//Look at the data the host sent, to see what kind of application specific command it sent.
            {
                case COMMAND_GET_STATUS:  //ステータス送信コマンド
                    m_bSuspendflg = false;
                    if(BackLight_Status && (TC_State == 3)){
                        BackLight_ON_SetHigh();
                    }
                    
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_GET_STATUS;   //コマンドエコーバック
                        ToSendDataBuffer[2] = (uint8_t)(TMP102_Val >> 8);
                        ToSendDataBuffer[3] = (uint8_t)(TMP102_Val & 0xFF);
                        ToSendDataBuffer[4] = (uint8_t)(CDS_AD_Val >> 8);
                        ToSendDataBuffer[5] = (uint8_t)(CDS_AD_Val & 0xFF);
                        ToSendDataBuffer[6] = (uint8_t)(BL_AD_Val >> 8);
                        ToSendDataBuffer[7] = (uint8_t)(BL_AD_Val & 0xFF);
                        ToSendDataBuffer[8] = (uint8_t)(ADXL350_X_Val >> 8);
                        ToSendDataBuffer[9] = (uint8_t)(ADXL350_X_Val & 0xFF);
                        ToSendDataBuffer[10] = (uint8_t)(ADXL350_Y_Val >> 8);
                        ToSendDataBuffer[11] = (uint8_t)(ADXL350_Y_Val & 0xFF);
                        ToSendDataBuffer[12] = (uint8_t)(ADXL350_Z_Val >> 8);
                        ToSendDataBuffer[13] = (uint8_t)(ADXL350_Z_Val & 0xFF);
                        ToSendDataBuffer[14] = (uint8_t)(BH1750_Val >> 8);
                        ToSendDataBuffer[15] = (uint8_t)(BH1750_Val & 0xFF);
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_SET_BACKLIGHT:  //バックライト制御コマンド
                    if(ReceivedDataBuffer[3] > 0){  //チェック下位バイトだけ
                        da_data = ReceivedDataBuffer[4];
                        da_data = da_data << 8;
                        da_data = da_data | ReceivedDataBuffer[5];
                        //da_data = da_data & 0x03FF;
                        //da_data = da_data & 0x3E80;
                        da_data = da_data & 0x3FFF;     //20210114
                        m_brightness = da_data;
                        // Change 2020/02/26 PWM Set
                        OC1_PrimaryValueSet(da_data);
                        //Spi_LT1661_Set(BACK_LIGHT,da_data);  //バックライト輝度セット
                        if (!m_bSuspendflg && (TC_State == 3)){
                            BackLight_ON_SetHigh();
                        }
                        BackLight_Status = 1;
                        //BackLight_Kido = da_data;
                    }
                    else {
                        BackLight_ON_SetLow();
                        BackLight_Status = 0; //バックライト消灯
                        m_brightness = 0;
                    }
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SET_BACKLIGHT;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_SET_IRLED:  //IRLED制御コマンド
                    da_data = ReceivedDataBuffer[2];
                    da_data = da_data << 8;
                    da_data = da_data | ReceivedDataBuffer[3];
                    da_data = da_data & 0x03FF;  
                    DAC082S085_Set(IRLED_LEFT,da_data); 
                    da_data = ReceivedDataBuffer[4];
                    da_data = da_data << 8;
                    da_data = da_data | ReceivedDataBuffer[5];
                    da_data = da_data & 0x03FF;
                    DAC082S085_Set(IRLED_RIGHT,da_data);
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SET_IRLED;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_SET_FAN:  //FANのONOFF
                    if(ReceivedDataBuffer[3] > 0){  //チェック下位バイトだけ
                        fan_data = ReceivedDataBuffer[4];
                        fan_data = fan_data << 8;
                        fan_data = fan_data | ReceivedDataBuffer[5];
                        fan_data = fan_data & 0x3E80;
                        //fan_data = fan_data & 0x03FF;
                        OC2_PrimaryValueSet(fan_data);
                    }
                    else {
                        //0でOCセット
                        OC2_PrimaryValueSet(0);
                    }
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SET_FAN;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_SET_FAN2:  //FAN2のONOFF
                    if(ReceivedDataBuffer[3] > 0){  //チェック下位バイトだけ
                        fan2_data = ReceivedDataBuffer[4];
                        fan2_data = fan2_data << 8;
                        fan2_data = fan2_data | ReceivedDataBuffer[5];
                        fan2_data = fan2_data & 0x3E80;
                        //fan2_data = fan2_data & 0x03FF;
                        OC3_PrimaryValueSet(fan2_data);
                        //OCセット
                    }
                    else {
                        //0でOCセット
                        OC3_PrimaryValueSet(0);
                    }
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SET_FAN2;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_SET_LED:  //LED点灯制御
                    //LED無しなので何もしない
//                    switch(ReceivedDataBuffer[3]){
//                        case 0:
//                            LED_G_ON_SetLow();
//                            LED_R_ON_SetLow();
//                            break;
//                        case 1:
//                            LED_R_ON_SetHigh();
//                            LED_G_ON_SetLow();
//                            break;
//                        case 2:
//                            LED_G_ON_SetHigh();
//                            LED_R_ON_SetLow();
//                            break;
//                        case 3:
//                            LED_R_ON_SetHigh();
//                            LED_G_ON_SetHigh();
//                            break;
//                    }
                     if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SET_LED;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }               
                    break;
                case COMMAND_SYSMEM_WRITE:  //システムメモリにデータ書き込み
                    for (index_retVal = 0; index_retVal < 10; index_retVal++){
                       mem_buffer[index_retVal] = ReceivedDataBuffer[2+index_retVal]; //レシーブバッファから内容コピー
                    }
                    index_retVal = I2C1_EEPROM_Write(SYSMEM_ADR,&mem_buffer[0],10);
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SYSMEM_WRITE;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }                              
                    break;
                case COMMAND_SYSMEM_READ:  //システムメモリからデータ読み込み
                    if(!HIDTxHandleBusy(USBInHandle))
                    {                
                        index_retVal = I2C1_EEPROM_Read(SYSMEM_ADR,&mem_buffer[0],10);
                        for (index_retVal = 0; index_retVal < 10; index_retVal++){
                           ToSendDataBuffer[2+index_retVal] = mem_buffer[index_retVal]; //レシーブバッファから内容コピー
                        }                
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_SYSMEM_READ;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }       
                    break;
                case COMMAND_USRMEM_READ:  //ユーザメモリからデータ読み込み
                    mem_adr = ReceivedDataBuffer[2];
                    mem_adr = mem_adr << 8;
                    mem_adr = mem_adr | ReceivedDataBuffer[3];
                    mem_num = ReceivedDataBuffer[5];
                    if(!HIDTxHandleBusy(USBInHandle))
                    {                
                        index_retVal = I2C1_EEPROM_Read(mem_adr,&mem_buffer[0],mem_num);
                        for (index_retVal = 0; index_retVal < mem_num; index_retVal++){
                           ToSendDataBuffer[4+index_retVal] = mem_buffer[index_retVal]; //レシーブバッファから内容コピー
                        }                
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_USRMEM_READ;   //コマンドエコーバック
                        ToSendDataBuffer[2] = 0x00;   //コマンドエコーバック
                        ToSendDataBuffer[3] = mem_num;   //コマンドエコーバック                    
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }                
                    break;
                case COMMAND_USRMEM_WRITE:  //ユーザメモリにデータ書き込み
                    mem_adr = ReceivedDataBuffer[2];
                    mem_adr = mem_adr << 8;
                    mem_adr = mem_adr | ReceivedDataBuffer[3];
                    mem_num = ReceivedDataBuffer[5];
                    // ガード
                    if (mem_num == 0 || mem_num > 32 ||
                        mem_adr < 0x0100 ||
                        mem_adr > (0x2000 - mem_num))
                    {
                        if(!HIDTxHandleBusy(USBInHandle))
                        {
                            ToSendDataBuffer[0] = 0x0A;
                            ToSendDataBuffer[1] = 0xFF;
                            ToSendDataBuffer[2] = 0x02; // エラーコード（仮）
                            USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                        }
                        break;
                    }
                    for (index_retVal = 0; index_retVal < mem_num; index_retVal++){
                       mem_buffer[index_retVal] = ReceivedDataBuffer[6+index_retVal]; //レシーブバッファから内容コピー
                    }
                    index_retVal = I2C1_EEPROM_Write(mem_adr,&mem_buffer[0],mem_num);
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_USRMEM_WRITE;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }     
                    break;
                case COMMAND_BL_ON:  //パラメータがセットされている場合のBL ON
                    break;
                case COMMAND_IRLED_ON:  //パラメータがセットされている場合のIRLED　ON
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x81;				//Echo back to the host PC the command we are fulfilling in the first uint8_t.  In this case, the Get Pushbutton State command.
    //                    if(BUTTON_IsPressed(BUTTON_USB_DEVICE_HID_CUSTOM) == false)	//pushbutton not pressed, pull up resistor on circuit board is pulling the PORT pin high
    //                    {
    //                            ToSendDataBuffer[1] = 0x01;
    //                    }
    //                    else									//sw3 must be == 0, pushbutton is pressed and overpowering the pull up resistor
    //                    {
    //                            ToSendDataBuffer[1] = 0x00;
    //                    }
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;

                case COMMAND_FAN_ON:	//FAN温度がセットされている場合のFAN　ON
                    {
    //                    uint16_t pot;

                        //Check to make sure the endpoint/buffer is free before we modify the contents
                        if(!HIDTxHandleBusy(USBInHandle))
                        {
                            //Use ADC to read the I/O pin voltage.  See the relevant HardwareProfile - xxxxx.h file for the I/O pin that it will measure.
                            //Some demo boards, like the PIC18F87J50 FS USB Plug-In Module board, do not have a potentiometer (when used stand alone).
                            //This function call will still measure the analog voltage on the I/O pin however.  To make the demo more interesting, it
                            //is suggested that an external adjustable analog voltage should be applied to this pin.

    //                        pot = ADC_Read10bit(ADC_CHANNEL_POTENTIOMETER);

                            ToSendDataBuffer[0] = 0x37;  	//Echo back to the host the command we are fulfilling in the first uint8_t.  In this case, the Read POT (analog voltage) command.
    //                        ToSendDataBuffer[1] = (uint8_t)pot; //LSB
    //                        ToSendDataBuffer[2] = pot >> 8;     //MSB


                            //Prepare the USB module to send the data packet to the host
                            USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                        }
                    }
                    break;
                case COMMAND_GET_VER:  //バージョン取得コマンド
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_GET_VER;   //コマンドエコーバック
                        // FW Version
                        ToSendDataBuffer[2] = (uint8_t)(m_version >> 8);
                        ToSendDataBuffer[3] = (uint8_t)(m_version & 0xFF);
                        // Board Version
                        ToSendDataBuffer[4] = 0x00;
                        ToSendDataBuffer[5] = m_boardVersion;
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);    
                    }
                    break;
                case COMMAND_BOOTLOADER: //ブートローダ起動
                    mem_buffer[0] = (BOOTFLAG >> 8);   //ブートローダ起動フラグ
                    mem_buffer[1] = (BOOTFLAG & 0xFF);   //ブートローダ起動フラグ
                    I2C1_EEPROM_Write(SYSMEM_ADR + BOOTFLAG_OFFSET,&mem_buffer[0],2);
                    //ブートフラグを書き込んだので、USBを挿しなおすとブートローダモードで起動する。
                        
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_BOOTLOADER;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
                    break;
                case COMMAND_HDMIRST:  //HDMIリセット
                    i2c2_uh2cd_write16(0x0002,0x0100);  //HDMIリセット
                    __delay_ms(10);
                    i2c2_uh2cd_write16(0x0002,0x0000);
                    TC_State = 0;   //S0に戻す
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_HDMIRST;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);    
                    }
                    break;
                case COMMAND_DSIRST:  //DSIリセット
                    tc358870_dsi_reset();
                    santek_RS3();
                    
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_DSIRST;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);    
                    }
                    break;
                case COMMAND_COLORBAR:  //カラーバー表示
                    if (ReceivedDataBuffer[3] == 1){
                        m_bColorBar_Req = true;
                        m_bColorBar_Show = false;
                    }else{
                        m_bColorBar_Req = false;
                    }
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_COLORBAR;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);    
                    }
                    break;
                case COMMAND_GET_SYSSTS:  //システムステータス
                    tc_sys_status = i2c2_uh2cd_read8(0x8520); //SYS_STATUS
                    tc_video_input_status = i2c2_uh2cd_read8(0x8521); //VIDEO_INPUT_STATUS
                    tc_video_input_status1 = i2c2_uh2cd_read8(0x8522); //VIDEO_INPUT_STATUS1
                    tc_audio_status0 = i2c2_uh2cd_read8(0x8523); //AUDIO_STATUS0
                    
                    //Check to make sure the endpoint/buffer is free before we modify the contents
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_GET_SYSSTS;   //コマンドエコーバック
                        ToSendDataBuffer[2] = 0;
                        ToSendDataBuffer[3] = tc_sys_status;
                        ToSendDataBuffer[4] = 0;
                        ToSendDataBuffer[5] = tc_video_input_status;
                        ToSendDataBuffer[6] = 0;
                        ToSendDataBuffer[7] = tc_video_input_status1;
                        ToSendDataBuffer[8] = 0;
                        ToSendDataBuffer[9] = tc_audio_status0;
                        
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);    
                    }
                    break;
                case COMMAND_CAMERA_RESET:  //カメラのリセット
                    switch(ReceivedDataBuffer[3]){
                        case 0:
                        	//すべてのカメラリセット
                            Camera_Reset(0);
                            break;
                        case 1:
                        	//左カメラリセット
                            Camera_Reset(1);
                            break;
                        case 2:
                        	//中央カメラリセット
                            Camera_Reset(2);
                            break;
                        case 3:
                        	//右カメラリセット
                            Camera_Reset(3);
                            break;
                        default:
                        	break;
                    }
                     if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_CAMERA_RESET;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }   
                    break;
                default:
                    //登録されていない不正なコマンドの場合
                    if(!HIDTxHandleBusy(USBInHandle))
                    {
                        ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                        ToSendDataBuffer[1] = COMMAND_UNKNOWN;   //コマンドエコーバック
                        //Prepare the USB module to send the data packet to the host
                        USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
                    }
            }
        }else{
            //最初が05以外の不正なコマンドの場合
            if(!HIDTxHandleBusy(USBInHandle))
            {
                ToSendDataBuffer[0] = 0x0A;	  //返信先頭バイト
                ToSendDataBuffer[1] = COMMAND_UNKNOWN;   //コマンドエコーバック
                //Prepare the USB module to send the data packet to the host
                USBInHandle = HIDTxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ToSendDataBuffer[0],64);
            }
        }
        //Re-arm the OUT endpoint, so we can receive the next OUT data packet 
        //that the host may try to send us.
        USBOutHandle = HIDRxPacket(CUSTOM_DEVICE_HID_EP, (uint8_t*)&ReceivedDataBuffer[0], 64);
//        int i;
//        for(i=0; i < 65; i++){  //0クリア
//            ReceivedDataBuffer[i] = 0;
//        }
    }
}