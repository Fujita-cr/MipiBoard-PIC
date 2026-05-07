/*
 * File:   santek_qhd_lcd.c
 * Author: thaya
 *
 * Created on 2020/01/04, 22:28
 */


#include "xc.h"
#include "TC358870.h"
#include "thd_i2c2.h"
#include "pin_manager.h"
#include "power_reset.h"
#include "../extern_val.h"

void santek_ColorBar(){
    // Software Reset
i2c2_uh2cd_write16(0x0004,0x0004); // ConfCtl0
i2c2_uh2cd_write16(0x0002,0x3F00); // SysCtl
i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
i2c2_uh2cd_write16(0x7000,0x0009); // CB_CTL
// DSI-TX1 Transition Timing
i2c2_uh2cd_write32(0x0308,0x00000001); // DSI_TX_CLKEN
i2c2_uh2cd_write32(0x030C,0x00000001); // DSI_TX_CLKSEL
i2c2_uh2cd_write32(0x04A0,0x00000001); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x04AC,0x00001022); // MIPI_PLL_CNF
Waitx1ms(1);
i2c2_uh2cd_write32(0x04A0,0x00000003); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x0318,0x00000014); // LANE_ENABLE
i2c2_uh2cd_write32(0x0320,0x000012BD); // LINE_INIT_COUNT
i2c2_uh2cd_write32(0x0324,0x00000000); // HSTX_TO_COUNT
i2c2_uh2cd_write32(0x0328,0x00000101); // FUNC_ENABLE
i2c2_uh2cd_write32(0x0330,0x00010000); // DSI_TATO_COUNT
i2c2_uh2cd_write32(0x0334,0x00005000); // DSI_PRESP_BTA_COUNT
i2c2_uh2cd_write32(0x0338,0x00010000); // DSI_PRESP_LPR_COUNT
i2c2_uh2cd_write32(0x033C,0x00010000); // DSI_PRESP_LPW_COUNT
i2c2_uh2cd_write32(0x0340,0x00010000); // DSI_PRESP_HSR_COUNT
i2c2_uh2cd_write32(0x0344,0x00010000); // DSI_PRESP_HSW_COUNT
i2c2_uh2cd_write32(0x0348,0x00001000); // DSI_PR_TO_COUNT
i2c2_uh2cd_write32(0x034C,0x00010000); // DSI_LRX-H_TO_COUNT
i2c2_uh2cd_write32(0x0350,0x00000141); // FUNC_MODE
i2c2_uh2cd_write32(0x0354,0x00000001); // DSI_RX_VC_ENABLE
i2c2_uh2cd_write32(0x0358,0x000000C8); // IND_TO_COUNT
i2c2_uh2cd_write32(0x0368,0x0000002A); // DSI_HSYNC_STOP_COUNT
i2c2_uh2cd_write32(0x0370,0x000002FE); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x037C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x038C,0x00000020); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0390,0x0000000E); // DSI_HBPR
i2c2_uh2cd_write32(0x03A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x03C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0414,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x041C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0424,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0454,0x00000005); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0458,0x001F0004); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x045C,0x000B0005); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0460,0x000A0005); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0464,0x00004650); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0468,0x0000000C); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x046C,0x000B0007); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0470,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0474,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0478,0x00050004); // BTA_COUNT
i2c2_uh2cd_write32(0x047C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x031C,0x00000001); // DSITX_START
// DSI-TX0 Transition Timing
i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x02AC,0x00001022); // MIPI_PLL_CNF
Waitx1ms(1);
i2c2_uh2cd_write32(0x02A0,0x00000003); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x0118,0x00000014); // LANE_ENABLE
i2c2_uh2cd_write32(0x0120,0x000012BD); // LINE_INIT_COUNT
i2c2_uh2cd_write32(0x0124,0x00000000); // HSTX_TO_COUNT
i2c2_uh2cd_write32(0x0128,0x00000101); // FUNC_ENABLE
i2c2_uh2cd_write32(0x0130,0x00010000); // DSI_TATO_COUNT
i2c2_uh2cd_write32(0x0134,0x00005000); // DSI_PRESP_BTA_COUNT
i2c2_uh2cd_write32(0x0138,0x00010000); // DSI_PRESP_LPR_COUNT
i2c2_uh2cd_write32(0x013C,0x00010000); // DSI_PRESP_LPW_COUNT
i2c2_uh2cd_write32(0x0140,0x00010000); // DSI_PRESP_HSR_COUNT
i2c2_uh2cd_write32(0x0144,0x00010000); // DSI_PRESP_HSW_COUNT
i2c2_uh2cd_write32(0x0148,0x00001000); // DSI_PR_TO_COUNT
i2c2_uh2cd_write32(0x014C,0x00010000); // DSI_LRX-H_TO_COUNT
i2c2_uh2cd_write32(0x0150,0x00000141); // FUNC_MODE
i2c2_uh2cd_write32(0x0154,0x00000001); // DSI_RX_VC_ENABLE
i2c2_uh2cd_write32(0x0158,0x000000C8); // IND_TO_COUNT
i2c2_uh2cd_write32(0x0168,0x0000002A); // DSI_HSYNC_STOP_COUNT
i2c2_uh2cd_write32(0x0170,0x000002FE); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x018C,0x00000020); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0190,0x0000000E); // DSI_HBPR
i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0254,0x00000005); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0258,0x001F0004); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x025C,0x000B0005); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0260,0x000A0005); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0264,0x00004650); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0268,0x0000000C); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x026C,0x000B0007); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0278,0x00050004); // BTA_COUNT
i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
// Command Transmission Before Video Start
i2c2_uh2cd_write16(0x0500,0x0004); // CMD_SEL
i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG
    // LCD Initialization
    // POWER ON +/-AVDD
    // Wait 5ms
    /*
     LCDリセットあり上書き注意
     */
    Waitx1ms(5);
    Santek_LCD_Reset();
    Waitx1ms(10);
    //パターン1
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x01D6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x18B3); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    //i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q    //輝度値
    i2c2_uh2cd_write16(0x0504,0x0051); // DCSCMD_Q  //輝度値
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1C53); // DCSCMD_Q 元は0C53
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0035); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x03B0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q

    Waitx1ms(5);
