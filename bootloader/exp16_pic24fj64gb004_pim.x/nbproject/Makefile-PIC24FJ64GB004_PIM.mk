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
ifeq "$(wildcard nbproject/Makefile-local-PIC24FJ64GB004_PIM.mk)" "nbproject/Makefile-local-PIC24FJ64GB004_PIM.mk"
include nbproject/Makefile-local-PIC24FJ64GB004_PIM.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PIC24FJ64GB004_PIM
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../../mipiboard_HID-C.X/mcc_generated_files/clock.c ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c usb_descriptors.c framework/usb/src/usb_device.c framework/usb/src/usb_device_hid.c app_hid_boot_loader.c system.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/758183835/clock.o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o ${OBJECTDIR}/_ext/758183835/mcc.o ${OBJECTDIR}/_ext/758183835/pin_manager.o ${OBJECTDIR}/_ext/758183835/power_reset.o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/framework/usb/src/usb_device.o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o ${OBJECTDIR}/app_hid_boot_loader.o ${OBJECTDIR}/system.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/758183835/clock.o.d ${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d ${OBJECTDIR}/_ext/758183835/mcc.o.d ${OBJECTDIR}/_ext/758183835/pin_manager.o.d ${OBJECTDIR}/_ext/758183835/power_reset.o.d ${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d ${OBJECTDIR}/usb_descriptors.o.d ${OBJECTDIR}/framework/usb/src/usb_device.o.d ${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d ${OBJECTDIR}/app_hid_boot_loader.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/758183835/clock.o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o ${OBJECTDIR}/_ext/758183835/mcc.o ${OBJECTDIR}/_ext/758183835/pin_manager.o ${OBJECTDIR}/_ext/758183835/power_reset.o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/framework/usb/src/usb_device.o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o ${OBJECTDIR}/app_hid_boot_loader.o ${OBJECTDIR}/system.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=../../mipiboard_HID-C.X/mcc_generated_files/clock.c ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c usb_descriptors.c framework/usb/src/usb_device.c framework/usb/src/usb_device_hid.c app_hid_boot_loader.c system.c main.c



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

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-PIC24FJ64GB004_PIM.mk ${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GB004
MP_LINKER_FILE_OPTION=,--script="hid_boot_p24FJ64GB004.gld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/758183835/clock.o: ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  .generated_files/flags/PIC24FJ64GB004_PIM/b45b3d9b9430984fe1054c1e794bfb09c2f52f19 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/758183835/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/clock.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/interrupt_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/454d5dc5c1b6f90fd4b1d66c714b0eb642756b94 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/mcc.o: ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  .generated_files/flags/PIC24FJ64GB004_PIM/a34a2447b30eb54588a467117633b122c16661e9 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/758183835/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/mcc.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/pin_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/29d59784ec5dabc7f348e5f3dbb6e3c26838f2da .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/758183835/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/pin_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/power_reset.o: ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  .generated_files/flags/PIC24FJ64GB004_PIM/8279c3e1161e84ddd5ff0d3d0a4e201ae31f6dcb .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/_ext/758183835/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/power_reset.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/thd_i2c1.o: ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  .generated_files/flags/PIC24FJ64GB004_PIM/a4699b7cd99bb80250691eab1676a32e5fe56f0c .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  .generated_files/flags/PIC24FJ64GB004_PIM/cc1de3ed0cfdfc73e507b5b7a57fdb9930b6c1ed .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device.o: framework/usb/src/usb_device.c  .generated_files/flags/PIC24FJ64GB004_PIM/dfd1300ca76966bb72e8e6e8e1dec2cebc75dcf0 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device.c  -o ${OBJECTDIR}/framework/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device_hid.o: framework/usb/src/usb_device_hid.c  .generated_files/flags/PIC24FJ64GB004_PIM/90c9256ab6e070b2b0f6fdc7a291a59ae268aa3b .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device_hid.c  -o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_hid_boot_loader.o: app_hid_boot_loader.c  .generated_files/flags/PIC24FJ64GB004_PIM/8d4258a338a73c69bd73bd25b3e2cc9f6ab496a6 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o.d 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_hid_boot_loader.c  -o ${OBJECTDIR}/app_hid_boot_loader.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_hid_boot_loader.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC24FJ64GB004_PIM/f29fb5daad4f742ceaef5267d2a1ae30011b6303 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC24FJ64GB004_PIM/3e99979874b0549b90f250d3ac827b9b9d7e8074 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/758183835/clock.o: ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  .generated_files/flags/PIC24FJ64GB004_PIM/a16bb08397b6719e5344f2b623665ae48e1aaef6 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/758183835/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/clock.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/interrupt_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/b44469491065b449c4380c5dbbe12819231c004c .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/mcc.o: ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  .generated_files/flags/PIC24FJ64GB004_PIM/4006d9cc1c4947423376bc519fe17b76e6599f00 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/758183835/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/mcc.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/pin_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/749c8199c349f90d1a4300a3398ce8d2dbd43c2a .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/758183835/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/pin_manager.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/power_reset.o: ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  .generated_files/flags/PIC24FJ64GB004_PIM/eb5343bef59b37d30b0376e8be8af10787d3f263 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/_ext/758183835/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/power_reset.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/thd_i2c1.o: ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  .generated_files/flags/PIC24FJ64GB004_PIM/1af73a0839c4f176bb6135baf7d5099f892d8e4f .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  .generated_files/flags/PIC24FJ64GB004_PIM/5a19a3af0b973487d453a93881e67ab07832742c .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device.o: framework/usb/src/usb_device.c  .generated_files/flags/PIC24FJ64GB004_PIM/8d65343f40d87b06b96d1d4cb6ff5bbdda3c5c16 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device.c  -o ${OBJECTDIR}/framework/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device_hid.o: framework/usb/src/usb_device_hid.c  .generated_files/flags/PIC24FJ64GB004_PIM/e5ddcfbb13053f61830156154d14adbaf4ff6b45 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device_hid.c  -o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_hid_boot_loader.o: app_hid_boot_loader.c  .generated_files/flags/PIC24FJ64GB004_PIM/5e1462f272f8dcb803bb31ea350c1eff4265532a .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o.d 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_hid_boot_loader.c  -o ${OBJECTDIR}/app_hid_boot_loader.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_hid_boot_loader.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC24FJ64GB004_PIM/8a42369a6c05a128ee6512f0208218d81b96b150 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC24FJ64GB004_PIM/9c62c6c081e9f41d158afbc826313980c6e82f53 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    hid_boot_p24FJ64GB004.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,-D__BOOTLOADER,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   hid_boot_p24FJ64GB004.gld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,-D__BOOTLOADER,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/exp16_pic24fj64gb004_pim.x.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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
