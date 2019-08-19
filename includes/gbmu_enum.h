#ifndef GBMU_ENUM_H
#define GBMU_ENUM_H

/*
**-------------------------------------------------------
**          MEMORY MAP
**-------------------------------------------------------
*/

enum e_memory
{
    GB_RST_START = 0x000,
    GB_RST_END = 0x0FF,
    GB_ROM_START = 0x100,
    GB_ROM_END = 0x14F,
    GB_USER = 0x150,
    GB_LCD_START = 0x8000,
    GB_LCD_END = 0x9FFF,
    GB_EXT_RAM_START = 0xA000,
    GB_EXT_RAM_END = 0xBFFF,
    GB_RAM_START  = 0xC000,
    GB_RAM_END  = 0xDFFF,
    GB_CPU_RAM_START = 0xFE00,
    GB_CPU_RAM_END = 0xFFFF,
    GB_AREA_PROHIB_START = 0xE000,
    GB_AREA_PROHIB_END = 0xFDFF,
    GB_OAM_RAM_START = 0xFE00,
    GB_OAM_RAM_END = 0xFE9F,
    GB_SYS_CONTROL_START = 0xFF00,
    GB_SYS_CONTROL_END = 0xFF7F,
    GB_STACK_RAM_START = 0xFF80,
    GB_STACK_RAM_END = 0xFFFE,
};

/*
**--------------------------------
**           MEMORY DMG
**--------------------------------
*/

enum e_memory_dmg
{
    DMG_LCD_BANK_START = 0x800,
    DMG_LCD_BANK_END= 0x9FFF,
    DMG_UWRAM_START = 0xC000,
    DMG_UWRAM_END = 0xDFFF,
};

/*
**--------------------------------
**           MEMORY CGB
**--------------------------------
*/

enum e_memory_color
{
    CGB_DISPLAY_DATA1_START = 0x9800,
    CGB_DISPLAY_DATA1_END = 0x9BFF,
    CGB_DISPLAY_DATA2_START = 0x9C00,
    CGB_DISPLAY_DATA2_END = 0x9FFF,
    CGB_UWRAM_BANK0_START = 0xC000,
    CGB_UWRAM_BANK0_END = 0xEFFF,
    CGB_UWRAM_BANK17_START = 0xD000,
    CGB_UWRAM_BANK17_END = 0xDFFF,
};

/*
**-------------------------------------------------------
**          CPU FUNCTIONS (COMMON TO DMG/CGB)
**-------------------------------------------------------
*/

/*
**--------------------------------
**           Controller Data
**--------------------------------
*/

enum e_input_ports
{
    P1_ADD = 0xFF00,
    P10 = 0b1,
    P11 = 0b10,
    P12 = 0b100,
    P13 = 0b1000,
    P14 = 0b10000,
    P15 = 0b100000,
};

enum e_controller
{
    KEY_RIGHT = P14 | P10,
    KEY_LEFT = P14 | P11,
    KEY_UP = P14 | P12,
    KEY_DOWN = P14 | P13,
    KEY_A = P15 | P10,
    KEY_B = P15 | P11,
    KEY_SELECT = P15 | P12,
    KEY_START = P15 | P13,
};

/*
**--------------------------------
**          Divider Registers
**--------------------------------
*/

enum e_divider_reg
{
    DV_ADD = 0xFF04,
};

/*
**--------------------------------
**           Timer Registers
**--------------------------------
*/

enum e_timer_reg
{
    TIMA_ADD = 0xFF05,
    TMA_ADD = 0xFF06,
    TAC_ADD = 0xFF07,
    TAC_CLOCK_SELECT = 0b1,
    TAC_TIMER_STOP = 0b100,
};

/*
**--------------------------------
**           Interrupt Flags
**--------------------------------
*/

enum e_interrupt_flags
{
    IF_ADD = 0xFF0F,
    IE_ADD = 0xFFFF,
    V_BLANK = 0b1,
    LCDC = 0b10,
    TIMER_OVERFLOW = 0b100,
    SERIAL_IO_TRANSFER = 0b1000,
    P10_P13_TERMINAL_NEG = 0b10000,
};

/*
**--------------------------------
**     Serial Cable Communication
**--------------------------------
*/

enum e_serial_cable_comunitation
{
    SB_ADD = 0xFF01,
    SC_ADD = 0xFF02,
    SCK_TERMINAL_IO = 0b1,
    SHIFT_CLOCK_SWITCHING = 0b10,
    SERIAL_TRANSFER_FLAG = 0b10000000,
};

/*
**-------------------------------------------------------
**          CPU FUNCTIONS (CGB ONLY)
**-------------------------------------------------------
*/

/*
**--------------------------------
**    Bank Register for Game Boy Working RAM
**--------------------------------
*/

enum e_bank_reg_w_ram
{
    SVBK_ADD = 0xFF70,
};

/*
**--------------------------------
**            CPU Operating Speed
**--------------------------------
*/

