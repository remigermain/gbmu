#include "gbmu.h"

int main(int ac, char **av)
{
	if (init_flags(av, "c|r {char*{,,*.gb}};;|v {int {0,32}};;|", "rom;r|verbose;v|step;c|", 0) >= 0)
	{
		ft_printf("start\n");
	}
	return (0);
}
