#ifndef COREWAR_H
# define COREWAR_H
# define HASH_TABLE_SIZE sizeof(t_has_table)
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
#include "op.h"

typedef struct			s_args
{
	int 				arg_type;
	char				*data;
}						t_args;

typedef struct			s_command
{
	char				*method;
	char 				*command_name;
	t_args				arg[3];
	int					count_args;
	struct s_command	*next;
}						t_command;

typedef struct			s_hash_table
{
	char 				*lable;
	t_command			*command;
	struct s_hash_table	*collision;
}						t_hash_table;

typedef struct			s_bot
{
	char 				*name;
	char 				*comment;
	t_hash_table 		**hash_table;
	unsigned int		*keys;
	t_command			*command;
}						t_bot;

typedef struct			s_corewar
{
	t_bot				bot;
	int					registrs[16];
}						t_corewar;

#endif
