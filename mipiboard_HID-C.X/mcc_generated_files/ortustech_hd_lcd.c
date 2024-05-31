/*
 * File:   ortustech_hd_lcd.c
 * Author: thaya
 *
 * Created on 2020/01/04, 22:24
 */


#include "xc.h"
#include "pin_manager.h"
#include "TC358870.h"
#include "ortustech_hd_lcd.h"
#include "thd_i2c2.h"
#include "power_reset.h"
#define FCY 16000000UL 
#include <libpic30.h>

void ortustech_RS1(void)
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
i2c2_uh2cd_write8(0x8420,0x06); // EQ_BYPS
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
i2c2_uh2cd_write8(0x8C08,0x52); // EDID_RAM
i2c2_uh2cd_write8(0x8C09,0x62); // EDID_RAM
i2c2_uh2cd_write8(0x8C0A,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C0B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0C,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C0D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C0F,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C10,0x1C); // EDID_RAM
i2c2_uh2cd_write8(0x8C11,0x1D); // EDID_RAM
i2c2_uh2cd_write8(0x8C12,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C13,0x03); // EDID_RAM
i2c2_uh2cd_write8(0x8C14,0x80); // EDID_RAM
i2c2_uh2cd_write8(0x8C15,0x06); // EDID_RAM
i2c2_uh2cd_write8(0x8C16,0x0A); // EDID_RAM
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
i2c2_uh2cd_write8(0x8C36,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8C37,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8C38,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8C39,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8C3A,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C3B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C3C,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8C3D,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C3E,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8C3F,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C40,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8C41,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C42,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8C43,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8C44,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C45,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C46,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C47,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8C48,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8C49,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8C4A,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8C4B,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8C4C,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C4D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C4E,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8C4F,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C50,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8C51,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C52,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8C53,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C54,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8C55,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8C56,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C57,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C58,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C59,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8C5A,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5B,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5C,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5D,0xFC); // EDID_RAM
i2c2_uh2cd_write8(0x8C5E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C5F,0x43); // EDID_RAM
i2c2_uh2cd_write8(0x8C60,0x4F); // EDID_RAM
i2c2_uh2cd_write8(0x8C61,0x4D); // EDID_RAM
i2c2_uh2cd_write8(0x8C62,0x35); // EDID_RAM
i2c2_uh2cd_write8(0x8C63,0x30); // EDID_RAM
i2c2_uh2cd_write8(0x8C64,0x48); // EDID_RAM
i2c2_uh2cd_write8(0x8C65,0x35); // EDID_RAM
i2c2_uh2cd_write8(0x8C66,0x4E); // EDID_RAM
i2c2_uh2cd_write8(0x8C67,0x30); // EDID_RAM
i2c2_uh2cd_write8(0x8C68,0x33); // EDID_RAM
i2c2_uh2cd_write8(0x8C69,0x55); // EDID_RAM
i2c2_uh2cd_write8(0x8C6A,0x4C); // EDID_RAM
i2c2_uh2cd_write8(0x8C6B,0x43); // EDID_RAM
i2c2_uh2cd_write8(0x8C6C,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6D,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6E,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C6F,0xFD); // EDID_RAM
i2c2_uh2cd_write8(0x8C70,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C71,0x36); // EDID_RAM
i2c2_uh2cd_write8(0x8C72,0x42); // EDID_RAM
i2c2_uh2cd_write8(0x8C73,0x45); // EDID_RAM
i2c2_uh2cd_write8(0x8C74,0x4B); // EDID_RAM
i2c2_uh2cd_write8(0x8C75,0x06); // EDID_RAM
i2c2_uh2cd_write8(0x8C76,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8C77,0x0A); // EDID_RAM
i2c2_uh2cd_write8(0x8C78,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C79,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7A,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7B,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7C,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7D,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C7E,0x01); // EDID_RAM
i2c2_uh2cd_write8(0x8C7F,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8C80,0x02); // EDID_RAM
i2c2_uh2cd_write8(0x8C81,0x03); // EDID_RAM
i2c2_uh2cd_write8(0x8C82,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8C83,0xC0); // EDID_RAM
i2c2_uh2cd_write8(0x8C84,0x47); // EDID_RAM
i2c2_uh2cd_write8(0x8C85,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C86,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C87,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C88,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C89,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C8A,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C8B,0x7D); // EDID_RAM
i2c2_uh2cd_write8(0x8C8C,0x23); // EDID_RAM
i2c2_uh2cd_write8(0x8C8D,0x08); // EDID_RAM
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
i2c2_uh2cd_write8(0x8C9A,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8C9B,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8C9C,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8C9D,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8C9E,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8C9F,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA0,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8CA1,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CA2,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8CA3,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CA4,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8CA5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA6,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8CA7,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8CA8,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CA9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CAA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CAB,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CAC,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8CAD,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8CAE,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8CAF,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8CB0,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CB1,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CB2,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8CB3,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CB4,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8CB5,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CB6,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8CB7,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CB8,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8CB9,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8CBA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CBD,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CBE,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8CBF,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8CC0,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8CC1,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8CC2,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CC3,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CC4,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8CC5,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CC6,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8CC7,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CC8,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8CC9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCA,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8CCB,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8CCC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCD,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CCF,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CD0,0x4A); // EDID_RAM
i2c2_uh2cd_write8(0x8CD1,0x1A); // EDID_RAM
i2c2_uh2cd_write8(0x8CD2,0xD0); // EDID_RAM
i2c2_uh2cd_write8(0x8CD3,0xB0); // EDID_RAM
i2c2_uh2cd_write8(0x8CD4,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CD5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CD6,0x0C); // EDID_RAM
i2c2_uh2cd_write8(0x8CD7,0x50); // EDID_RAM
i2c2_uh2cd_write8(0x8CD8,0x5B); // EDID_RAM
i2c2_uh2cd_write8(0x8CD9,0x20); // EDID_RAM
i2c2_uh2cd_write8(0x8CDA,0x63); // EDID_RAM
i2c2_uh2cd_write8(0x8CDB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CDC,0x3D); // EDID_RAM
i2c2_uh2cd_write8(0x8CDD,0x6D); // EDID_RAM
i2c2_uh2cd_write8(0x8CDE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CDF,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE0,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE1,0x18); // EDID_RAM
i2c2_uh2cd_write8(0x8CE2,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE3,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE4,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE5,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE6,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE7,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE8,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CE9,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEA,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEB,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEC,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CED,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEE,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CEF,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF0,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF1,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF2,0x00); // EDID_RAM
i2c2_uh2cd_write8(0x8CF3,0x00); // EDID_RAM
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
i2c2_uh2cd_write8(0x8CFF,0x34); // EDID_RAM
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
return;
}

