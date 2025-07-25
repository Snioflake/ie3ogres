#ifndef NITRO_HW_MMAP_GLOBAL_H_
#define NITRO_HW_MMAP_GLOBAL_H_

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// GLOBAL MEMORY MAP
//---------------------------------------------------------------------------

//----------------------------- ITCM
#define HW_ITCM_IMAGE           0x01000000
#define HW_ITCM                 0x01ff8000
#define HW_ITCM_SIZE            0x8000
#define HW_ITCM_END             (HW_ITCM + HW_ITCM_SIZE)

//----------------------------- DTCM
#ifndef SDK_ASM
#include <nitro/types.h>
extern u32 SDK_AUTOLOAD_DTCM_START[];
#define HW_DTCM                 ((u32)SDK_AUTOLOAD_DTCM_START)
#else // SDK_ASM
.extern SDK_AUTOLOAD_DTCM_START
#define HW_DTCM                 SDK_AUTOLOAD_DTCM_START
#endif // SDK_ASM
#define HW_DTCM_SIZE            0x4000
#define HW_DTCM_END             (HW_DTCM + HW_DTCM_SIZE)
//----------------------------- MAIN
#define HW_MAIN_MEM             0x02000000
#define HW_MAIN_MEM_SIZE        0x00400000
#define HW_MAIN_MEM_EX_SIZE     0x00800000
#define HW_MAIN_MEM_END         (HW_MAIN_MEM + HW_MAIN_MEM_SIZE)
#define HW_MAIN_MEM_EX_END      (HW_MAIN_MEM + HW_MAIN_MEM_EX_SIZE)
//----------------------------- WRAMs
#define HW_WRAM                 0x037f8000
#define HW_WRAM_END             0x03800000
#define HW_WRAM_SIZE            (HW_WRAM_END-HW_WRAM)
//----------------------------- IOs
#define HW_IOREG                0x04000000
#define HW_IOREG_END            0x05000000
#define HW_REG_BASE             HW_IOREG        // alias
//----------------------------- VRAMs
#define HW_BG_PLTT              0x05000000
#define HW_BG_PLTT_END          0x05000200
#define HW_BG_PLTT_SIZE         (HW_BG_PLTT_END-HW_BG_PLTT)
#define HW_OBJ_PLTT             0x05000200
#define HW_OBJ_PLTT_END         0x05000400
#define HW_OBJ_PLTT_SIZE        (HW_OBJ_PLTT_END-HW_OBJ_PLTT)
#define HW_PLTT                 HW_BG_PLTT
#define HW_PLTT_END             HW_OBJ_PLTT_END
#define HW_PLTT_SIZE            (HW_PLTT_END-HW_PLTT)
#define HW_DB_BG_PLTT           0x05000400
#define HW_DB_BG_PLTT_END       0x05000600
#define HW_DB_BG_PLTT_SIZE      (HW_DB_BG_PLTT_END-HW_DB_BG_PLTT)
#define HW_DB_OBJ_PLTT          0x05000600
#define HW_DB_OBJ_PLTT_END      0x05000800
#define HW_DB_OBJ_PLTT_SIZE     (HW_DB_OBJ_PLTT_END-HW_DB_OBJ_PLTT)
#define HW_DB_PLTT              HW_DB_BG_PLTT
#define HW_DB_PLTT_END          HW_DB_OBJ_PLTT_END
#define HW_DB_PLTT_SIZE         (HW_DB_PLTT_END-HW_DB_PLTT)
#define HW_BG_VRAM              0x06000000
#define HW_BG_VRAM_END          0x06080000
#define HW_BG_VRAM_SIZE         (HW_BG_VRAM_END-HW_BG_VRAM)
#define HW_DB_BG_VRAM           0x06200000
#define HW_DB_BG_VRAM_END       0x06220000
#define HW_DB_BG_VRAM_SIZE      (HW_DB_BG_VRAM_END-HW_DB_BG_VRAM)
#define HW_OBJ_VRAM             0x06400000
#define HW_OBJ_VRAM_END         0x06440000
#define HW_OBJ_VRAM_SIZE        (HW_OBJ_VRAM_END-HW_OBJ_VRAM)
#define HW_DB_OBJ_VRAM          0x06600000
#define HW_DB_OBJ_VRAM_END      0x06620000
#define HW_DB_OBJ_VRAM_SIZE     (HW_DB_OBJ_VRAM_END-HW_DB_OBJ_VRAM)
#define HW_LCDC_VRAM            0x06800000
#ifdef SDK_TS
#define HW_LCDC_VRAM_END        0x068A4000
#else
#define HW_LCDC_VRAM_END        0x06898000
#endif
#define HW_LCDC_VRAM_SIZE       (HW_LCDC_VRAM_END-HW_LCDC_VRAM)
#define HW_OAM                  0x07000000
#define HW_OAM_END              0x07000400
#define HW_OAM_SIZE             (HW_OAM_END-HW_OAM)
#define HW_DB_OAM               0x07000400
#define HW_DB_OAM_END           0x07000800
#define HW_DB_OAM_SIZE          (HW_DB_OAM_END-HW_DB_OAM)
//----------------------------- Cartridge Bus
#define HW_CTRDG_ROM            0x08000000
#define HW_CTRDG_ROM_END        0x0a000000
#define HW_CTRDG_RAM            0x0a000000
#define HW_CTRDG_RAM_END        0x0a010000
//----------------------------- System ROM
#define HW_BIOS                 0xffff0000
#define HW_BIOS_END             0xffff8000
#define HW_RESET_VECTOR         0xffff0000
//----------------------------- for request to ARM7
#define HW_EXT_WRAM_ARM7         0x06000000
#define HW_EXT_WRAM_ARM7_END     0x06040000
#define HW_EXT_WRAM_ARM7_SIZE    (HW_EXT_WRAM_ARM7_END-HW_EXT_WRAM_ARM7)

#ifdef __cplusplus
} /* extern "C" */
#endif

/* NITRO_HW_MMAP_GLOBAL_H_ */
#endif