// Host Data Transfer Start
// Split Control
i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
i2c2_uh2cd_write16(0x500C,0x8000); // STX0_FPX
i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
// Color Bar Setting
i2c2_uh2cd_write16(0x7008,0x0020); // CB_HSW
i2c2_uh2cd_write16(0x700A,0x0002); // CB_VSW
i2c2_uh2cd_write16(0x700C,0x064C); // CB_Htotal
i2c2_uh2cd_write16(0x700E,0x0A08); // CB_Vtotal
i2c2_uh2cd_write16(0x7010,0x05A0); // CB_Hact
i2c2_uh2cd_write16(0x7012,0x0A00); // CB_Vact
i2c2_uh2cd_write16(0x7014,0x0048); // CB_Hstart
i2c2_uh2cd_write16(0x7016,0x0006); // CB_Vstart
i2c2_uh2cd_write16(0x7000,0x000F); // CB_CTL
// Start Video TX
i2c2_uh2cd_write16(0x0004,0x0C37); // ConfCtl0
// Command Transmission After Video Start. HS command TX
i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG

}

void santek_RS1(void)
{
// Initialization for Stand-by (RS1)
// Software Reset
i2c2_uh2cd_write16(0x0004,0x0004); // ConfCtl0
i2c2_uh2cd_write16(0x0002,0x3F00); // SysCtl
i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
// HDMI Interrupt Mask, Clear
i2c2_uh2cd_write16(0x0016,0x0F3F); // IntMask
i2c2_uh2cd_write8(0x8502,0xFF); // SYS_INT
i2c2_uh2cd_write8(0x850B,0xFF); // MISC_INT
i2c2_uh2cd_write16(0x0014,0x0F3F); // IntStatus
i2c2_uh2cd_write8(0x8512,0xFE); // SYS_INTM
i2c2_uh2cd_write8(0x8514,0xFF); // PACKET_INTM
i2c2_uh2cd_write8(0x8515,0xFF); // AUDIO_IMNTM
i2c2_uh2cd_write8(0x8516,0xFF); // ABUF_INTM
// HDMI PHY
i2c2_uh2cd_write8(0x8410,0x03); // PHY CTL
i2c2_uh2cd_write8(0x8413,0x3F); // PHY_ENB
i2c2_uh2cd_write8(0x8420,0x07); // EQ_BYPS
i2c2_uh2cd_write8(0x84F0,0x31); // APLL_CTL
i2c2_uh2cd_write8(0x84F4,0x01); // DDCIO_CTL
// HDMI Clock
i2c2_uh2cd_write16(0x8540,0x12C0); // SYS_FREQ0_1
i2c2_uh2cd_write8(0x8630,0x00); // LOCKDET_FREQ0
i2c2_uh2cd_write16(0x8631,0x0753); // LOCKDET_REF1_2
i2c2_uh2cd_write8(0x8670,0x02); // NCO_F0_MOD
i2c2_uh2cd_write16(0x8A0C,0x12C0); // CSC_SCLK0_1
// EDID
i2c2_uh2cd_write8(0x85E0,0x01); // EDID_MODE
i2c2_uh2cd_write16(0x85E3,0x0100); // EDID_LEN1_2
// EDID Data
i2c2_uh2cd_write8(0x8C00,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C01,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C02,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C03,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C04,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C05,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C06,0xFF); // EDID_RAM
i2c2_uh2cd_write8(0x8C07,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C08,0x4D); // EDID_RAM
i2c2_uh2cd_write8(0x8C09,0x12); // EDID_RAM
i2c2_uh2cd_write8(0x8C0A,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8C0B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0C,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8C0D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0F,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C10,0x1C); // EDID_RAM
i2c2_uh2cd_write8(0x8C11,0x1E); // EDID_RAM
i2c2_uh2cd_write8(0x8C12,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C13,0x03); // EDID_RAM
i2c2_uh2cd_write8(0x8C14,0x80); // EDID_RAM
i2c2_uh2cd_write8(0x8C15,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8C16,0x06); // EDID_RAM
i2c2_uh2cd_write8(0x8C17,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8C18,0x0A); // EDID_RAM
i2c2_uh2cd_write8(0x8C19,0x0D); // EDID_RAM
i2c2_uh2cd_write8(0x8C1A,0xC9); // EDID_RAM
i2c2_uh2cd_write8(0x8C1B,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C1C,0x57); // EDID_RAM
i2c2_uh2cd_write8(0x8C1D,0x47); // EDID_RAM
i2c2_uh2cd_write8(0x8C1E,0x98); // EDID_RAM
i2c2_uh2cd_write8(0x8C1F,0x27); // EDID_RAM
i2c2_uh2cd_write8(0x8C20,0x12); // EDID_RAM
i2c2_uh2cd_write8(0x8C21,0x48); // EDID_RAM
i2c2_uh2cd_write8(0x8C22,0x4C); // EDID_RAM
i2c2_uh2cd_write8(0x8C23,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C24,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C25,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C26,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C27,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C28,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C29,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2A,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2B,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2C,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2D,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2E,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C2F,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C30,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C31,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C32,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C33,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C34,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C35,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C36,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C37,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8C38,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C39,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8C3A,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C3B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C3C,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8C3D,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C3E,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8C3F,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C40,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8C41,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C42,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8C43,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8C44,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C45,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C46,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C47,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8C48,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C49,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8C4A,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C4B,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8C4C,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C4D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C4E,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8C4F,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C50,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8C51,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C52,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8C53,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C54,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8C55,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8C56,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C57,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C58,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C59,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8C5A,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5C,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5D,0xFC); // EDID_RAM
i2c2_uh2cd_write8(0x8C5E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5F,0x53); // EDID_RAM
i2c2_uh2cd_write8(0x8C60,0x54); // EDID_RAM
i2c2_uh2cd_write8(0x8C61,0x30); // EDID_RAM
i2c2_uh2cd_write8(0x8C62,0x35); // EDID_RAM
i2c2_uh2cd_write8(0x8C63,0x35); // EDID_RAM
i2c2_uh2cd_write8(0x8C64,0x30); // EDID_RAM
i2c2_uh2cd_write8(0x8C65,0x51); // EDID_RAM
i2c2_uh2cd_write8(0x8C66,0x48); // EDID_RAM
i2c2_uh2cd_write8(0x8C67,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8C68,0x53); // EDID_RAM
i2c2_uh2cd_write8(0x8C69,0x41); // EDID_RAM
i2c2_uh2cd_write8(0x8C6A,0x4E); // EDID_RAM
i2c2_uh2cd_write8(0x8C6B,0x54); // EDID_RAM
i2c2_uh2cd_write8(0x8C6C,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6F,0xFD); // EDID_RAM
i2c2_uh2cd_write8(0x8C70,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C71,0x36); // EDID_RAM
i2c2_uh2cd_write8(0x8C72,0x42); // EDID_RAM
i2c2_uh2cd_write8(0x8C73,0x45); // EDID_RAM
i2c2_uh2cd_write8(0x8C74,0x4B); // EDID_RAM
i2c2_uh2cd_write8(0x8C75,0x19); // EDID_RAM
i2c2_uh2cd_write8(0x8C76,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C77,0x0A); // EDID_RAM
i2c2_uh2cd_write8(0x8C78,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C79,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7A,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7B,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7C,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7D,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7E,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C7F,0x79); // EDID_RAM
i2c2_uh2cd_write8(0x8C80,0x02); // EDID_RAM
i2c2_uh2cd_write8(0x8C81,0x03); // EDID_RAM
i2c2_uh2cd_write8(0x8C82,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8C83,0xC1); // EDID_RAM
i2c2_uh2cd_write8(0x8C84,0x47); // EDID_RAM
i2c2_uh2cd_write8(0x8C85,0xC6); // EDID_RAM
i2c2_uh2cd_write8(0x8C86,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C87,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C88,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C89,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C8A,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C8B,0x46); // EDID_RAM
i2c2_uh2cd_write8(0x8C8C,0x23); // EDID_RAM
i2c2_uh2cd_write8(0x8C8D,0x09); // EDID_RAM
i2c2_uh2cd_write8(0x8C8E,0x07); // EDID_RAM
i2c2_uh2cd_write8(0x8C8F,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C90,0x83); // EDID_RAM
i2c2_uh2cd_write8(0x8C91,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C92,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C93,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C94,0x65); // EDID_RAM
i2c2_uh2cd_write8(0x8C95,0x03); // EDID_RAM
i2c2_uh2cd_write8(0x8C96,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8C97,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C98,0x10); // EDID_RAM
i2c2_uh2cd_write8(0x8C99,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C9A,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C9B,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8C9C,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8C9D,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8C9E,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C9F,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA0,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8CA1,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CA2,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8CA3,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CA4,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8CA5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA6,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8CA7,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8CA8,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CAA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CAB,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CAC,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CAD,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8CAE,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CAF,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8CB0,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CB1,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CB2,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8CB3,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CB4,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8CB5,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CB6,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8CB7,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CB8,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8CB9,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8CBA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBD,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CBE,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CBF,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8CC0,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CC1,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8CC2,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CC3,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CC4,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8CC5,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CC6,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8CC7,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CC8,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8CC9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCA,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8CCB,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8CCC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCD,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCF,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CD0,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CD1,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8CD2,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CD3,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8CD4,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CD5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CD6,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8CD7,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CD8,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8CD9,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CDA,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8CDB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CDC,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8CDD,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8CDE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CDF,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE0,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE1,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CE2,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CE3,0x5F); // EDID_RAM
i2c2_uh2cd_write8(0x8CE4,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CE5,0xAC); // EDID_RAM
i2c2_uh2cd_write8(0x8CE6,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CE7,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE8,0x08); // EDID_RAM
i2c2_uh2cd_write8(0x8CE9,0xA0); // EDID_RAM
i2c2_uh2cd_write8(0x8CEA,0x64); // EDID_RAM
i2c2_uh2cd_write8(0x8CEB,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CEC,0x22); // EDID_RAM
i2c2_uh2cd_write8(0x8CED,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEE,0x78); // EDID_RAM
i2c2_uh2cd_write8(0x8CEF,0x44); // EDID_RAM
i2c2_uh2cd_write8(0x8CF0,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF1,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF2,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF3,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CF4,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF6,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF7,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF8,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFD,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CFF,0x12); // EDID_RAM
// HDCP Setting
// HDMI SYSTEM
i2c2_uh2cd_write8(0x8543,0x02); // DDC_CTL
i2c2_uh2cd_write8(0x8544,0x11); // HPD_CTL
// HDMI Audio Setting
i2c2_uh2cd_write8(0x8600,0x00); // AUD_Auto_Mute
i2c2_uh2cd_write8(0x8602,0xF3); // Auto_CMD0
i2c2_uh2cd_write8(0x8603,0x02); // Auto_CMD1
i2c2_uh2cd_write8(0x8604,0x0C); // Auto_CMD2
i2c2_uh2cd_write8(0x8606,0x05); // BUFINIT_START
i2c2_uh2cd_write8(0x8607,0x00); // FS_MUTE
i2c2_uh2cd_write8(0x8652,0x02); // SDO_MODE1
i2c2_uh2cd_write32(0x8671,0x020C49BA); // NCO_48F0A_D
i2c2_uh2cd_write32(0x8675,0x01E1B089); // NCO_44F0A_D
i2c2_uh2cd_write8(0x8680,0x00); // AUD_MODE
}