uint16_t ortustech_Check_HDMI_Cable(void)
{
    uint8_t retVal;
// Check HDMI cable status
retVal = i2c2_uh2cd_read8(0x8520); // 
retVal = i2c2_uh2cd_read8(0x8520); //
retVal = i2c2_uh2cd_read8(0x8520); //
retVal = retVal & 0x01; // bit0 = DDC_POWER HDMI Connector is Connected
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
// Enter Sleep
i2c2_uh2cd_write16(0x0002,0x0001); // SysCtl
return (uint16_t)retVal;
}
uint16_t ortustech_Check_RS_Int(void)
{
uint16_t d_IntStatus,retVal;
uint8_t  d_IntSYSSTATUS,d_MISC_INT;
uint8_t  HPI_chg,I_DDC,S_DDC5V;    
// Interrupt Service Routine(RS_Int)
// Exit from Sleep
i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
Waitx1us(10);
// Check Interrupt
d_IntStatus = i2c2_uh2cd_read16(0x0014); // IntStatus
d_IntSYSSTATUS = i2c2_uh2cd_read16(0x001A); // IntSYSSTATUS
HPI_chg =(uint8_t)(d_IntSYSSTATUS & 0x0001); // Check HPDI Change DDC_5V ON or OFF
I_DDC = i2c2_uh2cd_read8(0x8502); // SYS_INT
I_DDC = 0x01; // DDC Power 0V<-->5V Change
d_MISC_INT = i2c2_uh2cd_read8(0x850B); // MISC_INT
S_DDC5V = i2c2_uh2cd_read8(0x8520); // SYS_STATUS
S_DDC5V = S_DDC5V & 0x81; //bit0 = 1 DDC5V input = 0:DDC5V no input
                          //bit7 = 1 S_SYNC stable = 0: unstable
i2c2_uh2cd_write16(0x0016,0x0F3F); // IntMask
i2c2_uh2cd_write8(0x8502,0xFF); // SYS_INT
i2c2_uh2cd_write8(0x850B,0xFF); // MISC_INT
i2c2_uh2cd_write16(0x0014,0x0F3F); // IntStatus 
//bit7:S_SYNC 1=Stable 0=unstable
//bit2:HPI_chg DDC5V status change
//bit1:I_DDC DDC Power 0V<-->5V Change
//bit0:S_DDC Statsu of 5V ON or OFF
retVal = (HPI_chg << 2)|(I_DDC << 1)|S_DDC5V;
return retVal;
}
void ortustech_RS2_Ready(void)
{
// Initialization for Ready (RS2)
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
// Set HPDO to "H"
i2c2_uh2cd_write8(0x854A,0x01); // INIT_END
}

void ortustech_RS3(void)
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
i2c2_uh2cd_write32(0x02AC,0x00001423); // MIPI_PLL_CNF
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
i2c2_uh2cd_write32(0x0170,0x000002AA); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x018C,0x0000000F); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0190,0x00000055); // DSI_HBPR
i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0254,0x00000002); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0258,0x00120002); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x025C,0x00050002); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0260,0x00030003); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0264,0x00004A38); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0268,0x00000008); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x026C,0x00050004); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0278,0x00020001); // BTA_COUNT
i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
// DSI-TX1 Transition Timing
// Command Transmission Before Video Start
i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG
// LCD Initialization
// SETEXTC
/* ここにＬＣＤリセットあり上書き注意　*/
Ortustech_LCD_Reset();  //LCD リセット解除

