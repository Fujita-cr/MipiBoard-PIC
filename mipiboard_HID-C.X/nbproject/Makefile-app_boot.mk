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
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_device_hid.c mcc_generated_files/usb/usb_events.c mcc_generated_files/usb/usb_hal_16bit.c mcc_generated_files/spi1.c mcc_generated_files/clock.c mcc_generated_files/adc1.c mcc_generated_files/ext_int.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/tmr5.c mcc_generated_files/thd_i2c1.c mcc_generated_files/thd_i2c2.c mcc_generated_files/ADXL350_TMP102.c mcc_generated_files/ltc1661.c mcc_generated_files/power_reset.c mcc_generated_files/system.c mcc_generated_files/TC358870.c mcc_generated_files/santek_qhd_lcd.c mcc_generated_files/ortustech_hd_lcd.c mcc_generated_files/oc1.c mcc_generated_files/oc2.c mcc_generated_files/oc3.c app_device_custom_hid.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o ${OBJECTDIR}/mcc_generated_files/ltc1661.o ${OBJECTDIR}/mcc_generated_files/power_reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/TC358870.o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o ${OBJECTDIR}/mcc_generated_files/oc1.o ${OBJECTDIR}/mcc_generated_files/oc2.o ${OBJECTDIR}/mcc_generated_files/oc3.o ${OBJECTDIR}/app_device_custom_hid.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d ${OBJECTDIR}/mcc_generated_files/spi1.o.d ${OBJECTDIR}/mcc_generated_files/clock.o.d ${OBJECTDIR}/mcc_generated_files/adc1.o.d ${OBJECTDIR}/mcc_generated_files/ext_int.o.d ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d ${OBJECTDIR}/mcc_generated_files/mcc.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/traps.o.d ${OBJECTDIR}/mcc_generated_files/tmr5.o.d ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d ${OBJECTDIR}/mcc_generated_files/power_reset.o.d ${OBJECTDIR}/mcc_generated_files/system.o.d ${OBJECTDIR}/mcc_generated_files/TC358870.o.d ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d ${OBJECTDIR}/mcc_generated_files/oc1.o.d ${OBJECTDIR}/mcc_generated_files/oc2.o.d ${OBJECTDIR}/mcc_generated_files/oc3.o.d ${OBJECTDIR}/app_device_custom_hid.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o ${OBJECTDIR}/mcc_generated_files/spi1.o ${OBJECTDIR}/mcc_generated_files/clock.o ${OBJECTDIR}/mcc_generated_files/adc1.o ${OBJECTDIR}/mcc_generated_files/ext_int.o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o ${OBJECTDIR}/mcc_generated_files/mcc.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/mcc_generated_files/traps.o ${OBJECTDIR}/mcc_generated_files/tmr5.o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o ${OBJECTDIR}/mcc_generated_files/ltc1661.o ${OBJECTDIR}/mcc_generated_files/power_reset.o ${OBJECTDIR}/mcc_generated_files/system.o ${OBJECTDIR}/mcc_generated_files/TC358870.o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o ${OBJECTDIR}/mcc_generated_files/oc1.o ${OBJECTDIR}/mcc_generated_files/oc2.o ${OBJECTDIR}/mcc_generated_files/oc3.o ${OBJECTDIR}/app_device_custom_hid.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=mcc_generated_files/usb/usb_descriptors.c mcc_generated_files/usb/usb_device.c mcc_generated_files/usb/usb_device_hid.c mcc_generated_files/usb/usb_events.c mcc_generated_files/usb/usb_hal_16bit.c mcc_generated_files/spi1.c mcc_generated_files/clock.c mcc_generated_files/adc1.c mcc_generated_files/ext_int.c mcc_generated_files/interrupt_manager.c mcc_generated_files/mcc.c mcc_generated_files/pin_manager.c mcc_generated_files/traps.c mcc_generated_files/tmr5.c mcc_generated_files/thd_i2c1.c mcc_generated_files/thd_i2c2.c mcc_generated_files/ADXL350_TMP102.c mcc_generated_files/ltc1661.c mcc_generated_files/power_reset.c mcc_generated_files/system.c mcc_generated_files/TC358870.c mcc_generated_files/santek_qhd_lcd.c mcc_generated_files/ortustech_hd_lcd.c mcc_generated_files/oc1.c mcc_generated_files/oc2.c mcc_generated_files/oc3.c app_device_custom_hid.c main.c



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
ProjectDir="D:\20240425_test3(v17)_mipiboard_HID\mipiboard_HID-C.X"
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

