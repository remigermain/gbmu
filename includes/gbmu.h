#ifndef GBMU_H
# define GBMU_H
# include <fcntl.h>
# include "libft.h"
# include "gbmu_enum.h"
# define STACK_MEM  0xFFFF
# define TAB_ASCII " !\"#$%&\'()*+,-./.0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_"

/*
**-------------------------------------------------------
**          header from rom
**-------------------------------------------------------
*/

struct s_rom_header
{
    unsigned char   unk[256];
    unsigned short  magic;
    unsigned short  start_add;
    unsigned char   data[48];
    unsigned char   title[11];
    unsigned int    game_code;
    unsigned char   support_code;
    unsigned short  maker_code;
    unsigned char   sgb_support_code;
    unsigned char   cassette_type;
    unsigned char   rom_size;
    unsigned char   ram_size;
    unsigned char   destination;
    unsigned char   type33;
    unsigned char   mask_rom_version;
    unsigned char   complement_check;
    unsigned short  checksum;
}__attribute__((packed));

typedef struct s_rom_header t_rom_header;

typedef struct s_gbmu
{
    t_rom_header    rom;
    unsigned char   reg[8];
    unsigned        pc : 16;
    unsigned        sp : 16;
    unsigned char   area[STACK_MEM];
}               t_gbmu;
/*
**-------------------------------------------------------
**          read_rom.c
**-------------------------------------------------------
*/
void    read_rom(t_gbmu *st);

/*
**-------------------------------------------------------
**          modifier_register.c
**-------------------------------------------------------
*/
void    set_register_flag(t_gbmu *st, int result, enum e_mod_flag mod);

/*
**-------------------------------------------------------
**          utils.c
**-------------------------------------------------------
*/
void    gbmu_error(t_gbmu *st, char *str);

/*
**-------------------------------------------------------
**         deubg.c
**-------------------------------------------------------
*/
void    rom_information(t_gbmu *st);

#endif