uint16_t santek_Check_HDMI_Cable(void)
{
uint8_t retVal;
// Check HDMI cable status
retVal = i2c2_uh2cd_read8(0x8520); // 
retVal = i2c2_uh2cd_read8(0x8520); // 
retVal = i2c2_uh2cd_read8(0x8520); // 
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
// Enter Sleep
i2c2_uh2cd_write16(0x0002,0x0001); // SysCtl

retVal = retVal & 0x01;
//Check DDC_5V
return retVal;
}

uint16_t santek_Check_RS_Int(void)
{
    uint16_t d_IntStatus,retVal;
    uint8_t  d_IntSYSSTATUS,d_MISC_INT;
    uint8_t  HPI_chg,I_DDC,S_DDC5V,SYNC_chg;
    
    // Interrupt Service Routine(RS_Int)
    // Exit from Sleep
    i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
    Waitx1us(10);
    // Check Interrupt
    //システム割り込みステータスを取得
    d_IntStatus = i2c2_uh2cd_read16(0x0014); // IntStatus
    
    //HPIステータスの変化を確認（ホットプラグ検出）
    d_IntSYSSTATUS = i2c2_uh2cd_read16(0x001A); // IntSYSSTATUS
    HPI_chg =(uint8_t)(d_IntSYSSTATUS & 0x0001); // Check HPDI Change DDC_5V ON or OFF
            
    //DDC 5Vの変化を確認
    I_DDC = i2c2_uh2cd_read8(0x8502); // SYS_INT
    I_DDC = I_DDC & 0x01; // DDC Power 0V<-->5V Change
    
    //他の割り込み
    d_MISC_INT = i2c2_uh2cd_read8(0x850B); // MISC_INT
    SYNC_chg = (d_MISC_INT & 0x02) >> 1;   //SYNCの変化
    
    //システムステータス（割り込みが入ったときでなく、現在の値なので注意！）
    S_DDC5V = i2c2_uh2cd_read8(0x8520); // SYS_STATUS
    S_DDC5V = S_DDC5V & 0x81; //bit0 = 1 DDC5V input = 0:DDC5V no input
                              //bit7 = 1 S_SYNC stable = 0: unstable
    
    //割り込みレジスタの再設定
    i2c2_uh2cd_write16(0x0016,0x0F3F); // IntMask
    i2c2_uh2cd_write8(0x8502,0xFF); // SYS_INT
    i2c2_uh2cd_write8(0x850B,0xFF); // MISC_INT
    i2c2_uh2cd_write16(0x0014,0x0F3F); // IntStatus 
    
    //bit7:S_SYNC 1=Stable 0=unstable   ※現在のステータス
    //bit3:SYNC_chg SYNC status change
    //bit2:HPI_chg DDC5V status change
    //bit1:I_DDC DDC Power 0V<-->5V Change
    //bit0:S_DDC Statsu of 5V ON or OFF   ※現在のステータス
    retVal = (SYNC_chg << 3)|(HPI_chg << 2)|(I_DDC << 1)|S_DDC5V;
    return retVal;
}
void santek_RS2_Ready(void)
{
// Initialization for Ready (RS2)
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
// Set HPDO to "H"
i2c2_uh2cd_write8(0x854A,0x01); // INIT_END
}
void santek_RS3(void)
{
   // MIPI Output Enable(RS3)
    // Check HDMI resolution/format
    Waitx1ms(5000);
    // MIPI Output Setting
    // Stop Video and Audio
    i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
    // Soft Reset CSI-TX and Splitter Block
    i2c2_uh2cd_write16(0x0002,0x1200); // SysCtl
    i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
    // Video Color Format Setting
    i2c2_uh2cd_write8(0x8A02,0x42); // VOUT_SYNC0
    // DSI-TX0 Transition Timing
    i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
    i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
    i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x02AC,0x00001022); // MIPI_PLL_CNF
    Waitx1ms(1);
    i2c2_uh2cd_write32(0x02A0,0x00000003); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x0118,0x00000014); // LANE_ENABLE
    i2c2_uh2cd_write32(0x0120,0x000012BD); // LINE_INIT_COUNT
    i2c2_uh2cd_write32(0x0124,0x00000000); // HSTX_TO_COUNT
    i2c2_uh2cd_write32(0x0128,0x00000101); // FUNC_ENABLE
    i2c2_uh2cd_write32(0x0130,0x00010000); // DSI_TATO_COUNT
    i2c2_uh2cd_write32(0x0134,0x00005000); // DSI_PRESP_BTA_COUNT
    i2c2_uh2cd_write32(0x0138,0x00010000); // DSI_PRESP_LPR_COUNT
    i2c2_uh2cd_write32(0x013C,0x00010000); // DSI_PRESP_LPW_COUNT
    i2c2_uh2cd_write32(0x0140,0x00010000); // DSI_PRESP_HSR_COUNT
    i2c2_uh2cd_write32(0x0144,0x00010000); // DSI_PRESP_HSW_COUNT
    i2c2_uh2cd_write32(0x0148,0x00001000); // DSI_PR_TO_COUNT
    i2c2_uh2cd_write32(0x014C,0x00010000); // DSI_LRX-H_TO_COUNT
    i2c2_uh2cd_write32(0x0150,0x00000141); // FUNC_MODE
    i2c2_uh2cd_write32(0x0154,0x00000001); // DSI_RX_VC_ENABLE
    i2c2_uh2cd_write32(0x0158,0x000000C8); // IND_TO_COUNT
    i2c2_uh2cd_write32(0x0168,0x0000002A); // DSI_HSYNC_STOP_COUNT
    i2c2_uh2cd_write32(0x0170,0x000002A0); // APF_VDELAYCNT	
    i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
    i2c2_uh2cd_write32(0x018C,0x00000020); // DSI_HSYNC_WIDTH
    i2c2_uh2cd_write32(0x0190,0x0000000E); // DSI_HBPR
    i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
    i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
    i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
    i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
    i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
    i2c2_uh2cd_write32(0x0254,0x00000005); // LPTXTIMECNT
    i2c2_uh2cd_write32(0x0258,0x001F0004); // TCLK_HEADERCNT
    i2c2_uh2cd_write32(0x025C,0x000B0005); // TCLK_TRAILCNT
    i2c2_uh2cd_write32(0x0260,0x000A0005); // THS_HEADERCNT
    i2c2_uh2cd_write32(0x0264,0x00004650); // TWAKEUPCNT
    i2c2_uh2cd_write32(0x0268,0x0000000C); // TCLK_POSTCNT
    i2c2_uh2cd_write32(0x026C,0x000B0007); // THS_TRAILCNT
    i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
    i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
    i2c2_uh2cd_write32(0x0278,0x00050004); // BTA_COUNT
    i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
    i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
    // DSI-TX1 Transition Timing
    i2c2_uh2cd_write32(0x0308,0x00000001); // DSI_TX_CLKEN
    i2c2_uh2cd_write32(0x030C,0x00000001); // DSI_TX_CLKSEL
    i2c2_uh2cd_write32(0x04A0,0x00000001); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x04AC,0x00001022); // MIPI_PLL_CNF
    Waitx1ms(1);
    i2c2_uh2cd_write32(0x04A0,0x00000003); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x0318,0x00000014); // LANE_ENABLE
    i2c2_uh2cd_write32(0x0320,0x000012BD); // LINE_INIT_COUNT
    i2c2_uh2cd_write32(0x0324,0x00000000); // HSTX_TO_COUNT
    i2c2_uh2cd_write32(0x0328,0x00000101); // FUNC_ENABLE
    i2c2_uh2cd_write32(0x0330,0x00010000); // DSI_TATO_COUNT
    i2c2_uh2cd_write32(0x0334,0x00005000); // DSI_PRESP_BTA_COUNT
    i2c2_uh2cd_write32(0x0338,0x00010000); // DSI_PRESP_LPR_COUNT
    i2c2_uh2cd_write32(0x033C,0x00010000); // DSI_PRESP_LPW_COUNT
    i2c2_uh2cd_write32(0x0340,0x00010000); // DSI_PRESP_HSR_COUNT
    i2c2_uh2cd_write32(0x0344,0x00010000); // DSI_PRESP_HSW_COUNT
    i2c2_uh2cd_write32(0x0348,0x00001000); // DSI_PR_TO_COUNT
    i2c2_uh2cd_write32(0x034C,0x00010000); // DSI_LRX-H_TO_COUNT
    i2c2_uh2cd_write32(0x0350,0x00000141); // FUNC_MODE
    i2c2_uh2cd_write32(0x0354,0x00000001); // DSI_RX_VC_ENABLE
    i2c2_uh2cd_write32(0x0358,0x000000C8); // IND_TO_COUNT
    i2c2_uh2cd_write32(0x0368,0x0000002A); // DSI_HSYNC_STOP_COUNT
    i2c2_uh2cd_write32(0x0370,0x000002A0); // APF_VDELAYCNT	
    i2c2_uh2cd_write32(0x037C,0x00000080); // DSI_TX_MODE
    i2c2_uh2cd_write32(0x038C,0x00000020); // DSI_HSYNC_WIDTH
    i2c2_uh2cd_write32(0x0390,0x0000000E); // DSI_HBPR
    i2c2_uh2cd_write32(0x03A4,0x00000000); // DSI_RX_STATE_INT_MASK
    i2c2_uh2cd_write32(0x03C0,0x00000015); // DSI_LPRX_THRESH_COUNT
    i2c2_uh2cd_write32(0x0414,0x00000000); // APP_SIDE_ERR_INT_MASK
    i2c2_uh2cd_write32(0x041C,0x00000080); // DSI_RX_ERR_INT_MASK
    i2c2_uh2cd_write32(0x0424,0x00000000); // DSI_LPTX_INT_MASK
    i2c2_uh2cd_write32(0x0454,0x00000005); // LPTXTIMECNT
    i2c2_uh2cd_write32(0x0458,0x001F0004); // TCLK_HEADERCNT
    i2c2_uh2cd_write32(0x045C,0x000B0005); // TCLK_TRAILCNT
    i2c2_uh2cd_write32(0x0460,0x000A0005); // THS_HEADERCNT
    i2c2_uh2cd_write32(0x0464,0x00004650); // TWAKEUPCNT
    i2c2_uh2cd_write32(0x0468,0x0000000C); // TCLK_POSTCNT
    i2c2_uh2cd_write32(0x046C,0x000B0007); // THS_TRAILCNT
    i2c2_uh2cd_write32(0x0470,0x00000020); // HSTXVREGCNT
    i2c2_uh2cd_write32(0x0474,0x0000001F); // HSTXVREGEN
    i2c2_uh2cd_write32(0x0478,0x00050004); // BTA_COUNT
    i2c2_uh2cd_write32(0x047C,0x00000002); // DPHY_TX ADJUST
    i2c2_uh2cd_write32(0x031C,0x00000001); // DSITX_START
    // Command Transmission Before Video Start
    i2c2_uh2cd_write16(0x0500,0x0004); // CMD_SEL
    i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG


    // LCD Initialization
    // POWER ON +/-AVDD
    // Wait 5ms
    /*
     LCDリセットあり上書き注意
     */
    Waitx1ms(5);
    Santek_LCD_Reset();
    Waitx1ms(10);
    // H/W RESET High Wait 10ms

    //パターン1
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x01D6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x18B3); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    //i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q    //輝度値
    i2c2_uh2cd_write16(0x0504,0x0051); // DCSCMD_Q  //輝度値
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1C53); // DCSCMD_Q 元は0C53
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0035); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x03B0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q

    Waitx1ms(5);
    // Host Data Transfer Start
    // Split Control
    i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
    i2c2_uh2cd_write16(0x500C,0x0000); // STX0_FPX
    i2c2_uh2cd_write16(0x500E,0x02CF); // STX0_LPX
    i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
    i2c2_uh2cd_write16(0x508C,0x02D0); // STX1_FPX
    i2c2_uh2cd_write16(0x508E,0x059F); // STX1_LPX
    i2c2_uh2cd_write16(0x7080,0x0080); // STX_DBG
    i2c2_uh2cd_write16(0x5008,0x0870); // STX0_WC
    i2c2_uh2cd_write16(0x5088,0x0870); // STX1_WC
    // Enable Interrupt
    i2c2_uh2cd_write8(0x8502,0xFF); // SYS_INT
    i2c2_uh2cd_write8(0x8503,0xFF); // CLK_INT
    i2c2_uh2cd_write8(0x8504,0xFF); // PACKET_INT
    i2c2_uh2cd_write8(0x8505,0xFF); // CBIT_INT
    i2c2_uh2cd_write8(0x8506,0xFF); // AUDIO_INT
    i2c2_uh2cd_write8(0x850B,0xFF); // MISC_INT
    i2c2_uh2cd_write16(0x0014,0x0F3F); // IntStatus
    i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
    // Start Video TX
    i2c2_uh2cd_write16(0x0004,0x0C37); // ConfCtl0
    i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
    // Command Transmission After Video Start.
    i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
}

