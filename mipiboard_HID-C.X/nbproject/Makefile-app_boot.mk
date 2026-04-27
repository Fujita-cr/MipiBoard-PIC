#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-app_boot.mk)" "nbproject/Makefile-local-app_boot.mk"
include nbproject/Makefile-local-app_boot.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=app_boot
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_device_hid.c mcc_generated_files/usb/usb_events.c mcc_generated_files/usb/usb_hal_16bit.c mcc_generated_files/spi1.c mcc_generated_files/clock.c mcc_generated_files/adc1.c mcc_generated_files/ext_int.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/tmr5.c mcc_generated_files/thd_i2c1.c mcc_generated_files/thd_i2c2.c mcc_generated_files/ADXL350_TMP102.c mcc_generated_files/ltc1661.c mcc_generated_files/power_reset.c mcc_generated_files/system.c mcc_generated_files/TC358870.c mcc_generated_files/santek_qhd_lcd.c mcc_generated_files/ortustech_hd_lcd.c mcc_generated_files/oc1.c mcc_generated_files/oc2.c mcc_generated_files/oc3.c mcc_generated_files/tmr2.c app_device_custom_hid.c main.c mcc_generated_files/dac082s085.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o ${OBJECTDIR}/mcc_generated_files/ltc1661.o ${OBJECTDIR}/mcc_generated_files/power_reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/TC358870.o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o ${OBJECTDIR}/mcc_generated_files/oc1.o ${OBJECTDIR}/mcc_generated_files/oc2.o ${OBJECTDIR}/mcc_generated_files/oc3.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/app_device_custom_hid.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcc_generated_files/dac082s085.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/adc1.o.d ${OBJECTDIR}/mcc_generated_files/ext_int.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/tmr5.o.d ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d ${OBJECTDIR}/mcc_generated_files/power_reset.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/TC358870.o.d ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d ${OBJECTDIR}/mcc_generated_files/oc1.o.d ${OBJECTDIR}/mcc_generated_files/oc2.o.d ${OBJECTDIR}/mcc_generated_files/oc3.o.d ${OBJECTDIR}/mcc_generated_files/tmr2.o.d ${OBJECTDIR}/app_device_custom_hid.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/mcc_generated_files/dac082s085.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o ${OBJECTDIR}/mcc_generated_files/ltc1661.o ${OBJECTDIR}/mcc_generated_files/power_reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/TC358870.o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o ${OBJECTDIR}/mcc_generated_files/oc1.o ${OBJECTDIR}/mcc_generated_files/oc2.o ${OBJECTDIR}/mcc_generated_files/oc3.o ${OBJECTDIR}/mcc_generated_files/tmr2.o ${OBJECTDIR}/app_device_custom_hid.o ${OBJECTDIR}/main.o ${OBJECTDIR}/mcc_generated_files/dac082s085.o

# Source Files
SOURCEFILES=mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_device_hid.c mcc_generated_files/usb/usb_events.c mcc_generated_files/usb/usb_hal_16bit.c mcc_generated_files/spi1.c mcc_generated_files/clock.c mcc_generated_files/adc1.c mcc_generated_files/ext_int.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/tmr5.c mcc_generated_files/thd_i2c1.c mcc_generated_files/thd_i2c2.c mcc_generated_files/ADXL350_TMP102.c mcc_generated_files/ltc1661.c mcc_generated_files/power_reset.c mcc_generated_files/system.c mcc_generated_files/TC358870.c mcc_generated_files/santek_qhd_lcd.c mcc_generated_files/ortustech_hd_lcd.c mcc_generated_files/oc1.c mcc_generated_files/oc2.c mcc_generated_files/oc3.c mcc_generated_files/tmr2.c app_device_custom_hid.c main.c mcc_generated_files/dac082s085.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

