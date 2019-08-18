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
    STAT_MODE,

    SCY_ADD = 0xFF42,
    SCX_ADD = 0xFF43,
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





#endif
