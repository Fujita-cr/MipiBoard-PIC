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
#include <system.h>
#include <system_config.h>

#include <usb.h>
#include <usb_device_hid.h>

#include <app_hid_boot_loader.h>
#include <app_led_usb_status.h>

#include "boot.h"

//app
#include "extern_val.h"
//#include "mcc_generated_files/ADXL350_TMP102.h"
//#include "mcc_generated_files/adc1.h"
//#include "mcc_generated_files/usb/usb.h"
//#include "mcc_generated_files/tmr5.h"
//#include "mcc_generated_files/ext_int.h"
#include "mcc_generated_files/thd_i2c1.h"
//#include "mcc_generated_files/thd_i2c2.h"
//#include "mcc_generated_files/spi1.h"
//#include "mcc_generated_files/traps.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/power_reset.h"
#include "mcc_generated_files/interrupt_manager.h"
#include "mcc_generated_files/clock.h"
//#include "mcc_generated_files/TC358870.h"
//#include "app_device_custom_hid.h"
//#include "mcc_generated_files/LTC1661.h"
//#include "mcc_generated_files/oc1.h"
//#include "mcc_generated_files/oc2.h"
//#include "mcc_generated_files/oc3.h"

//__delay_ms用
#define FCY 16000000UL 
#include <libpic30.h>

MAIN_RETURN main(void)
{
    //Switch to alternate interrupt vector table for bootloader
    INTCON2bits.ALTIVT = 1;
    
    //Configuration bitはアプリ側と同じにする必要がある
    PIN_MANAGER_Initialize();
    
    //Power関係を設定しないとアプリ側に切り替えた時にファンが回らない現象あり
    Power_Reset_Init(); //ピンのlow/highを設定　初期化時にされているはずだが
    Power_On();     //電源投入TC358870とLCDリセット解除
    
    //各種初期化
    INTERRUPT_Initialize();
    CLOCK_Initialize();
    //下記のSYSTEM_Initilizeでは何もしていない
    //SYSTEM_Initialize(SYSTEM_STATE_USB_START);
//    SPI1_Initialize();
    I2C1_Initialize();
//    ADC1_Initialize();
    // Add 2020/02/26 PWM
//    OC1_Initialize();
//    OC2_Initialize();
//    OC3_Initialize();
//    I2C2_Initialize();
    //EXT_INT_Initialize();
    //INTERRUPT_GlobalEnable();

    //EEPEOM読み込み
    uint8_t mem_buffer[2];       //EEPROM用メモリバッファ
    uint8_t boot_flag[2];

    __delay_ms(30);    //EEPROMの起動が終わっていないときがあるので30ms待つ

    boot_flag[0] = (BOOTFLAG >> 8);   //ブートローダ起動フラグ
    boot_flag[1] = (BOOTFLAG & 0xFF);   //ブートローダ起動フラグ
    int16_t ret = I2C1_EEPROM_Read(SYSMEM_ADR + BOOTFLAG_OFFSET,&mem_buffer[0],2);
    bool boot = (mem_buffer[0] == boot_flag[0]) && (mem_buffer[1] == boot_flag[1]);
    if((boot != true) && (RCON & 0x83) != 0){
        //if((RCON & 0x83) != 0)はリセットで起動した意味
        //アプリ起動
        INTCON2bits.ALTIVT = 0;
        GOTO_BOOT_ADDRESS;
    }
    
    USBDeviceInit();
    USBDeviceAttach();

    while(1)
    {
        //In case the application uses config bit settings that enable the WDT, we 
        //need to periodically clear it in order for the bootloader to run normally.
        //ClrWdt();   
        
        //SYSTEM_Tasks();

        #if defined(USB_POLLING)
            // Interrupt or polling method.  If using polling, must call
            // this function periodically.  This function will take care
            // of processing and responding to SETUP transactions
            // (such as during the enumeration process when you first
            // plug in).  USB hosts require that USB devices should accept
            // and process SETUP packets in a timely fashion.  Therefore,
            // when using polling, this function should be called
            // regularly (such as once every 1.8ms or faster** [see
            // inline code comments in usb_device.c for explanation when
            // "or faster" applies])  In most cases, the USBDeviceTasks()
            // function does not take very long to execute (ex: <100
            // instruction cycles) before it returns.
            USBDeviceTasks();
        #endif

        /* If the USB device isn't configured yet, we can't really do anything
         * else since we don't have a host to talk to.  So jump back to the
         * top of the while loop. */
        if( USBGetDeviceState() < CONFIGURED_STATE )
        {
            /* Jump back to the top of the while loop. */
            continue;
        }

        /* If we are currently suspended, then we need to see if we need to
         * issue a remote wakeup.  In either case, we shouldn't process any
         * keyboard commands since we aren't currently communicating to the host
         * thus just continue back to the start of the while loop. */
        if( USBIsDeviceSuspended() == true )
        {
            /* Jump back to the top of the while loop. */
            continue;
        }

        //Application specific tasks
        APP_HIDBootLoaderTasks();

    }//end while
}//end main


bool USER_USB_CALLBACK_EVENT_HANDLER(int event, void *pdata, uint16_t size)
{
    switch( event )
    {
        case EVENT_TRANSFER:
            break;

        case EVENT_SOF:
            /* We are using the SOF as a timer to time the LED indicator.  Call
             * the LED update function here. */
            //APP_LEDUpdateUSBStatus();
            break;

        case EVENT_SUSPEND:
            /* Update the LED status for the suspend event. */
            //APP_LEDUpdateUSBStatus();
            break;

        case EVENT_RESUME:
            /* Update the LED status for the resume event. */
            //APP_LEDUpdateUSBStatus();
            break;

        case EVENT_CONFIGURED:
            /* When the device is configured, we can (re)initialize the demo
             * code. */
            APP_HIDBootLoaderInitialize();
            break;

        case EVENT_SET_DESCRIPTOR:
            break;

        case EVENT_EP0_REQUEST:
            /* We have received a non-standard USB request.  The HID driver
             * needs to check to see if the request was for it. */
            USBCheckHIDRequest();
            break;

        case EVENT_BUS_ERROR:
            break;

        case EVENT_TRANSFER_TERMINATED:
            break;

        default:
            break;
    }
    return true;
}

/*******************************************************************************
 End of File
*/