i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xFFB9); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9483); // DCSCMD_Q
// SETPOWER
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x7CB1); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2400); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0106); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1D1D); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1257); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE601); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00E2); // DCSCMD_Q
// SETDISP
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0007); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00B2); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x04C8); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0066); // DCSCMD_Q
// INVOFF
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0020); // DCSCMD_Q
// MADCTL
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0036); // DCSCMD_Q
// COLMOD
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x703A); // DCSCMD_Q
// SETCYC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x001F); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00B4); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3204); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1032); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3200); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0810); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0127); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0353); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0137); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0153); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3030); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0101); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x6161); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x06BF); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1002); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00C7); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x08C6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0008); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0CC0); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
// SETGIP
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0021); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00D5); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0A00); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0100); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0033); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3300); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5432); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1076); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8832); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9999); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5499); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8876); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0088); // DCSCMD_Q
// SETDGC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0080); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x01C1); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0600); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x160E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x261E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x362E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x463E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x564E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x665E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x766E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x867E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x968E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xA69E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xB6AE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xC6BE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xD6CE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE6DE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xF6EE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00FE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0300); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x130B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x231B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x332B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x433B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x534B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x635B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x736B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x837B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x938B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xA39B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xB3AB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xC3BB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xD3CB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE3DB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xF3EB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00FB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1008); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1E18); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3E36); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x4E46); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5E56); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x6E66); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x7E76); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8E86); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9E96); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xAEA6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xBEB6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xCEC6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xDED6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xEDE6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00F5); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
// SETGAMMA
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x002B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00E0); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1D12); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1334); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x042A); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x120C); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1916); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1616); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x110E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1800); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3F24); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2C16); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0D04); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1610); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1618); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1016); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0711); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0616); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x080F); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0716); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
// SETCABC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x000A); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0FC9); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1E00); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x001E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3E01); // DCSCMD_Q
// WRDDISBV
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q
// WRCTRLD
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0053); // DCSCMD_Q
// SETVDC
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x07BC); // DCSCMD_Q
Waitx1ms(5);
// SETPANEL
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x09CC); // DCSCMD_Q
Waitx1ms(50);
// SETMIPI
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x03BA); // DCSCMD_Q
// SLEEP OUT
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
Waitx1ms(200);
// DISPON
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
Waitx1ms(600);
// Split Control
i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
i2c2_uh2cd_write16(0x500C,0x0000); // STX0_FPX
i2c2_uh2cd_write16(0x500E,0x02CF); // STX0_LPX
i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
i2c2_uh2cd_write16(0x508C,0x0000); // STX1_FPX
i2c2_uh2cd_write16(0x508E,0x02CF); // STX1_LPX
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
i2c2_uh2cd_write16(0x0004,0x0C35); // ConfCtl0
i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
// Command Transmission After Video Start.
i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG   
}
void ortustech_DO(void)
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
// DSI-TX0 Transition Timing
i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
i2c2_uh2cd_write32(0x02AC,0x00001423); // MIPI_PLL_CNF
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
i2c2_uh2cd_write32(0x0170,0x00000296); // APF_VDELAYCNT
i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
i2c2_uh2cd_write32(0x018C,0x0000000F); // DSI_HSYNC_WIDTH
i2c2_uh2cd_write32(0x0190,0x00000055); // DSI_HBPR
i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
i2c2_uh2cd_write32(0x0254,0x00000002); // LPTXTIMECNT
i2c2_uh2cd_write32(0x0258,0x00120002); // TCLK_HEADERCNT
i2c2_uh2cd_write32(0x025C,0x00050002); // TCLK_TRAILCNT
i2c2_uh2cd_write32(0x0260,0x00030003); // THS_HEADERCNT
i2c2_uh2cd_write32(0x0264,0x00004A38); // TWAKEUPCNT
i2c2_uh2cd_write32(0x0268,0x00000008); // TCLK_POSTCNT
i2c2_uh2cd_write32(0x026C,0x00050004); // THS_TRAILCNT
i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
i2c2_uh2cd_write32(0x0278,0x00020001); // BTA_COUNT
i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
// Command Transmission Before Video Start
i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
// Split Control
i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
i2c2_uh2cd_write16(0x500C,0x8000); // STX0_FPX
i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
// Color Bar Setting
i2c2_uh2cd_write16(0x7008,0x0020); // CB_HSW
i2c2_uh2cd_write16(0x700A,0x0003); // CB_VSW
i2c2_uh2cd_write16(0x700C,0x0380); // CB_Htotal
i2c2_uh2cd_write16(0x700E,0x050C); // CB_Vtotal
i2c2_uh2cd_write16(0x7010,0x02D0); // CB_Hact
i2c2_uh2cd_write16(0x7012,0x0500); // CB_Vact
i2c2_uh2cd_write16(0x7014,0x0055); // CB_Hstart
i2c2_uh2cd_write16(0x7016,0x0006); // CB_Vstart
i2c2_uh2cd_write16(0x7000,0x0007); // CB_CTL
// Start Video TX
i2c2_uh2cd_write16(0x0004,0x0C35); // ConfCtl0
// Command Transmission After Video Start. HS command TX
i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
i2c2_uh2cd_write16(0x7000,0x0000); // CB_CTL    
}

void ortustech_RS4(void)
{
  // MIPI Output Disable(RS4)
// Reset Display by H/W reset
Ortustech_LCD_Reset();
// Stop CSI output
i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
// Enable Interrupt
i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask  
}

