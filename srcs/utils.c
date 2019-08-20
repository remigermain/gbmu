#include "gbmu.h"

void    gbmu_error(t_gbmu *st, char *str)
{
    (void)st;
    error_line(str);
    exit(EXIT_FAILURE);
}