enum e_cpu_operating_speed
{
    KEY1_ADD = 0xFF4D,
    SPEDD_FLAG_SWITCH = 0b1,
    SPEED_FLAG = 0b10000000,
};

/*
**--------------------------------
**           Infrared Communication
**--------------------------------
*/

enum e_infrared_com
{
    RP_ADD = 0xFF56,
    RP_W_LED = 0b1,
    RP_R_LED = 0b10,
    RP_LED_FLAG = 0b11000000,
};

/*
**-------------------------------------------------------
**          DISPLAY FUNCTIONS
**-------------------------------------------------------
*/

/*
**--------------------------------
**           LCD Display Registers
**--------------------------------
*/

enum e_lcd_common
{
    LCDC_ADD = 0xFF40,
    LCDC_MODE = 0b1,
    LCDC_OBJ_FLAG = 0b10,
    LCDC_OBJ_BLOCK = 0b100,
    LCDC_BG_CODE_SELECT = 0b1000,
    LCDC_BG_CHAR = 0b10000,
    LCDC_WINDOWING = 0b100000,
    LCDC_WINDO_CDE_SELECT = 0b1000000,
    LCDC_CONTROLLER = 0b10000000,

    STAT_ADD = 0xFF41,
    STAT_MODE_FLAG = 0b11,
    STAT_MATCH_FLAG = 0b100,
    STAT_INTERRUPT = 0b1111000,

    SCY_ADD = 0xFF42,
    SCX_ADD = 0xFF43,

    LY_ADD = 0xFF44,
    LYC_ADD = 0xFF45,

    WY_ADD = 0xFF4A,
    WX_ADD = 0xFF4B,

};

enum e_lcd_dmg
{
    ICI_PAGE_55,
};

enum e_lcd_cgb
{
    VBK_ADD = 0xFF4F,
    VBK_BANK = 0b1,
    COLOR_PAL = 0b111,
    CGAR_BANK = 0b1000,
    LR_FLIP_FLAG = 0b100000,
    UD_FLIP_FLAG = 0b1000000,
    VBK_PRIORITY_FLAG = 0b10000000,
};

/*
**--------------------------------
**           OAM Register
**--------------------------------
*/

enum e_oam_register
{
    OBJO_LCD_Y_ADD = 0xFE00,
    OBJO_LCD_X_ADD = 0xFE01,
    OBJO_CHR_CODE_ADD = 0xFE02,
    OBJO_ATTRIBUTE_FLAG = 0xFE03,
};

/*
**-------------------------------------------------------
**          DMA Registers
**-------------------------------------------------------
*/

/*
**--------------------------------
**         DMA Transfers in DMG
**--------------------------------
*/

enum e_dma_transfers_dmg
{
    EMPTY,
};

enum e_dma_control_register_cgb
{
    HDMA5_ADD = 0XFF55,
};

enum e_dma_transfers_common
{
    DMA_ADD = 0xFF46,   
};

/*
**-------------------------------------------------------
**          LCD COLOR DISPLAY (CGB ONLY)
**-------------------------------------------------------
*/

/*
**--------------------------------
**         Color Palettes
**--------------------------------
*/

enum e_color_palette
{
    COLOR_PALETTE_L = 0b11111111,
    COLOR_PALETTE_H = 0b11111111,
    RED_COLOR_ADD = 0b11111,
    GREEN_COLOR_ADD = 0b1111100000,
    BLUE_COLOR_ADD = 0b111110000000000,
};

/*
**--------------------------------
**           Writing Data to a Color Palette
**--------------------------------
*/

enum e_write_color_palette
{
    BCPS_ADD = 0xFF68,
    BCPD_ADD = 0xFF69,
    OCPS_ADD = 0xFF6A,
    OCPD_ADD = 0xFF6B,
};

/*
**-------------------------------------------------------
**          SOUND FUNCTIONS
**-------------------------------------------------------
*/

/*
**-------------------------------------------------------
**          SOUND CONTROL REGISTERS
**-------------------------------------------------------
*/

/*
**--------------------------------
**         Sound 1 Mode Registers
**--------------------------------
*/

enum e_sound1_mode_reg
{
    NR10_ADD = 0xFF10,
    NR11_ADD = 0xFF11,
    NR12_ADD = 0xFF12,
    NR13_ADD = 0xFF13,
    NR14_ADD = 0xFF14,
};

/*
**--------------------------------
**         Sound 2 Mode Registers
**--------------------------------
*/

enum e_soud2_mode_reg
{
    NR21_ADD = 0xFF16,
    NR22_ADD = 0xFF17,
    NR23_ADD = 0xFF18,
    NR24_ADD = 0xFF19,
};

/*
**--------------------------------
**         Sound 3 Mode Registers
**--------------------------------
*/

enum e_soud3_mode_reg
{
    NR30_ADD = 0xFF1A,
    NR31_ADD = 0xFF1B,
    NR32_ADD = 0xFF1C,
    NR33_ADD = 0xFF1D,
    NR34_ADD = 0xFF1E,
};

