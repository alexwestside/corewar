#include "corewar.h"

int 	len_char(char **a)
{
	int len;

	len = 0;
	while (a[len] != NULL)
		len++;
	return (len);
}

void				get_method(char ***a, t_command **method)
{
	t_command		*head;
	t_command		*tmp;
	char 			**s;
	char			**p;

	while (**a && ***a == '\t')
	{
		tmp = (t_command *)malloc(sizeof(t_command));
		tmp->method = NULL;
		tmp->next = NULL;
		s = ft_strsplit(*ft_strsplit(**a, '\t'), ' ');
		tmp->command_name = ft_strdup(*(s++));
		if (s[0])
		{
			tmp->arg1 = ft_strdup(s[0]);
			if (s[1])
			{
				tmp->arg2 = ft_strdup(s[1]);
				if (s[2])
					tmp->arg3 = ft_strdup(s[2]);
			}
		}
		if (*method == NULL)
			*method = tmp;
		else
		{
			head = *method;
			while ((*method)->next != NULL)
				*method = (*method)->next;
			(*method)->next = tmp;
			*method = head;
		}
		(*a)++;
	}
}

t_hash_table		*get_hash(char ***text, char **a)
{
	t_hash_table	*table;

	table = (t_hash_table *)malloc(sizeof(t_hash_table));
	table->command = NULL;
	table->collision = NULL;
	table->lable = ft_strdup(*(a++));
	++(*text);
	get_method((*a == NULL ? text : &a), &table->command);
	return (table);
}

t_bot				ft_command(char **text)
{
	t_hash_table	**hash_table;
	unsigned int	*key;
	char	**a;
	int i;
	unsigned int j;
	int 		col;
	t_hash_table	*tmp;
	t_hash_table	*head;
	t_bot			bot;

	i = 0;
	j = 0;
	hash_table = (t_hash_table **)malloc(sizeof(t_hash_table *));
	key = (unsigned int *)malloc(sizeof(unsigned int));
	while (*text != NULL)
	{
		a = ft_strsplit(*text, ':');
		if (!ft_strstr(a[0], "%") && *a[0] != '#' && *a[0] != '\0' && *a[0] != '.' && *a[0] != '\t')
		{
			j = hash_key(a[0]);
			if ((col = collision(key, j)) == 0)
			{
				key[i] = j;
				key = realloc(key, (sizeof(key) * (i + 2)));
				hash_table[i] = get_hash(&text, a);
				hash_table = realloc(hash_table, (sizeof(hash_table) * (i + 2)));
				i++;
			}
			else
			{
				tmp = get_hash(&text, a);
				head = hash_table[col];
				while (hash_table[col]->collision != NULL)
					hash_table[col] = hash_table[col]->collision;
				hash_table[col]->collision = tmp;
				hash_table[col] = head;
			}
		}
		else
			text++;
	}
	bot.hash_table = hash_table;
	bot.keys = key;
	return (bot);
}