void santek_DO(void)
{
// Auto Disp Off(RS_DO)
// Software Reset
i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
i2c2_uh2cd_write16(0x0006,0x0008); // ConfCtl1
i2c2_uh2cd_write16(0x0002,0x1200); // SysCtl
i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
i2c2_uh2cd_write16(0x7000,0x0009); // CB_CTL
// DSI-TX1 Transition Timing
i2c2_uh2cd_write32(0x0308,0x00000001); // DSI_TX_CLKEN
i2c2_uh2cd_write32(0x030C,0x00000001); // DSI_TX_CLKSEL
i2c2_uh2cd_write32(0x04A0,0x00000001); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x04AC,0x00001022); // MIPI_PLL_CNF
Waitx1ms(1);
i2c2_uh2cd_write32(0x04A0,0x00000003); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x0318,0x00000014); // LANE_ENABLE
i2c2_uh2cd_write32(0x0320,0x000012BD); // LINE_INIT_COUNT
i2c2_uh2cd_write32(0x0324,0x00000000); // HSTX_TO_COUNT
i2c2_uh2cd_write32(0x0328,0x00000101); // FUNC_ENABLE
i2c2_uh2cd_write32(0x0330,0x00010000); // DSI_TATO_COUNT
i2c2_uh2cd_write32(0x0334,0x00005000); // DSI_PRESP_BTA_COUNT
i2c2_uh2cd_write32(0x0338,0x00010000); // DSI_PRESP_LPR_COUNT
i2c2_uh2cd_write32(0x033C,0x00010000); // DSI_PRESP_LPW_COUNT
i2c2_uh2cd_write32(0x0340,0x00010000); // DSI_PRESP_HSR_COUNT
i2c2_uh2cd_write32(0x0344,0x00010000); // DSI_PRESP_HSW_COUNT
i2c2_uh2cd_write32(0x0348,0x00001000); // DSI_PR_TO_COUNT
i2c2_uh2cd_write32(0x034C,0x00010000); // DSI_LRX-H_TO_COUNT
i2c2_uh2cd_write32(0x0350,0x00000141); // FUNC_MODE
i2c2_uh2cd_write32(0x0354,0x00000001); // DSI_RX_VC_ENABLE
i2c2_uh2cd_write32(0x0358,0x000000C8); // IND_TO_COUNT
i2c2_uh2cd_write32(0x0368,0x0000002A); // DSI_HSYNC_STOP_COUNT
i2c2_uh2cd_write32(0x0370,0x00000649); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x037C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x038C,0x00000010); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0390,0x0000001E); // DSI_HBPR
i2c2_uh2cd_write32(0x03A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x03C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0414,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x041C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0424,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0454,0x00000005); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0458,0x001F0004); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x045C,0x000B0005); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0460,0x000A0005); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0464,0x00004650); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0468,0x0000000C); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x046C,0x000B0007); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0470,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0474,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0478,0x00050004); // BTA_COUNT
i2c2_uh2cd_write32(0x047C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x031C,0x00000001); // DSITX_START
// DSI-TX0 Transition Timing
i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x02AC,0x00001022); // MIPI_PLL_CNF
Waitx1ms(1);
i2c2_uh2cd_write32(0x02A0,0x00000003); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x0118,0x00000014); // LANE_ENABLE
i2c2_uh2cd_write32(0x0120,0x000012BD); // LINE_INIT_COUNT
i2c2_uh2cd_write32(0x0124,0x00000000); // HSTX_TO_COUNT
i2c2_uh2cd_write32(0x0128,0x00000101); // FUNC_ENABLE
i2c2_uh2cd_write32(0x0130,0x00010000); // DSI_TATO_COUNT
i2c2_uh2cd_write32(0x0134,0x00005000); // DSI_PRESP_BTA_COUNT
i2c2_uh2cd_write32(0x0138,0x00010000); // DSI_PRESP_LPR_COUNT
i2c2_uh2cd_write32(0x013C,0x00010000); // DSI_PRESP_LPW_COUNT
i2c2_uh2cd_write32(0x0140,0x00010000); // DSI_PRESP_HSR_COUNT
i2c2_uh2cd_write32(0x0144,0x00010000); // DSI_PRESP_HSW_COUNT
i2c2_uh2cd_write32(0x0148,0x00001000); // DSI_PR_TO_COUNT
i2c2_uh2cd_write32(0x014C,0x00010000); // DSI_LRX-H_TO_COUNT
i2c2_uh2cd_write32(0x0150,0x00000141); // FUNC_MODE
i2c2_uh2cd_write32(0x0154,0x00000001); // DSI_RX_VC_ENABLE
i2c2_uh2cd_write32(0x0158,0x000000C8); // IND_TO_COUNT
i2c2_uh2cd_write32(0x0168,0x0000002A); // DSI_HSYNC_STOP_COUNT
i2c2_uh2cd_write32(0x0170,0x00000649); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x018C,0x00000010); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0190,0x0000001E); // DSI_HBPR
i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0254,0x00000005); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0258,0x001F0004); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x025C,0x000B0005); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0260,0x000A0005); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0264,0x00004650); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0268,0x0000000C); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x026C,0x000B0007); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0278,0x00050004); // BTA_COUNT
i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
// Command Transmission Before Video Start
i2c2_uh2cd_write16(0x0500,0x0004); // CMD_SEL
// Split Control
i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
i2c2_uh2cd_write16(0x500C,0x8000); // STX0_FPX
i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
// Color Bar Setting
i2c2_uh2cd_write16(0x7008,0x0020); // CB_HSW
i2c2_uh2cd_write16(0x700A,0x0002); // CB_VSW
i2c2_uh2cd_write16(0x700C,0x0632); // CB_Htotal
i2c2_uh2cd_write16(0x700E,0x0A08); // CB_Vtotal
i2c2_uh2cd_write16(0x7010,0x05A0); // CB_Hact
i2c2_uh2cd_write16(0x7012,0x0A00); // CB_Vact
i2c2_uh2cd_write16(0x7014,0x0048); // CB_Hstart
i2c2_uh2cd_write16(0x7016,0x0004); // CB_Vstart
i2c2_uh2cd_write16(0x7000,0x0007); // CB_CTL
// Start Video TX
i2c2_uh2cd_write16(0x0004,0x0C37); // ConfCtl0
// Command Transmission After Video Start. HS command TX
i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
i2c2_uh2cd_write16(0x7000,0x0000); // CB_CTL

}


void santek_RS4(void)
{
// MIPI Output Disable(RS4)
// Reset Display by H/W reset
// Stop CSI output
i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask

}

void santek_LCDOFF()
{
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
}

void santek_LCDBrightness(int16_t brightness)
{
    int16_t bright = brightness * 0.249; //1023を255へ
    bright = bright << 8;
    bright = bright & 0xFF00;
    bright = bright | 0x0051;
    
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,bright); // DCSCMD_Q
}
