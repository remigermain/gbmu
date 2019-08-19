#include "gbmu.h"

void    rom_information(t_gbmu *st)
{
    ft_printf("\n[ ROM INFORMATION ]\n");
    ft_printf("magic : %.2x", ((unsigned char*)&st->rom.magic)[0]);
    ft_printf(" %.2x\n", ((unsigned char*)&st->rom.magic)[1]);
    ft_printf("title : %.11s\n", st->rom.title);
    ft_printf("gamecode : %hhd\n", st->rom.game_code);
    ft_printf("support code : %hhd\n", st->rom.support_code);
    ft_printf("maker cde : %d\n", st->rom.maker_code);
    ft_printf("sgb support code : %hhd\n", st->rom.sgb_support_code);
    ft_printf("cassette type : %hhd\n", st->rom.cassette_type);
    ft_printf("rom size : %hhd\n", st->rom.rom_size);
    ft_printf("ram size : %hhd\n", st->rom.ram_size);
    ft_printf("destination code : %hhd\n", st->rom.destination);
    ft_printf("33type : %hhd\n", st->rom.type33);
    ft_printf("mask rom verison : %hhd\n", st->rom.mask_rom_version);
    ft_printf("complement check : %hhd\n", st->rom.complement_check);
    ft_printf("checksum : %hx", ((unsigned char*)&st->rom.checksum)[0]);
    ft_printf(" %hx\n", ((unsigned char*)&st->rom.checksum)[0]);
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