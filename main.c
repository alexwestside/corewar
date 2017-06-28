#include "corewar.h"

int 		main(int ac, char **av)
{
	char 	**text;
	t_corewar	corewar;

	text = open_read(av[1]);
	valid(text, &corewar);
}