void HDMI_TimChk(uint8_t *data)
{
/*
#define PX_FREQ0 0
#define	PX_FREQ1 1

#define	H_SIZE0 2
#define	H_SIZE1 3
#define	DE_HPOS0 4
#define	DE_HPOS1 5
#define	DE_HWID0 6
#define	DE_HWID1 7

#define	V_SIZE0 8
#define	V_SIZE1 9
#define	DE_POS_A0 10
#define	DE_POS_A1 11
#define	DE_POS_B0 12
#define	DE_POS_B1 13
#define	DE_VWID0 14
#define	DE_VWID1 15
#define	VI_STATUS1 16
*/
    
i2c2_uh2cd_write8(0x8540,0xC0); // SYS_FREQ0
i2c2_uh2cd_write8(0x8541,0x12); // SYS_FREQ1
i2c2_uh2cd_write8(0x8A0C,0xC0); // SYS_FREQ0(CSC)
i2c2_uh2cd_write8(0x8A0D,0x12); // SYS_FREQ1(CSC)
i2c2_uh2cd_write8(0x8593,0x33); // HV_CLR
Waitx1ms(100);
// HDMI Input Video Timing Check (PCLK)
//PX_FREQ0 
*data = i2c2_uh2cd_read8(0x8405); // PX_FREQ0
data++;
//PX_FREQ1 
*data = i2c2_uh2cd_read8(0x8406); // PX_FREQ1
data++;
// HDMI Input Video Timing Check (Horizontal Related)
//H_SIZE0 
*data = i2c2_uh2cd_read8(0x858E); // H_SIZE0
data++;
//H_SIZE1 
*data = i2c2_uh2cd_read8(0x858F); // H_SIZE1
data++;
//DE_HPOS0 
*data = i2c2_uh2cd_read8(0x8580); // DE_HPOS0
data++;
//DE_HPOS1 
*data = i2c2_uh2cd_read8(0x8581); // DE_HPOS1
data++;
//DE_HWID0 
*data = i2c2_uh2cd_read8(0x8582); // DE_HWID0
data++;
//DE_HWID1 
*data = i2c2_uh2cd_read8(0x8583); // DE_HWID1
data++;
// HDMI Input Video Timing Check (Vertical Related)
//V_SIZE0 
*data = i2c2_uh2cd_read8(0x8590); // V_SIZE0
data++;
//V_SIZE1 
*data = i2c2_uh2cd_read8(0x8591); // V_SIZE1
data++;
//DE_POS_A0 
*data = i2c2_uh2cd_read8(0x8584); // DE_POS_A0
data++;
//DE_POS_A1 
*data = i2c2_uh2cd_read8(0x8585); // DE_POS_A1
data++;
//DE_POS_B0 
*data = i2c2_uh2cd_read8(0x8586); // DE_POS_B0
data++;
//DE_POS_B1 
*data = i2c2_uh2cd_read8(0x8587); // DE_POS_B1
data++;
//DE_VWID0 
*data = i2c2_uh2cd_read8(0x858C); // DE_VWID0
data++;
//DE_VWID1 
*data = i2c2_uh2cd_read8(0x858D); // DE_VWID1
data++;
// HDMI Input Video Timing Check (VSYNC,HSYNC Porarity)
//VI_STATUS1 
*data = i2c2_uh2cd_read8(0x8526); // VI_STATUS1
}

void ortustech_LCDInit(){
i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG
    
    /* ここにＬＣＤリセットあり上書き注意　*/
Ortustech_LCD_Reset();  //LCD リセット解除

i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xFFB9); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9483); // DCSCMD_Q
// SETPOWER
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x7CB1); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2400); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0106); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1D1D); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1257); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE601); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00E2); // DCSCMD_Q
// SETDISP
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0007); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00B2); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x04C8); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0066); // DCSCMD_Q
// INVOFF
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0020); // DCSCMD_Q
// MADCTL
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0036); // DCSCMD_Q
// COLMOD
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x703A); // DCSCMD_Q
// SETCYC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x001F); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00B4); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3204); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1032); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3200); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0810); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0127); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0353); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0137); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0153); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3030); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0101); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x6161); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x06BF); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1002); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00C7); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x08C6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0008); // DCSCMD_Q
// Not open
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0CC0); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
// SETGIP
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0021); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00D5); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0A00); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0100); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0033); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3300); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5432); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1076); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8832); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9999); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5499); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8876); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0088); // DCSCMD_Q
// SETDGC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0080); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x01C1); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0600); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x160E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x261E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x362E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x463E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x564E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x665E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x766E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x867E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x968E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xA69E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xB6AE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xC6BE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xD6CE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE6DE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xF6EE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00FE); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0300); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x130B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x231B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x332B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x433B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x534B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x635B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x736B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x837B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x938B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xA39B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xB3AB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xC3BB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xD3CB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xE3DB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xF3EB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00FB); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1008); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1E18); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3E36); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x4E46); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x5E56); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x6E66); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x7E76); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x8E86); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x9E96); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xAEA6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xBEB6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xCEC6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xDED6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xEDE6); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00F5); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
// SETGAMMA
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x002B); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x00E0); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1D12); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1334); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x042A); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x120C); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1916); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1616); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x110E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1800); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3F24); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x2C16); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0D04); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1610); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1618); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1016); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0711); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0616); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x080F); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0716); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
// SETCABC
i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x000A); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0FC9); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x1E00); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x001E); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x3E01); // DCSCMD_Q
// WRDDISBV
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q
// WRCTRLD
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0053); // DCSCMD_Q
// SETVDC
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x07BC); // DCSCMD_Q
Waitx1ms(5);
// SETPANEL
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x09CC); // DCSCMD_Q
Waitx1ms(50);
// SETMIPI
i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x03BA); // DCSCMD_Q
// SLEEP OUT
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
Waitx1ms(200);
// DISPON
i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
Waitx1ms(600);
}

