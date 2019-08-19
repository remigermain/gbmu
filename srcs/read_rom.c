#include "gbmu.h"

void    reverse_rom(t_gbmu *st)
{
    reverse_byts((unsigned char *)&st->rom.magic, sizeof(st->rom.magic));
    reverse_byts((unsigned char *)&st->rom.start_add, sizeof(st->rom.start_add));
    reverse_byts((unsigned char *)&st->rom.maker_code, sizeof(st->rom.maker_code));
    reverse_byts((unsigned char *)&st->rom.magic, sizeof(st->rom.magic));
    reverse_byts((unsigned char *)&st->rom.checksum, sizeof(st->rom.checksum));
}

void    read_rom(t_gbmu *st)
{
    char    *name;
    int     fd;

    name = NULL;
    if (exist_flags('r'))
        name = get_flags_av('r', 0);
    else
        name = get_flags_av(FLAG_ARGV, 0);
    if ((fd = open(name, O_RDONLY)) > 0)
    {
        if (read(fd, &(st->rom), sizeof(t_rom)) != sizeof(t_rom))
            gbmu_error(st, "header of rom is not good !");
        reverse_rom(st);
        print_memory(&st->rom, sizeof(t_rom));
        if (exist_flags('i'))
            rom_information(st);
        close(fd);
    }
    else
        gbmu_error(st, "can't open file");
}