#include "gbmu.h"

int main(int ac, char **av)
{
	t_gbmu st;

	(void)ac;
	ft_bzero(&st, sizeof(t_gbmu));
	if (init_flags(av, "ci|r {char*{,, *.gb | *.gbc }};;|v {int {0,32}};;|", "rom;r|verbose;v|step;c|info;i|", 0) >= 0)
	{
		print_flags();
		//read_rom(&st);
	}
	return (0);
}