//ターナープログラム
void turner_RS1( void )
{
//#define TC_FUNC_MODE_VALUE 0x00000161
//	BYTE	rdata8;
//	BYTE	bytebuf[5];
//	WORD	rdata16;
//    DWORD   rdata32;
//	WORD i;
//	static	BYTE step;
//	static	WORD	cnt;
//	static	BYTE _go_rs2_rs3;
	
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
    i2c2_uh2cd_write8(0x8420,0x06); // EQ_BYPS
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
    i2c2_uh2cd_write8(0x8C08,0x52); // EDID_RAM
    i2c2_uh2cd_write8(0x8C09,0x62); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0A,0x07); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0B,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0C,0x07); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0D,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0E,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C0F,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C10,0x1C); // EDID_RAM
    i2c2_uh2cd_write8(0x8C11,0x1D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C12,0x01); // EDID_RAM
    i2c2_uh2cd_write8(0x8C13,0x03); // EDID_RAM
    i2c2_uh2cd_write8(0x8C14,0x80); // EDID_RAM
    i2c2_uh2cd_write8(0x8C15,0x06); // EDID_RAM
    i2c2_uh2cd_write8(0x8C16,0x0A); // EDID_RAM
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
    i2c2_uh2cd_write8(0x8C36,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C37,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C38,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C39,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3A,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3B,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3C,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3D,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3E,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8C3F,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C40,0x63); // EDID_RAM 
    i2c2_uh2cd_write8(0x8C41,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C42,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C43,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C44,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C45,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C46,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C47,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8C48,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C49,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4A,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4B,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4C,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4D,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4E,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8C4F,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8C50,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8C51,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C52,0x63); // EDID_RAM
    i2c2_uh2cd_write8(0x8C53,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C54,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C55,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C56,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C57,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C58,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C59,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5A,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5B,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5C,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5D,0xFC); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5E,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C5F,0x54); // EDID_RAM
    i2c2_uh2cd_write8(0x8C60,0x6F); // EDID_RAM
    i2c2_uh2cd_write8(0x8C61,0x73); // EDID_RAM
    i2c2_uh2cd_write8(0x8C62,0x68); // EDID_RAM
    i2c2_uh2cd_write8(0x8C63,0x69); // EDID_RAM
    i2c2_uh2cd_write8(0x8C64,0x62); // EDID_RAM
    i2c2_uh2cd_write8(0x8C65,0x61); // EDID_RAM
    i2c2_uh2cd_write8(0x8C66,0x2D); // EDID_RAM
    i2c2_uh2cd_write8(0x8C67,0x55); // EDID_RAM
    i2c2_uh2cd_write8(0x8C68,0x48); // EDID_RAM
    i2c2_uh2cd_write8(0x8C69,0x32); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6A,0x44); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6B,0x0A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6C,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6D,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6E,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C6F,0xFD); // EDID_RAM
    i2c2_uh2cd_write8(0x8C70,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C71,0x36); // EDID_RAM
    i2c2_uh2cd_write8(0x8C72,0x42); // EDID_RAM
    i2c2_uh2cd_write8(0x8C73,0x45); // EDID_RAM
    i2c2_uh2cd_write8(0x8C74,0x4B); // EDID_RAM
    i2c2_uh2cd_write8(0x8C75,0x06); // EDID_RAM
    i2c2_uh2cd_write8(0x8C76,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8C77,0x0A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C78,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C79,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7A,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7B,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7C,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7D,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7E,0x01); // EDID_RAM
    i2c2_uh2cd_write8(0x8C7F,0x86); // EDID_RAM
    i2c2_uh2cd_write8(0x8C80,0x02); // EDID_RAM
    i2c2_uh2cd_write8(0x8C81,0x03); // EDID_RAM
    i2c2_uh2cd_write8(0x8C82,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C83,0xC1); // EDID_RAM
    i2c2_uh2cd_write8(0x8C84,0x47); // EDID_RAM
    i2c2_uh2cd_write8(0x8C85,0xED); // EDID_RAM
    i2c2_uh2cd_write8(0x8C86,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C87,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C88,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C89,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C8A,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C8B,0x6E); // EDID_RAM
    i2c2_uh2cd_write8(0x8C8C,0x23); // EDID_RAM
    i2c2_uh2cd_write8(0x8C8D,0x08); // EDID_RAM
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
    i2c2_uh2cd_write8(0x8C9A,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C9B,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8C9C,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C9D,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8C9E,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8C9F,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA0,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA1,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA2,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA3,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA4,0x63); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA5,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA6,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA7,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA8,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CA9,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAA,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAB,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAC,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAD,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAE,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CAF,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB0,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB1,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB2,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB3,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB4,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB5,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB6,0x63); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB7,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB8,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CB9,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBA,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBB,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBC,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBD,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBE,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CBF,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC0,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC1,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC2,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC3,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC4,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC5,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC6,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC7,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC8,0x63); // EDID_RAM
    i2c2_uh2cd_write8(0x8CC9,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCA,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCB,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCC,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCD,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCE,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CCF,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD0,0x4A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD1,0x1A); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD2,0xD0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD3,0xB0); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD4,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD5,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD6,0x0C); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD7,0x50); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD8,0x5B); // EDID_RAM
    i2c2_uh2cd_write8(0x8CD9,0x20); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDA,0x63); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDB,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDC,0x3D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDD,0x6D); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDE,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CDF,0x00); // EDID_RAM 
    i2c2_uh2cd_write8(0x8CE0,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE1,0x18); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE2,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE3,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE4,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE5,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE6,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE7,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE8,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CE9,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CEA,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CEB,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CEC,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CED,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CEE,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CEF,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CF0,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CF1,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CF2,0x00); // EDID_RAM
    i2c2_uh2cd_write8(0x8CF3,0x00); // EDID_RAM
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
    i2c2_uh2cd_write8(0x8CFF,0x1D); // EDID_RAM
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
    // Check HDMI cable status
    i2c2_uh2cd_read8(0x8520); // 
//    i2c2_uh2cd_read8(0x8520); //  1回にしてみる
//    i2c2_uh2cd_read8(0x8520); // 
    // Enable Interrupt
    i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
    // Enter Sleep
    i2c2_uh2cd_write16(0x0002,0x0001); // SysCtl
    // Interrupt Service Routine(RS_Int)
    // Exit from Sleep
    i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
    Waitx1us(10);


