#include "gbmu.h"

void    gbmu_error(t_gbmu *st, char *str)
{
    (void)st;
    error_line(str);
    exit(EXIT_FAILURE);
}

void    reverse_byts(unsigned char *byts, int size)
{
    unsigned char   tmp;
    int             mem;

    mem = size;
    while (size-- > mem / 2)
    {
        tmp = byts[size];
        byts[size] = byts[mem - size];
        byts[mem - size] = tmp;
    }
}
