
/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated header file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides APIs for driver for ADC1.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.155.0-a
        Device            :  PIC24FJ64GB004
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.40
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "adc1.h"
/**
  Section: Data Type Definitions
*/

/* ADC Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

 */
typedef struct
{
	uint8_t intSample;
}

ADC_OBJECT;

static ADC_OBJECT adc1_obj;

/**
  Section: Driver Interface
*/


void ADC1_Initialize (void)
{
//    // ASAM disabled; ADSIDL disabled; DONE enabled; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC Clearing sample bit ends sampling and starts conversion; ADON enabled; 
//
//   AD1CON1 = 0x8001;
//
//    // CSCNA enabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every 2nd sample/conversion operation; 
//
//   AD1CON2 = 0x004;         //0x404
//
//    // SAMC 2; ADRC FOSC/2; ADCS 3; 
//
//   AD1CON3 = 0x203;
//
//    // CH0SA AN0; CH0SB AN0; CH0NB AVSS; CH0NA AVSS; 
//
//   AD1CHS = 0x00;
//
//    // CSSL9 disabled; CSSL8 disabled; CSSL7 disabled; CSSL6 disabled; CSSL5 disabled; CSSL4 disabled; CSSL3 disabled; CSSL2 disabled; CSSL15 disabled; CSSL1 enabled; CSSL14 disabled; CSSL0 enabled; CSSL13 disabled; CSSL12 disabled; CSSL11 disabled; CSSL10 disabled; 
//
//   AD1CSSL = 0x03;
//
//   adc1_obj.intSample = AD1CON2bits.SMPI;
   
    AD1CON1 = 0x00E4; // integer format, auto conversion,sample after conversion ends             

	AD1CON2 = 0x003C; // AVDD & AVSS as references,Disable Scan mode,interrupt after 16 sample/convert sequence,16 buffer levels, use MuxA              

    AD1CON3 = 0x0D09;// AD Clock as derivative of system clock,13TAD,16 samples are collected in 1mSec,Fcy =4Mhz 1Tcy=0.26uS              

	AD1CHS = 0x0000;// Positive sample input channel for MUX A to use AN0,Negative input channel for MUX A to use VR-

	AD1PCFG = 0xFFFC; //AN0,AN1 analog pin

 	AD1CSSL	= 0x0000; // Channel Scanning Disabled
    
    //新規追加
//    // ASAM enabled; ADSIDL disabled; DONE enabled; FORM Absolute decimal result, unsigned, right-justified; SAMP disabled; SSRC Clearing sample bit ends sampling and starts conversion; ADON enabled; 
//
//   AD1CON1 = 0x8005;
//
//    // CSCNA enabled; VCFG0 AVDD; VCFG1 AVSS; ALTS disabled; BUFM disabled; SMPI Generates interrupt after completion of every 2nd sample/conversion operation; 
//
//   AD1CON2 = 0x404;
//
//    // SAMC 16; ADRC FOSC/2; ADCS 15; 
//
//   AD1CON3 = 0x100F;
//
//    // CH0SA AN0; CH0SB AN0; CH0NB AVSS; CH0NA AVSS; 
//
//   AD1CHS = 0x00;
//
//    // CSSL9 disabled; CSSL8 disabled; CSSL7 disabled; CSSL6 disabled; CSSL5 disabled; CSSL4 disabled; CSSL3 disabled; CSSL2 disabled; CSSL15 disabled; CSSL1 enabled; CSSL14 disabled; CSSL0 enabled; CSSL13 disabled; CSSL12 disabled; CSSL11 disabled; CSSL10 disabled; 
//
//   AD1CSSL = 0x03;
//
//
//   adc1_obj.intSample = AD1CON2bits.SMPI;
}

void ADC1_Start(void)
{
   AD1CON1bits.ADON = 1;     // Turn on the A/D converter
   //AD1CON1bits.SAMP = 1;
}

void ADC1_Stop(void)
{
   AD1CON1bits.ADON = 0; 
    //AD1CON1bits.SAMP = 0;
}

uint16_t ADC1_ConversionResultBufferGet(uint16_t *buffer)
{
    int count;
    uint16_t *ADC16Ptr;

    ADC16Ptr = (uint16_t *)&(ADC1BUF0);

    for(count=0;count<=adc1_obj.intSample;count++)
    {
        buffer[count] = (uint16_t)*ADC16Ptr;
        ADC16Ptr++;
    }
    return count;
}

uint16_t ADC1_ConversionResultGet(void)
{
    return ADC1BUF0;
}

bool ADC1_IsConversionComplete( void )
{
    return AD1CON1bits.DONE; //Wait for conversion to complete   
}

void ADC1_ChannelSelect( ADC1_CHANNEL channel )
{
    AD1CHS = channel;
}

void __attribute__ ((weak)) ADC1_CallBack(void)
{
    // Add your custom callback code here
}

void ADC1_Tasks ( void )
{
	if(IFS0bits.AD1IF)
	{
		// ADC1 callback function 
		ADC1_CallBack();
	
		// clear the ADC interrupt flag
		IFS0bits.AD1IF = false;
	}
}

/*
 * void ADC1_Initialize (void)
 * 
 * 
 * void ADC1_ChannelSelect( ADC1_CHANNEL channel )
 * void ADC1_Start(void)
 * uint16_t adc_api()
 * void ADC1_Stop(void)
 
 */
uint16_t adc_api( void )
{
	while(IFS0bits.AD1IF == 0){
        
    }
	IFS0bits.AD1IF = 0;	
    return  ADC1BUF0;
}

/*
 ADC_XXXXX_ReadはADコンバータから読み取った値を返す
 */
uint16_t ADC_BLSENSOR_Read(void)
{
    
    uint16_t conversion;
    int16_t i;
    ADC1_ChannelSelect( ADC1_CHANNEL_AN1_BLSENSOR);
    ADC1_Start();
    for(i=0;i <1000;i++)
    {
    }
    conversion = adc_api();
    ADC1_Stop();
    conversion &=0x03FF;
//    while(!ADC1_IsConversionComplete())
//    {
//        ADC1_Tasks();   
//    }
//    conversion = ADC1_ConversionResultGet();
    return conversion;
}
uint16_t ADC_CDS_Read(void)
{
    
    uint16_t conversion;
    int16_t i;

    ADC1_ChannelSelect( ADC1_CHANNEL_AN0_CDS);
    ADC1_Start();
    //Provide Delay
    for(i=0;i <1000;i++)
    {
    }
    conversion = adc_api();  
    ADC1_Stop();
    conversion &=0x03FF;
//    while(!ADC1_IsConversionComplete())
//    {
//        ADC1_Tasks();   
//    }
//    conversion = ADC1_ConversionResultGet();
    return conversion;
}



/**
  End of File
*/