//    i2c2_uh2cd_write16(0x85C6,0x0053);    //不明なレジスタ
//    i2c2_uh2cd_write16(0x85C8,0x01A1); 

    Waitx1us(10);
    // Check Interrupt
    i2c2_uh2cd_read16(0x0014); // IntStatus
    i2c2_uh2cd_read16(0x001A); // IntSYSSTATUS
    i2c2_uh2cd_read8(0x8502); // SYS_INT
    i2c2_uh2cd_read8(0x850B); // MISC_INT
    i2c2_uh2cd_read8(0x8520); // SYS_STATUS
    i2c2_uh2cd_write16(0x0016,0x0F3F); // IntMask
    i2c2_uh2cd_write8(0x8502,0xFF); // SYS_INT
    i2c2_uh2cd_write8(0x850B,0xFF); // MISC_INT
    i2c2_uh2cd_write16(0x0014,0x0F3F); // IntStatus

    //	for( i = 0;i < 256; i++)
    //	{
    //		Zread_byte[i] = read_byte(0x8C00 + i);
    //	}
	//i = 0;
}

void turner_RS3(){
    // MIPI Output Enable(RS3)
    // Check HDMI resolution/format
    Waitx1ms(2000);
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
    i2c2_uh2cd_write32(0x02AC,0x00001425); // MIPI_PLL_CNF
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
    i2c2_uh2cd_write32(0x0170,0x000002D0); // APF_VDELAYCNT
    i2c2_uh2cd_write32(0x017C,0x00000081); // DSI_TX_MODE
    i2c2_uh2cd_write32(0x018C,0x0000000F); // DSI_HSYNC_WIDTH
    i2c2_uh2cd_write32(0x0190,0x00000055); // DSI_HBPR
    i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK 
    i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
    i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
    i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
    i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
    i2c2_uh2cd_write32(0x0254,0x00000002); // LPTXTIMECNT
    i2c2_uh2cd_write32(0x0258,0x00120002); // TCLK_HEADERCNT
    i2c2_uh2cd_write32(0x025C,0x00050002); // TCLK_TRAILCNT
    i2c2_uh2cd_write32(0x0260,0x00030003); // THS_HEADERCNT
    i2c2_uh2cd_write32(0x0264,0x00004A38); // TWAKEUPCNT
    i2c2_uh2cd_write32(0x0268,0x00000008); // TCLK_POSTCNT
    i2c2_uh2cd_write32(0x026C,0x00050004); // THS_TRAILCNT
    i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
    i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
    i2c2_uh2cd_write32(0x0278,0x00020001); // BTA_COUNT
    i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
    i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
    // DSI-TX1 Transition Timing
    // Command Transmission Before Video Start
    i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
    i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG   
    i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG

    //Turner_LCD_Reset();

    // DSI-TX1 Transition Timing
    // Command Transmission Before Video Start
    i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
    i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG
    Waitx1ms(10);
    // LCD Initialization
    // SETEXTC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xFFB9); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9483); // DCSCMD_Q
    // SETPOWER
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x7CB1); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2400); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0106); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1D1D); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1257); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE601); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00E2); // DCSCMD_Q
    // SETDISP
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0007); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B2); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x04C8); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0066); // DCSCMD_Q
    // INVOFF
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0020); // DCSCMD_Q
    // MADCTL
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0036); // DCSCMD_Q
    // COLMOD
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x703A); // DCSCMD_Q
    // SETCYC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x001F); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B4); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3204); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1032); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3200); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0810); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0127); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0353); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0137); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0153); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3030); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0101); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x6161); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x06BF); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00C7); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x08C6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0008); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0CC0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    // SETGIP
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0021); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00D5); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0A00); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0100); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0033); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3300); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5432); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1076); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8832); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9999); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5499); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8876); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0088); // DCSCMD_Q
    // SETDGC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0080); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x01C1); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0600); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x160E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x261E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x362E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x463E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x564E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x665E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x766E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x867E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x968E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xA69E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xB6AE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xC6BE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xD6CE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE6DE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xF6EE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00FE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0300); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x130B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x231B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x332B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x433B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x534B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x635B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x736B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x837B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x938B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xA39B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xB3AB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xC3BB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xD3CB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE3DB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xF3EB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00FB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1008); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1E18); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3E36); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x4E46); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5E56); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x6E66); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x7E76); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8E86); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9E96); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xAEA6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xBEB6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xCEC6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xDED6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xEDE6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00F5); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    // SETGAMMA
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x002B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00E0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1D12); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1334); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x042A); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x120C); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1916); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1616); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x110E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1800); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3F24); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2C16); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0D04); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1610); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1618); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1016); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0711); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0616); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x080F); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0716); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    // SETCABC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x000A); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0FC9); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1E00); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x001E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3E01); // DCSCMD_Q
    // WRDDISBV
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q
    // WRCTRLD
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0053); // DCSCMD_Q
    // SETVDC
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x07BC); // DCSCMD_Q
    Waitx1ms(5);
    // SETPANEL
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x09CC); // DCSCMD_Q
    Waitx1ms(50);
    // SETMIPI
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x03BA); // DCSCMD_Q
    // SLEEP OUT
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
    Waitx1ms(200);
    // DISPON
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
    Waitx1ms(600);
    // Split Control
    i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
    i2c2_uh2cd_write16(0x500C,0x0000); // STX0_FPX
    i2c2_uh2cd_write16(0x500E,0x02CF); // STX0_LPX
    i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
    i2c2_uh2cd_write16(0x508C,0x0000); // STX1_FPX
    i2c2_uh2cd_write16(0x508E,0x02CF); // STX1_LPX
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
    i2c2_uh2cd_write16(0x0004,0x0C35); // ConfCtl0
    i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
    // Command Transmission After Video Start.
    i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
}