# The following macros may be used in the pre and post step lines
_/_=\\
ShExtension=.bat
Device=PIC24FJ64GB004
ProjectDir="C:\WorkSpace\sparrow\PIC\HU-BoardPIC\mipiboard_HID-C.X"
ProjectName=mipiboard_HID
ConfName=app_boot
ImagePath="dist\app_boot\${IMAGE_TYPE}\mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ImageDir="dist\app_boot\${IMAGE_TYPE}"
ImageName="mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}"
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IsDebug="true"
else
IsDebug="false"
endif
MDFUHostPath="C:\Program Files\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pymdfu-bin.exe"
PYFWImageBuilderPath="C:\Program Files\Microchip\MPLABX\v6.25\mplab_platform\mplab-pymdfu\bin\windows\pyfwimagebuilder-bin.exe"

.build-conf:  .pre ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-app_boot.mk ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
	@echo "--------------------------------------"
	@echo "User defined post-build step: [combineAppAndBootloaderHex.bat ${ProjectDir} ${ImageDir} ${ImageName}]"
	@combineAppAndBootloaderHex.bat ${ProjectDir} ${ImageDir} ${ImageName}
	@echo "--------------------------------------"

MP_PROCESSOR_OPTION=24FJ64GB004
MP_LINKER_FILE_OPTION=,--script="..\bootloader\exp16_pic24fj64gb004_pim.x\hid_boot_p24FJ64GB004.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/app_boot/ce846ab7bae876435d3bbabd289adb06542e530e .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_descriptors.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/app_boot/eb574e60706f8feba134c4ff1c7f440748fb3c24 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o: mcc_generated_files/usb/usb_device_hid.c  .generated_files/flags/app_boot/65c2a94e872e9c0c4ede6cffa4b8db974ab866ea .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device_hid.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_events.o: mcc_generated_files/usb/usb_events.c  .generated_files/flags/app_boot/85f3a1fa6aadb0a3d3c70950ce3bc8069e99600f .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_events.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o: mcc_generated_files/usb/usb_hal_16bit.c  .generated_files/flags/app_boot/474006940860d73650b2252f291a1d13dad88553 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_hal_16bit.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/app_boot/c0c73256bec4018a18e23fd4ebf8117a3e8fc922 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/app_boot/12d23b9e96a6c640ceca0993150f0cadbdd874ce .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/app_boot/a2e885665926a2e7aaf1a96b454c83b9d3bfe58f .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/app_boot/2cd1fd002a094734f06a5a8892955cb0a4cec76a .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/app_boot/fb8512c0ab6700fcdc2049dfd66d589d17129d0e .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/app_boot/82434d7a79cad58efb2acd8462d9a7616df1b318 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/app_boot/c6b4fc456afc4c39d3154f9b8641a8910bc4085 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/app_boot/2f650929882956f876a4fc837f706c4b011546b9 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/app_boot/60cad120f180eae940ef7a2b40612effb6c1a3c1 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/thd_i2c1.o: mcc_generated_files/thd_i2c1.c  .generated_files/flags/app_boot/cfece9db9d1dbc157ee87c946be6a19cd5d7a009 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/thd_i2c2.o: mcc_generated_files/thd_i2c2.c  .generated_files/flags/app_boot/ef111e841acc5d9c52eabfa32ee136dbcff5a7f7 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c2.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o: mcc_generated_files/ADXL350_TMP102.c  .generated_files/flags/app_boot/3b4515e404e764867ca25e1a875c1832cd3db600 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ADXL350_TMP102.c  -o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ltc1661.o: mcc_generated_files/ltc1661.c  .generated_files/flags/app_boot/6e7441675467cb9f551b3edaa2642dfeb543d920 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ltc1661.c  -o ${OBJECTDIR}/mcc_generated_files/ltc1661.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ltc1661.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/power_reset.o: mcc_generated_files/power_reset.c  .generated_files/flags/app_boot/f5d04b6ecfe0a4b430eb9a35b7fe99edd3ac5e8d .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/mcc_generated_files/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/power_reset.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/app_boot/2d9067c8f04a7d7746ae7f4faacb8d8dfc3c120f .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/TC358870.o: mcc_generated_files/TC358870.c  .generated_files/flags/app_boot/f3bb6462269761ba65907f67328aec5a15e5cffc .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/TC358870.c  -o ${OBJECTDIR}/mcc_generated_files/TC358870.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/TC358870.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o: mcc_generated_files/santek_qhd_lcd.c  .generated_files/flags/app_boot/f2e7c40d08ea18a796c0c81c9fffb9dd2c598d93 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/santek_qhd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o: mcc_generated_files/ortustech_hd_lcd.c  .generated_files/flags/app_boot/ef12d2b4ef4ca81651fef87fcd0ad50c28a28389 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ortustech_hd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc1.o: mcc_generated_files/oc1.c  .generated_files/flags/app_boot/ed16258239c8c38e48fe17dd5fb87aec9a8cc566 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc1.c  -o ${OBJECTDIR}/mcc_generated_files/oc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc2.o: mcc_generated_files/oc2.c  .generated_files/flags/app_boot/d4cd28d4b5bf38ec8ef9f8931d418c112013c6ec .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc2.c  -o ${OBJECTDIR}/mcc_generated_files/oc2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc3.o: mcc_generated_files/oc3.c  .generated_files/flags/app_boot/e89a5b39f1cf07845206c66890b6e227658d3e6d .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc3.c  -o ${OBJECTDIR}/mcc_generated_files/oc3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc3.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/app_boot/1834350c594844f6f16cb6c433f9e833c3e7b03b .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/app_device_custom_hid.o: app_device_custom_hid.c  .generated_files/flags/app_boot/46208df0b7e2ae0a625e0da36d96f3ab64c84db2 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o.d 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_device_custom_hid.c  -o ${OBJECTDIR}/app_device_custom_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_custom_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/app_boot/5e3ede38b3b4b5eccc63efad1623926f31a1f1a5 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/dac082s085.o: mcc_generated_files/dac082s085.c  .generated_files/flags/app_boot/d488f326682bd924bf6b1d5b1d0acf067ffb7f18 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/dac082s085.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/dac082s085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/dac082s085.c  -o ${OBJECTDIR}/mcc_generated_files/dac082s085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/dac082s085.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/app_boot/f712a37c6c90957ff177422ddfd9a9376c09e52b .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_descriptors.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/app_boot/b7adb2041bc0a19984121dc658eb80de6af86f82 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o: mcc_generated_files/usb/usb_device_hid.c  .generated_files/flags/app_boot/fd89fecb7c6b0787d7c9c1587bc8c71943a39d5 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device_hid.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_events.o: mcc_generated_files/usb/usb_events.c  .generated_files/flags/app_boot/6c2b25e0cbdf910dac3315e0482a5c4b17e57bcd .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_events.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o: mcc_generated_files/usb/usb_hal_16bit.c  .generated_files/flags/app_boot/2c5ec69eade773958c0f0de88699e1cd450fd969 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_hal_16bit.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/app_boot/637e73d06a4adb2dbd5253e413c83c1b87285a4c .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/app_boot/9b5f4a2edb7216371529c9cf28627be8a1cfb85d .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/app_boot/51ffabb2c30af384c28a2760eccd0b1e7f89557 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/app_boot/9452880cb0a09d6562d16f24f27ea566f93c0132 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/app_boot/d5a04e1e62ed1db4af734a5d56801e39db068662 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/app_boot/a85ea642282afc22e4cf7d8b8feeaa59d4069f47 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/app_boot/6b6c01b899b14f4de980ad65342c73cc911cd2bb .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/app_boot/d1b46ae018968ffd8223520901f305183ff79ea6 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/app_boot/bf9a07fda23959a52c61979ebafceb5ee86c0d06 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/thd_i2c1.o: mcc_generated_files/thd_i2c1.c  .generated_files/flags/app_boot/dd9d5c0690228624f25d3b4f379a1c653bab0ce4 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/thd_i2c2.o: mcc_generated_files/thd_i2c2.c  .generated_files/flags/app_boot/29ebfbf18b33621beb1ff57554e8512daef075a4 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c2.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o: mcc_generated_files/ADXL350_TMP102.c  .generated_files/flags/app_boot/ad5c5f5024bdcce53566b3ac9cd2bf20ba654580 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ADXL350_TMP102.c  -o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ltc1661.o: mcc_generated_files/ltc1661.c  .generated_files/flags/app_boot/616b3c25f1c475a232c115a8cf9cf77d2105bded .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ltc1661.c  -o ${OBJECTDIR}/mcc_generated_files/ltc1661.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ltc1661.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/power_reset.o: mcc_generated_files/power_reset.c  .generated_files/flags/app_boot/4cea075d54bab82e7a89e9c0fff9b080700b359 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/mcc_generated_files/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/power_reset.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/app_boot/8b9d5832bbb15188d494b3135017c48c848b6cf .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/TC358870.o: mcc_generated_files/TC358870.c  .generated_files/flags/app_boot/7740dac5a7a08b47ce515b7baa3cbedd4e859d53 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/TC358870.c  -o ${OBJECTDIR}/mcc_generated_files/TC358870.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/TC358870.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o: mcc_generated_files/santek_qhd_lcd.c  .generated_files/flags/app_boot/ea4612e2b1263dd3bb4a42554ac6787645ebaa99 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/santek_qhd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o: mcc_generated_files/ortustech_hd_lcd.c  .generated_files/flags/app_boot/21cdd30a85a4dd8e7adbc706030cfb22b8d2447c .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ortustech_hd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc1.o: mcc_generated_files/oc1.c  .generated_files/flags/app_boot/ce580d134bf86093d63f5846eeb62dd40752c8f2 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc1.c  -o ${OBJECTDIR}/mcc_generated_files/oc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc2.o: mcc_generated_files/oc2.c  .generated_files/flags/app_boot/53a419376000c80ccfc669f215d44d7fddbe2718 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc2.c  -o ${OBJECTDIR}/mcc_generated_files/oc2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc2.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/oc3.o: mcc_generated_files/oc3.c  .generated_files/flags/app_boot/ef895c58c0f208c0179754990d9a6c0c1b28ad11 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc3.c  -o ${OBJECTDIR}/mcc_generated_files/oc3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc3.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/tmr2.o: mcc_generated_files/tmr2.c  .generated_files/flags/app_boot/e88df4f16da780b57d0635dab71207daaaf929e8 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr2.c  -o ${OBJECTDIR}/mcc_generated_files/tmr2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr2.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/app_device_custom_hid.o: app_device_custom_hid.c  .generated_files/flags/app_boot/10f870f29e1e7b51688d53a159ce007fda2410bd .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o.d 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_device_custom_hid.c  -o ${OBJECTDIR}/app_device_custom_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_custom_hid.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/app_boot/159ac4cc134779e9f6715d0d6ce02d7cfc894349 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/mcc_generated_files/dac082s085.o: mcc_generated_files/dac082s085.c  .generated_files/flags/app_boot/be4ddabccc3d2c3bd8cbfca75ffdd24760ccb7b .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/dac082s085.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/dac082s085.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/dac082s085.c  -o ${OBJECTDIR}/mcc_generated_files/dac082s085.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/dac082s085.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../bootloader/exp16_pic24fj64gb004_pim.x/hid_boot_p24FJ64GB004.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../bootloader/exp16_pic24fj64gb004_pim.x/hid_boot_p24FJ64GB004.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif

.pre:
	@echo "--------------------------------------"
	@echo "User defined pre-build step: [delete_old_hex.bat ${ProjectDir}]"
	@delete_old_hex.bat ${ProjectDir}
	@echo "--------------------------------------"

# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
