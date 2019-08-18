#ifndef GBMU_H
# define GBMU_H
# include "libft.h"
# include "gbmu_enum.h"
# define STACK_MEM  0xFFFF

typedef struct   s_process
{
    unsigned char reg[5];
}               t_process;

typedef struct s_gbmu
{
    unsigned char   area[STACK_MEM];
}               t_gbmu;
#endif
