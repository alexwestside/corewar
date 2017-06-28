#include "corewar.h"

void	ft_name(char **name, char **text)
{
	char **s;

	if (!ft_strstr(*text, ".name"))
		error("Syntax error at token [TOKEN][004:001] LABEL \"l2:\"");
	else
	{
		s = ft_strsplit(*text, '\t');
		s++;
		if (*s == NULL)
			error(NULL);
		else if (**s != '"')
			error("Lexical error at [2:10]");
		else
		{
			name = NULL;
		}
		text++;
	}
}

void 	ft_name_comment(char **name, char **comment, char **text)
{
	int i;
	char **s;

	i = 0;
	while (**text == '#' || **text == '\0')
		text++;
	ft_name(name, text);
	//ft_comment(comment, text);
}