.build-conf:  ${BUILD_SUBPROJECTS}
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
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/app_boot/62d3beae0270cfbb29ed07599866875e0f5d0099 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_descriptors.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/app_boot/ae39b61ccafe12ef1964e93b312b75925cce686c .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o: mcc_generated_files/usb/usb_device_hid.c  .generated_files/flags/app_boot/2b523ca96ee93c448e4ee7108d33d1d851b91ab1 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device_hid.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_events.o: mcc_generated_files/usb/usb_events.c  .generated_files/flags/app_boot/7c6617a4821bab02bfc7194d35044a44e7510655 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_events.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o: mcc_generated_files/usb/usb_hal_16bit.c  .generated_files/flags/app_boot/bbc9cc56d431f2680349ffc324eb559c35e9a3fd .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_hal_16bit.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/app_boot/2e9035dac4a3819abb2c7f24af231b34ae23d578 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/app_boot/6bf787817be901c940f8f41d289d3129b470bf3e .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/app_boot/915fa0a17c8d2e9c0eb01a431ba182fb7930057 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/app_boot/83ede7997416208e663f64342d2f9547eef63b0d .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/app_boot/80debb72cc9ced9faa9b1e98056af2f8288676f6 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/app_boot/494c8dc16bffeaa9140aa59ac4575f8be406aeb .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/app_boot/16c7f6e57cc58e458b0e8004bb12db535c9c8031 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/app_boot/17911971919897ebf8a0d466d5209c495c4370ce .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/app_boot/afb251a942cf877b8ab8bbdfcbfd1a12a17e329f .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/thd_i2c1.o: mcc_generated_files/thd_i2c1.c  .generated_files/flags/app_boot/be5ca0bed5a5d63ebd85b25f32c435aca1a5c934 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/thd_i2c2.o: mcc_generated_files/thd_i2c2.c  .generated_files/flags/app_boot/ebd8c52119dd1a01ad139f89604ec1990856281e .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c2.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o: mcc_generated_files/ADXL350_TMP102.c  .generated_files/flags/app_boot/bfdd19a6071f2ceaf3bee6b52d88cd23af07b9d4 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ADXL350_TMP102.c  -o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ltc1661.o: mcc_generated_files/ltc1661.c  .generated_files/flags/app_boot/66caebd237f23145027008707888ad931340c3f6 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ltc1661.c  -o ${OBJECTDIR}/mcc_generated_files/ltc1661.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ltc1661.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/power_reset.o: mcc_generated_files/power_reset.c  .generated_files/flags/app_boot/340e880f09bab2720bb3f7124679ba4223d91f01 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/mcc_generated_files/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/power_reset.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/app_boot/91dad08cf718a3f23ecb612f352422475a0bc5f4 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/TC358870.o: mcc_generated_files/TC358870.c  .generated_files/flags/app_boot/e89d0017b9e4bc5133556aed4f60d2fb2110a00b .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/TC358870.c  -o ${OBJECTDIR}/mcc_generated_files/TC358870.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/TC358870.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o: mcc_generated_files/santek_qhd_lcd.c  .generated_files/flags/app_boot/c7791646c39b450c2c66275e6c77331aaed30d65 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/santek_qhd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o: mcc_generated_files/ortustech_hd_lcd.c  .generated_files/flags/app_boot/4f9e0cc765caca6ce00f484d83a17941e44b26d1 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ortustech_hd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc1.o: mcc_generated_files/oc1.c  .generated_files/flags/app_boot/4af38bbeb3d77616008f1c18e93b5e145a523447 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc1.c  -o ${OBJECTDIR}/mcc_generated_files/oc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc2.o: mcc_generated_files/oc2.c  .generated_files/flags/app_boot/1128f877983ab412370dedae304de6372f8af712 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc2.c  -o ${OBJECTDIR}/mcc_generated_files/oc2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc2.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc3.o: mcc_generated_files/oc3.c  .generated_files/flags/app_boot/3fe38375b5aef01951e638d194f311d7f693bdd1 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc3.c  -o ${OBJECTDIR}/mcc_generated_files/oc3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc3.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_device_custom_hid.o: app_device_custom_hid.c  .generated_files/flags/app_boot/90ede55f0c29a0717ea936926770d26ab54538d6 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o.d 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_device_custom_hid.c  -o ${OBJECTDIR}/app_device_custom_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_custom_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/app_boot/bc13978783f11f6b1a9da6fc77601cebf674db83 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o: mcc_generated_files/usb/usb_descriptors.c  .generated_files/flags/app_boot/761a85872261b0a9982db69c102698ff167f0042 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_descriptors.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_descriptors.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device.o: mcc_generated_files/usb/usb_device.c  .generated_files/flags/app_boot/bbc985b5392905646b6484a47eb85fa5370dadd6 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o: mcc_generated_files/usb/usb_device_hid.c  .generated_files/flags/app_boot/3d1f8a6d91984a823bfceb3b0dde3a44d3be3900 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_device_hid.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_device_hid.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_events.o: mcc_generated_files/usb/usb_events.c  .generated_files/flags/app_boot/79bbe8a22e4ed129dd5b0608d4c8c5968100c6bc .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_events.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_events.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_events.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o: mcc_generated_files/usb/usb_hal_16bit.c  .generated_files/flags/app_boot/4a2f070bf1c3f4ea69bf06d70f27f1ebc4b07966 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/usb" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/usb/usb_hal_16bit.c  -o ${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/usb/usb_hal_16bit.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/spi1.o: mcc_generated_files/spi1.c  .generated_files/flags/app_boot/86558cf2710c442732712c0f0ba36ae95686407c .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/spi1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/spi1.c  -o ${OBJECTDIR}/mcc_generated_files/spi1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/spi1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/clock.o: mcc_generated_files/clock.c  .generated_files/flags/app_boot/bb42123dceb5c4b9cbabb518c43470ec5104eee7 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/clock.c  -o ${OBJECTDIR}/mcc_generated_files/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/clock.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/adc1.o: mcc_generated_files/adc1.c  .generated_files/flags/app_boot/3c0db632ae0cb4cf660e9536d1b28f2a272f1a4a .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ext_int.o: mcc_generated_files/ext_int.c  .generated_files/flags/app_boot/835dcfe6c157f5e5974272b80674413d9bd01d63 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ext_int.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ext_int.c  -o ${OBJECTDIR}/mcc_generated_files/ext_int.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ext_int.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/interrupt_manager.o: mcc_generated_files/interrupt_manager.c  .generated_files/flags/app_boot/4a14ec04b645c7294e646a988c20c85006150b4c .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/mcc_generated_files/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/interrupt_manager.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/mcc.o: mcc_generated_files/mcc.c  .generated_files/flags/app_boot/446b8e03f58078d03702c47375c2205bd53a0758 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/mcc.c  -o ${OBJECTDIR}/mcc_generated_files/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/mcc.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  .generated_files/flags/app_boot/c87ced8406dec395727d7068de073037e235129 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/traps.o: mcc_generated_files/traps.c  .generated_files/flags/app_boot/1267ce47319918070a1e4bdb3e24c378b8be77c0 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/traps.c  -o ${OBJECTDIR}/mcc_generated_files/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/traps.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/tmr5.o: mcc_generated_files/tmr5.c  .generated_files/flags/app_boot/34199c4856ae754ed15bcf56e2cea395019b78f1 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/tmr5.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/tmr5.c  -o ${OBJECTDIR}/mcc_generated_files/tmr5.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/tmr5.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/thd_i2c1.o: mcc_generated_files/thd_i2c1.c  .generated_files/flags/app_boot/3cd74608c6c8960793f73ff59b1fc4e70ed7639d .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/thd_i2c2.o: mcc_generated_files/thd_i2c2.c  .generated_files/flags/app_boot/7c6587660213330fd315e775096515d9846f9c92 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/thd_i2c2.c  -o ${OBJECTDIR}/mcc_generated_files/thd_i2c2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/thd_i2c2.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o: mcc_generated_files/ADXL350_TMP102.c  .generated_files/flags/app_boot/37c3d1f6f9b0252963ad117b8edaf143ed94c421 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ADXL350_TMP102.c  -o ${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ADXL350_TMP102.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ltc1661.o: mcc_generated_files/ltc1661.c  .generated_files/flags/app_boot/81f48b3a3da8944dd3a19d8fe3c9a3b4655cda11 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ltc1661.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ltc1661.c  -o ${OBJECTDIR}/mcc_generated_files/ltc1661.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ltc1661.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/power_reset.o: mcc_generated_files/power_reset.c  .generated_files/flags/app_boot/40a2542c91732a2634120d50de2cf29c1190a5f2 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/mcc_generated_files/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/power_reset.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system.o: mcc_generated_files/system.c  .generated_files/flags/app_boot/c4028a25f2b20f92a777cf342637b74e9afd83e .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system.c  -o ${OBJECTDIR}/mcc_generated_files/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/TC358870.o: mcc_generated_files/TC358870.c  .generated_files/flags/app_boot/41757a89f711237f8a5322cc6c6747bb52b9a91a .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/TC358870.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/TC358870.c  -o ${OBJECTDIR}/mcc_generated_files/TC358870.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/TC358870.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o: mcc_generated_files/santek_qhd_lcd.c  .generated_files/flags/app_boot/db3eb5b5df8318819fecdfe869efd8080d8a5270 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/santek_qhd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/santek_qhd_lcd.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o: mcc_generated_files/ortustech_hd_lcd.c  .generated_files/flags/app_boot/f8e58a5372d1a37422f05654821fb6718131df2f .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/ortustech_hd_lcd.c  -o ${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/ortustech_hd_lcd.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc1.o: mcc_generated_files/oc1.c  .generated_files/flags/app_boot/3897c531ec786312de4a86d5db75236c292daf55 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc1.c  -o ${OBJECTDIR}/mcc_generated_files/oc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc1.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc2.o: mcc_generated_files/oc2.c  .generated_files/flags/app_boot/799d6939b6123514f7a0bdd2f800ffe5c27ded80 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc2.c  -o ${OBJECTDIR}/mcc_generated_files/oc2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc2.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/oc3.o: mcc_generated_files/oc3.c  .generated_files/flags/app_boot/7ba34835b7b5c1cb5d428960d3de6dbd57165efe .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/oc3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/oc3.c  -o ${OBJECTDIR}/mcc_generated_files/oc3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/oc3.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_device_custom_hid.o: app_device_custom_hid.c  .generated_files/flags/app_boot/c4a674bbefc2efd8234f01cfbf9a5fa44e30b9a9 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o.d 
	@${RM} ${OBJECTDIR}/app_device_custom_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_device_custom_hid.c  -o ${OBJECTDIR}/app_device_custom_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_custom_hid.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/app_boot/844666f4f9044e298a4ce44b8d50777043134a64 .generated_files/flags/app_boot/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../bootloader/exp16_pic24fj64gb004_pim.x/hid_boot_p24FJ64GB004.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_app_boot=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/mipiboard_HID-C.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


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
