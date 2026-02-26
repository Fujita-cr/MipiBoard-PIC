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
${OBJECTDIR}/_ext/758183835/clock.o: ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  .generated_files/flags/PIC24FJ64GB004_PIM/38f451b54dde5f8cfe71830e250e0d01524269f4 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/758183835/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/clock.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/interrupt_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/de670520c638367914d547a37e705d12eb50076f .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/mcc.o: ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  .generated_files/flags/PIC24FJ64GB004_PIM/e480b0f87d1f0668496ba1f45dd089444faf4c30 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/758183835/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/mcc.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/pin_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/d2133c1d2e3d9cf7118faf58026edd2d188191f1 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/758183835/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/pin_manager.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/power_reset.o: ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  .generated_files/flags/PIC24FJ64GB004_PIM/682c8a8bbd403f671a46c60e21b5ed707d85195e .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/_ext/758183835/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/power_reset.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/thd_i2c1.o: ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  .generated_files/flags/PIC24FJ64GB004_PIM/665f6c4a7018e2b6a6f4abc389330cf0d5649021 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  .generated_files/flags/PIC24FJ64GB004_PIM/bc27934f53125cfd0971fd462782a11f9525cced .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device.o: framework/usb/src/usb_device.c  .generated_files/flags/PIC24FJ64GB004_PIM/4ad47845ca00b304dba9a8b149d0118710e8967b .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device.c  -o ${OBJECTDIR}/framework/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device_hid.o: framework/usb/src/usb_device_hid.c  .generated_files/flags/PIC24FJ64GB004_PIM/8484d7a4eca9ae44ae3ebf79ff25c0d7dec14965 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device_hid.c  -o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_hid_boot_loader.o: app_hid_boot_loader.c  .generated_files/flags/PIC24FJ64GB004_PIM/a1467afb2da19929a0bc5497a3c8ba61df0f631e .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o.d 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_hid_boot_loader.c  -o ${OBJECTDIR}/app_hid_boot_loader.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_hid_boot_loader.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC24FJ64GB004_PIM/439329a6496822c0779b5f78ee06616929be55ce .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC24FJ64GB004_PIM/52877ef67c20e6c7213eca9826dcd92d6b640991 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/758183835/clock.o: ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  .generated_files/flags/PIC24FJ64GB004_PIM/46ead1ca5c367c539ca0a0b1e8cf299327635267 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/758183835/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/clock.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/interrupt_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/7a01caa31e38a644dae1ea00d02d7f569947cc98 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/758183835/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/interrupt_manager.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/mcc.o: ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  .generated_files/flags/PIC24FJ64GB004_PIM/e3adc14d0f9ac5e72499ae7afe9f8dd1327987ee .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/758183835/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/mcc.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/pin_manager.o: ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  .generated_files/flags/PIC24FJ64GB004_PIM/d35888b8dc4fdf03c1f8a9a0930680d28dc90516 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/758183835/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/pin_manager.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/power_reset.o: ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  .generated_files/flags/PIC24FJ64GB004_PIM/1f02066cba6c2d466fc3537db38ac3c53de2ffb .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/power_reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/power_reset.c  -o ${OBJECTDIR}/_ext/758183835/power_reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/power_reset.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/758183835/thd_i2c1.o: ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  .generated_files/flags/PIC24FJ64GB004_PIM/ed3cd069d3d27d25c2ab24226f71b31620011651 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/758183835" 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d 
	@${RM} ${OBJECTDIR}/_ext/758183835/thd_i2c1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../mipiboard_HID-C.X/mcc_generated_files/thd_i2c1.c  -o ${OBJECTDIR}/_ext/758183835/thd_i2c1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/758183835/thd_i2c1.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  .generated_files/flags/PIC24FJ64GB004_PIM/ed38972af12a0f664e5d4d8279be582b23e0f63f .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device.o: framework/usb/src/usb_device.c  .generated_files/flags/PIC24FJ64GB004_PIM/3386663654f57118d3d9b7ea5056ea95f05c48d8 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device.c  -o ${OBJECTDIR}/framework/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/framework/usb/src/usb_device_hid.o: framework/usb/src/usb_device_hid.c  .generated_files/flags/PIC24FJ64GB004_PIM/ab3178d7c588aba92458f4c2f148f0f6b887be6a .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/framework/usb/src" 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d 
	@${RM} ${OBJECTDIR}/framework/usb/src/usb_device_hid.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  framework/usb/src/usb_device_hid.c  -o ${OBJECTDIR}/framework/usb/src/usb_device_hid.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/framework/usb/src/usb_device_hid.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/app_hid_boot_loader.o: app_hid_boot_loader.c  .generated_files/flags/PIC24FJ64GB004_PIM/4566d620f812142ada1457685dd8e853ca7a8823 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o.d 
	@${RM} ${OBJECTDIR}/app_hid_boot_loader.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  app_hid_boot_loader.c  -o ${OBJECTDIR}/app_hid_boot_loader.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_hid_boot_loader.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/PIC24FJ64GB004_PIM/9d154cd8f931698da0e12dc3ae755d29a1f2cf4e .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"        -g -omf=elf -DXPRJ_PIC24FJ64GB004_PIM=$(CND_CONF)    $(COMPARISON_BUILD)  -fno-short-double -Os -falign-arrays -I"." -I"./framework/usb/inc" -I"../../mipiboard_HID-C.X" -I"../../mipiboard_HID-C.X/mcc_generated_files" -DPIC24FJ64GB004_PIM -msmart-io=1 -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/PIC24FJ64GB004_PIM/2e39c6872a5857263cc5045e41dc7d215fa930f5 .generated_files/flags/PIC24FJ64GB004_PIM/da39a3ee5e6b4b0d3255bfef95601890afd80709
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