/*
**--------------------------------
**          Sound 4 Mode Registers
**--------------------------------
*/

enum e_soud4_mode_reg
{
    NR41_ADD = 0xFF20,
    NR42_ADD = 0xFF21,
    NR43_ADD = 0xFF22,
    NR44_ADD = 0xFF23,
};

/*
**--------------------------------
**          Sound Control Registers
**--------------------------------
*/

enum e_sound_control_reg
{
    NR50_ADD = 0xFF24,
    NR51_ADD = 0xFF25,
    NR52_ADD = 0xFF26,
};

/*
**-------------------------------------------------------
**          CPU INSTRUCTION SET
**-------------------------------------------------------
*/

enum e_register
{
  REG_A = 0,
  REG_B,
  REG_C,
  REG_D,
  REG_E,
  REG_F,
  REG_G,
  REG_H,
};

enum e_mod_flag
{
    FLAG_Z,
    FLAG_N,
    FLAG_H,
    FLAG_CY,
};

/*
**-------------------------------------------------------
**          SYSTEM COMMANDS
**-------------------------------------------------------
*/

enum e_sys_cmd
{
    PAL01 = 0x00,
    PAL23 = 0x01,
    PAL03 = 0x02,
    PAL12 = 0x03,
    ATTR_BLK = 0x04,
    ATTR_LIN = 0x05,
    ATTR_DIV = 0x06,
    ATTR_CHR = 0x07,
    SOUND = 0x08,
    SOU_TRN = 0x9,
    PAL_SET = 0x0A,
    PAL_TRN = 0x0B,
    ATRC_EN = 0x0C,
    ICON_EN = 0x0E,
    PROHIBITED_1 = 0x0D,
    DATA_SND = 0x0F,
    DATA_TRN = 10,
    MLT_REQ = 11,
    JUMP = 12,
    CHR_TRN = 13,
    PCT_TRN = 14,
    ATTR_TRN = 15,
    ATTR_SET = 16,
    MASK_EN = 17,
    PROHIBITED_2 = 18,
    PAL_PRI = 19,
};

/*
**-------------------------------------------------------
**          Sound Effect
**-------------------------------------------------------
*/

enum e_effect_a_flags
{

    JUMP_SOUND = 0x17,
    FAST_JUMO = 0x18,
    JET_FIRING = 0x19,
    JET_LANDING = 0x1A,
    CUP_BREAKING = 0x1B,
    GLASS_BREAKING = 0x1C,
    LEVEL_UP = 0x1D,
    AIR_INJECTION = 0x1E,
    SWORD_WIELDING = 0x1F,
    FAILLING_IN_WATER = 0x20,
    FIRE_A = 0x21,
    BREAKING_WALL = 0x22,
    CANCELLATION_SOUND = 0x23,
    STEPPING = 0x24,
    BLOCK_HITTING_SOUND = 0x25,
    SOUND_PICTURE_FLOATING_VIEW = 0x26,
    SCREEN_FADE_IN = 0x27,
    SCREEN_FADE_OUT = 0x28,
    WINDOW_OPENING = 0x29,
    WINDOW_CLOSING = 0x2A,
    LARGE_LASER_SOUND = 0x2B,
    SOUND_STRONE_DOOR_CLOSING = 0x2C,
    TELEPORTATION = 0x2D,
    THUNDER_A = 0x2E,
    EARTHQUAKE_A = 0x2F,
    SMALL_LASER_SOUND = 0x30,



};

enum e_effect_b_flags
{
    DUMMY_FLAG_RETRIGGERING = 0x00,
    SOUND_EFFECT_B_STOP = 0x80,
    APPLAUSE_SMALL = 0x01,
    APPLAUSE_MEDIUM = 0x02,
    APPLAUSE_LARGE = 0x03,
    WIND = 0x04,
    RAIN = 0x05,
    STORM = 0x06,
    HURRICANE = 0x07,
    THUNDER_B = 0x08,
    EARTHQUAKE_B = 0x09,
    LAVAL_FLOW = 0x0A,
    WAVE = 0x0B,
    RIVER = 0x0C,
    WATERFALL = 0x0D,
    SMALL_CHARACTER_RUNNING = 0x0E,
    HORSE_GALLOPING = 0x0F,
    WARNING_SOUND = 0x10,
    FUTURISTIC_CAR_RUNNING = 0x11,
    JET_FLYING = 0x12,
    UFO_FLYING = 0x13,
    ELECTROMAGNETIC_WAVES = 0x14,
    SOUND_SCORE_RAISED = 0x15,
    FIRE = 0x16,
    CAMERA_SHUTTER_FORMANT = 0x17,
    WRITING_FORMANT = 0x18,
    ERASING_FORMANT = 0x19,
};


/*
**-------------------------------------------------------
**          Sound Effect
**-------------------------------------------------------
*/

#endif
