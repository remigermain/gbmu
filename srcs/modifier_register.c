#include "gbmu.h"

void    set_register_flag(t_gbmu *st, int result, enum e_mod_flag mod)
{
    if (mod & FLAG_Z)
    {
        if (result == 0)
            st->reg[REG_F] |= FLAG_Z;
    }
    if (mod & FLAG_N)
    {
        st->reg[REG_F] |= FLAG_N;
    }
    if (mod & FLAG_H)
    {
        if (result & 0b1000)
            st->reg[REG_F] |= FLAG_H;
    }
    if (mod & FLAG_CY)
    {
        if (result & 0b10000000)
            st->reg[REG_F] |= FLAG_CY;
    }
}
