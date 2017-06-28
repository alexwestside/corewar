#include "corewar.h"

void		valid(char **text, t_corewar *corewar)
{
	ft_name_comment(&corewar->bot.name, &corewar->bot.comment, text);
	corewar->bot = ft_command(text);
}