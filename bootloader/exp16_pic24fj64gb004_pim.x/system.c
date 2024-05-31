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

#include <p24FJ64GB004.h>
#include <system.h>
#include <system_config.h>
#include <usb.h>

/*********************************************************************
* Function: void SYSTEM_Initialize( SYSTEM_STATE state )
*
* Overview: Initializes the system.
*
* PreCondition: None
*
* Input:  SYSTEM_STATE - the state to initialize the system into
*
* Output: None
*
********************************************************************/
void SYSTEM_Initialize( SYSTEM_STATE state )
{
    switch(state)
    {
        case SYSTEM_STATE_USB_START:
            
            //On the PIC24FJ64GB004 Family of USB microcontrollers, the PLL will not power up and be enabled
            //by default, even if a PLL enabled oscillator configuration is selected (such as HS+PLL).
            //This allows the device to power up at a lower initial operating frequency, which can be
            //advantageous when powered from a source which is not gauranteed to be adequate for 32MHz
            //operation.  On these devices, user firmware needs to manually set the CLKDIV<PLLEN> bit to
            //power up the PLL.
//            {
//                unsigned int pll_startup_counter = 600;
//                CLKDIVbits.PLLEN = 1;
//                while(pll_startup_counter--);
//            }
//        
//            LED_Enable(LED_USB_DEVICE_STATE);
//            LED_Enable(LED_USB_DEVICE_HID_CUSTOM);
            
            break;
            
        case SYSTEM_STATE_USB_SUSPEND:
            break;
            
        case SYSTEM_STATE_USB_RESUME:
            break;
    }
}

#if defined(USB_INTERRUPT)
void __attribute__((interrupt,auto_psv)) _USB1Interrupt()
{
    USBDeviceTasks();
}
#endif

