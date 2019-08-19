#include "gbmu.h"

void    print_type(void *type, int size)
{
    unsigned char   *mem;
    int             i;

    mem = (unsigned char *)type;
    i = 0;
    while (i < size)
        ft_printf("%.2X ", mem[i++]);
    ft_printf("\n");
}

void    rom_information(t_gbmu *st)
{
    ft_printf("\n[ ROM INFORMATION ]\n");
    ft_printf("magic : ");
    print_type(&st->rom.magic, sizeof(st->rom.magic));
    ft_printf("title : %.11s\n", st->rom.title);
    ft_printf("start add LO / HI : ");
    print_type(&st->rom.start_add, sizeof(st->rom.start_add));

    ft_printf("gamecode : ");
    print_type(&st->rom.game_code, sizeof(st->rom.game_code));

    ft_printf("support code : %.2hhx  ", st->rom.support_code);
    if (st->rom.support_code == CGB_INCOMPATIBLE)
        ft_printf("CGB_INCOMPATIBLE\n");
    else if (st->rom.support_code & CGB_COMPATIBLE)
        ft_printf("CGB_COMPATIBLE\n");
    else if (st->rom.support_code & CGB_EXCLUSIVE)
        ft_printf("CGB_EXCLUSIVE\n");
    else
        ft_printf("error\n");

    ft_printf("maker code : ");
    print_type(&st->rom.maker_code, sizeof(st->rom.maker_code));

    ft_printf("sgb support code : %.2hhx ", st->rom.sgb_support_code);
    if (st->rom.sgb_support_code == GB_SUPPORT_CODE)
        ft_printf("GB_SUPPORT_CODE && SGB_SUPPORT_CODE\n");
    else if (st->rom.sgb_support_code & SGB_SUPPORT_CODE)
        ft_printf("SGB_SUPPORT_CODE\n");
    else 
        ft_printf("error\n");

    ft_printf("cassette type : %.2hhx\n", st->rom.cassette_type);

    ft_printf("rom size : %.2hhx ", st->rom.rom_size);
    if (st->rom.rom_size == ROM_SIZE_256K)
        ft_printf("ROM_SIZE_256K\n");
    else if (st->rom.rom_size & ROM_SIZE_512K)
        ft_printf("ROM_SIZE_512K\n");
    else if (st->rom.rom_size & ROM_SIZE_1M)
        ft_printf("ROM_SIZE_1M\n");
    else if (st->rom.rom_size  &ROM_SIZE_2M)
        ft_printf("ROM_SIZE_2M\n");
    else if (st->rom.rom_size & ROM_SIZE_4M)
        ft_printf("ROM_SIZE_4M\n");
    else if (st->rom.rom_size & ROM_SIZE_8M)
        ft_printf("ROM_SIZE_8M\n");
    else if (st->rom.rom_size & ROM_SIZE_16M)
        ft_printf("ROM_SIZE_16M\n");
    else if (st->rom.rom_size & ROM_SIZE_32M)
        ft_printf("ROM_SIZE_32M\n");
    else if (st->rom.rom_size & ROM_SIZE_64M)
        ft_printf("ROM_SIZE_64M\n");
    else
        ft_printf("error\n");

    ft_printf("ram size : %h.2hd ", st->rom.ram_size);
    if (st->rom.ram_size == ROM_RAM_SIZE_MBC2)
        ft_printf("ROM_RAM_SIZE_MBC2\n");
    else if (st->rom.ram_size & ROM_RAM_SIZE_64K)
        ft_printf("ROM_RAM_SIZE_64K\n");
    else if (st->rom.ram_size & ROM_RAM_SIZE_256K)
        ft_printf("ROM_RAM_SIZE_256M\n");
    else if (st->rom.ram_size & ROM_RAM_SIZE_1M)
        ft_printf("ROM_RAM_SIZE_1M\n");

    ft_printf("destination code : %.2hhx ", st->rom.destination);
    if (st->rom.destination == ROM_DES_CODE_JAPAN)
        ft_printf("JAPAN\n");
    else if (st->rom.destination == ROM_DES_CODE_OTHER)
        ft_printf("OTHER\n");
    else
        ft_printf("error\n");
    
    ft_printf("33type : %.2hhx\n", st->rom.type33);

    ft_printf("mask rom verison : %.2hhx\n", st->rom.mask_rom_version);

    ft_printf("complement check : %.2hhx\n", st->rom.complement_check);
    ft_printf("checksum : ");
    print_type(&st->rom.checksum, sizeof(st->rom.checksum));
}

void    print_memory(unsigned char *mem, int size)
{
    int i;

    i = -1;
    while (++i < size)
    {
        if (i % 16 == 0)
            ft_printf("\n0x%.6x ", i);
        if (i % 8 == 0 && i % 16)
            ft_printf(" ");
        ft_printf("%hh.2x ", mem[i]);
    }
    ft_printf("\n");
}