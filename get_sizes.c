
#include "asm.h"

size_t get_t_dir_size(char *command_name)
{
	size_t size = 0;
	int i = -1;

	while (++i < REG_NUMBER)
	{
		if (!ft_strcmp(command_name, op_tab[i].command_name))
			break;
		i++;
	}
	size = op_tab[i].cod_octal ? 2 : 4;
//	return (op_tab[i].cod_octal ? 4 : 2);
	return (size);
}

int get_size_args(t_command *command)
{
	int size = 0;
	int i = -1;

	while (++i < 3)
	{
		if (command->arg[i].arg_type == DIR_CODE)
			size += get_t_dir_size(command->command_name);
		if (command->arg[i].arg_type == IND_CODE)
			size += 2;
		if (command->arg[i].arg_type == REG_CODE)
			size += 1;
	}
	return (size);
}

size_t get_distance_to_method(char *command_name, /*t_hash_table *hash, */t_corewar * corewar)
{
	size_t distance = 0;
	t_command *command;
	t_hash_table *hash;

	command = corewar->bot.command;
	while (command)
	{
		if (command_name && !ft_strcmp(command->method, command_name))
			break ;
		if (!command->command_name)
		{
			hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
			while (hash->command)
			{
				distance += !ft_strcmp(hash->command->command_name, "aff") ? 1 : 2;
				distance += get_size_args(hash->command);
				hash->command = hash->command->next;
			}
		}
		command = command->next;
	}
	return (distance);
}

void get_prog_size(header_t *header, t_corewar *corewar, int fd)
{
	unsigned size = 0;
	t_command *command;
	t_hash_table *hash;
	t_command *_command;

	command = corewar->bot.command;
	while (command)
	{
		hash = get_table(corewar->bot.hash_table, corewar->bot.keys, command->method);
		_command = hash->command;
		size++;
		if (ft_strcmp(_command->command_name, "aff"))
			size++;
		while (_command)
		{
			size += get_size_args(_command);
			_command = _command->next;
		}
		command = command->next;
	}
	header->prog_size = size;
	write(fd, "\0", sizeof(header->prog_size) - ((size / (MEM_SIZE >> 4)) + 1));
	write(fd, &header->prog_size, (size / (MEM_SIZE >> 4)) + 1);
}