void DDC5V_Noinput(){
    // Software Reset
    i2c2_uh2cd_write16(0x0004,0x0004); // ConfCtl0
    i2c2_uh2cd_write16(0x0002,0x3F00); // SysCtl
    i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
    i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
    i2c2_uh2cd_write16(0x7000,0x0009); // CB_CTL
    // DSI-TX1 Transition Timing
    // DSI-TX0 Transition Timing
    i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
    i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
    i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x02AC,0x00001425); // MIPI_PLL_CNF
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
    i2c2_uh2cd_write32(0x0170,0x00000339); // APF_VDELAYCNT
    i2c2_uh2cd_write32(0x017C,0x00000080); // DSI_TX_MODE
    i2c2_uh2cd_write32(0x018C,0x0000000A); // DSI_HSYNC_WIDTH
    i2c2_uh2cd_write32(0x0190,0x00000046); // DSI_HBPR
    i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
    i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
    i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
    i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
    i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
    i2c2_uh2cd_write32(0x0254,0x00000002); // LPTXTIMECNT
    i2c2_uh2cd_write32(0x0258,0x00120002); // TCLK_HEADERCNT
    i2c2_uh2cd_write32(0x025C,0x00050002); // TCLK_TRAILCNT
    i2c2_uh2cd_write32(0x0260,0x00030003); // THS_HEADERCNT
    i2c2_uh2cd_write32(0x0264,0x00004A38); // TWAKEUPCNT
    i2c2_uh2cd_write32(0x0268,0x00000008); // TCLK_POSTCNT
    i2c2_uh2cd_write32(0x026C,0x00050004); // THS_TRAILCNT
    i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
    i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
    i2c2_uh2cd_write32(0x0278,0x00020001); // BTA_COUNT
    i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
    i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
    // Command Transmission Before Video Start
    i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
    i2c2_uh2cd_write32(0x0110,0x00000016); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000016); // MODE_CONFIG

    //Turner_LCD_Reset();
    // LCD Initialization
    // SETEXTC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xFFB9); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9483); // DCSCMD_Q
    // SETPOWER
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x7CB1); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2400); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0106); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1D1D); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1257); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE601); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00E2); // DCSCMD_Q
    // SETDISP
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0007); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B2); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x04C8); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0066); // DCSCMD_Q
    // INVOFF
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0020); // DCSCMD_Q
    // MADCTL
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0036); // DCSCMD_Q
    // COLMOD
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x703A); // DCSCMD_Q
    // SETCYC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x001F); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B4); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3204); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1032); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3200); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0810); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0127); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0353); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0137); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0153); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3030); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0101); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0143); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x6161); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0001); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x06BF); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1002); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0004); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00C7); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x08C6); // DCSCMD_Q  
    i2c2_uh2cd_write16(0x0504,0x0008); // DCSCMD_Q
    // Not open
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0003); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0CC0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    // SETGIP
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0021); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00D5); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0A00); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0100); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0033); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3300); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5432); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1076); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8832); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8888); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9999); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5499); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8876); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0088); // DCSCMD_Q
    // SETDGC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0080); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x01C1); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0600); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x160E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x261E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x362E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x463E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x564E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x665E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x766E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x867E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x968E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xA69E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xB6AE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xC6BE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xD6CE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE6DE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xF6EE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00FE); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0300); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x130B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x231B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x332B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x433B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x534B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x635B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x736B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x837B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x938B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xA39B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xB3AB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xC3BB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xD3CB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xE3DB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xF3EB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00FB); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1008); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1E18); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2E26); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3E36); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x4E46); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x5E56); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x6E66); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x7E76); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x8E86); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x9E96); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xAEA6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xBEB6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xCEC6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xDED6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xEDE6); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00F5); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    // SETGAMMA
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x002B); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00E0); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1D12); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1334); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x042A); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x120C); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1916); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1616); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x110E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1800); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3F24); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x2C16); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0D04); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1610); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1618); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1016); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0711); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0616); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x080F); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0716); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0010); // DCSCMD_Q
    // SETCABC
    i2c2_uh2cd_write16(0x0504,0x8039); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x000A); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0FC9); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x1E00); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x001E); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0000); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x3E01); // DCSCMD_Q
    // WRDDISBV
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0xFF51); // DCSCMD_Q
    // WRCTRLD
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0053); // DCSCMD_Q
    // SETVDC
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x07BC); // DCSCMD_Q
    Waitx1ms(5);
    // SETPANEL
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x09CC); // DCSCMD_Q
    Waitx1ms(50);
    // SETMIPI
    i2c2_uh2cd_write16(0x0504,0x0015); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x03BA); // DCSCMD_Q
    // SLEEP OUT
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0011); // DCSCMD_Q
    Waitx1ms(200);
    // DISPON
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
    Waitx1ms(600);
    // Split Control
    i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
    i2c2_uh2cd_write16(0x500C,0x8000); // STX0_FPX
    i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
    // Color Bar Setting
    i2c2_uh2cd_write16(0x7008,0x0500); // CB_HSW
    i2c2_uh2cd_write16(0x700A,0x0003); // CB_VSW
    i2c2_uh2cd_write16(0x700C,0x0D2B); // CB_Htotal
    i2c2_uh2cd_write16(0x700E,0x050C); // CB_Vtotal
    i2c2_uh2cd_write16(0x7010,0x02D0); // CB_Hact
    i2c2_uh2cd_write16(0x7012,0x0500); // CB_Vact
    i2c2_uh2cd_write16(0x7014,0x0A00); // CB_Hstart
    i2c2_uh2cd_write16(0x7016,0x0006); // CB_Vstart
    i2c2_uh2cd_write16(0x7000,0x0005); // CB_CTL
    // Start Video TX
    i2c2_uh2cd_write16(0x0004,0x0C35); // ConfCtl0
    // Command Transmission After Video Start. HS command TX
    i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
    // MCAP
    i2c2_uh2cd_write16(0x0504,0x0023); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x00B0); // DCSCMD_Q
    Waitx1ms(32);
    // Interface Setting
    i2c2_uh2cd_write16(0x0504,0x0023); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x14B3); // DCSCMD_Q
    Waitx1ms(32);
    // MCAP
    i2c2_uh2cd_write16(0x0504,0x0023); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x03B0); // DCSCMD_Q
    Waitx1ms(32);
    // Set Display On
    i2c2_uh2cd_write16(0x0504,0x0005); // DCSCMD_Q
    i2c2_uh2cd_write16(0x0504,0x0029); // DCSCMD_Q
    Waitx1ms(32);

    // Auto Disp Off(RS_DO)
    // Software Reset
    i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
    i2c2_uh2cd_write16(0x0006,0x0008); // ConfCtl1
    i2c2_uh2cd_write16(0x0002,0x1200); // SysCtl
    i2c2_uh2cd_write16(0x0002,0x0000); // SysCtl
    i2c2_uh2cd_write16(0x0006,0x0000); // ConfCtl1
    i2c2_uh2cd_write16(0x7000,0x0009); // CB_CTL
    // DSI-TX1 Transition Timing
    // DSI-TX0 Transition Timing
    i2c2_uh2cd_write32(0x0108,0x00000001); // DSI_TX_CLKEN
    i2c2_uh2cd_write32(0x010C,0x00000001); // DSI_TX_CLKSEL
    i2c2_uh2cd_write32(0x02A0,0x00000001); // MIPI_PLL_CONTROL
    i2c2_uh2cd_write32(0x02AC,0x00001425); // MIPI_PLL_CNF
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
    i2c2_uh2cd_write32(0x0170,0x000002BB); // APF_VDELAYCNT
    i2c2_uh2cd_write32(0x017C,0x00000081); // DSI_TX_MODE
    i2c2_uh2cd_write32(0x018C,0x0000000F); // DSI_HSYNC_WIDTH
    i2c2_uh2cd_write32(0x0190,0x00000055); // DSI_HBPR
    i2c2_uh2cd_write32(0x01A4,0x00000000); // DSI_RX_STATE_INT_MASK
    i2c2_uh2cd_write32(0x01C0,0x00000015); // DSI_LPRX_THRESH_COUNT
    i2c2_uh2cd_write32(0x0214,0x00000000); // APP_SIDE_ERR_INT_MASK
    i2c2_uh2cd_write32(0x021C,0x00000080); // DSI_RX_ERR_INT_MASK
    i2c2_uh2cd_write32(0x0224,0x00000000); // DSI_LPTX_INT_MASK
    i2c2_uh2cd_write32(0x0254,0x00000002); // LPTXTIMECNT
    i2c2_uh2cd_write32(0x0258,0x00120002); // TCLK_HEADERCNT
    i2c2_uh2cd_write32(0x025C,0x00050002); // TCLK_TRAILCNT
    i2c2_uh2cd_write32(0x0260,0x00030003); // THS_HEADERCNT
    i2c2_uh2cd_write32(0x0264,0x00004A38); // TWAKEUPCNT
    i2c2_uh2cd_write32(0x0268,0x00000008); // TCLK_POSTCNT
    i2c2_uh2cd_write32(0x026C,0x00050004); // THS_TRAILCNT
    i2c2_uh2cd_write32(0x0270,0x00000020); // HSTXVREGCNT
    i2c2_uh2cd_write32(0x0274,0x0000001F); // HSTXVREGEN
    i2c2_uh2cd_write32(0x0278,0x00020001); // BTA_COUNT
    i2c2_uh2cd_write32(0x027C,0x00000002); // DPHY_TX ADJUST
    i2c2_uh2cd_write32(0x011C,0x00000001); // DSITX_START
    // Command Transmission Before Video Start
    i2c2_uh2cd_write16(0x0500,0x0000); // CMD_SEL
    // Split Control
    i2c2_uh2cd_write16(0x5000,0x0000); // STX0_CTL
    i2c2_uh2cd_write16(0x500C,0x8000); // STX0_FPX
    i2c2_uh2cd_write16(0x5080,0x0000); // STX1_CTL
    // Color Bar Setting
    i2c2_uh2cd_write16(0x7008,0x0020); // CB_HSW
    i2c2_uh2cd_write16(0x700A,0x0003); // CB_VSW
    i2c2_uh2cd_write16(0x700C,0x0380); // CB_Htotal
    i2c2_uh2cd_write16(0x700E,0x050C); // CB_Vtotal
    i2c2_uh2cd_write16(0x7010,0x02D0); // CB_Hact
    i2c2_uh2cd_write16(0x7012,0x0500); // CB_Vact
    i2c2_uh2cd_write16(0x7014,0x0055); // CB_Hstart
    i2c2_uh2cd_write16(0x7016,0x0006); // CB_Vstart
    i2c2_uh2cd_write16(0x7000,0x0007); // CB_CTL
    // Start Video TX
    i2c2_uh2cd_write16(0x0004,0x0C35); // ConfCtl0
    // Command Transmission After Video Start. HS command TX
    i2c2_uh2cd_write32(0x0110,0x00000006); // MODE_CONFIG
    i2c2_uh2cd_write32(0x0310,0x00000006); // MODE_CONFIG
    i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
    i2c2_uh2cd_write16(0x7000,0x0000); // CB_CTL
    // MIPI Output Disable(RS4)
    // Reset Display by H/W reset
    // Stop CSI output
    i2c2_uh2cd_write16(0x0004,0x0C14); // ConfCtl0
    // Enable Interrupt
    i2c2_uh2cd_write16(0x0016,0x0D3F); // IntMask
}