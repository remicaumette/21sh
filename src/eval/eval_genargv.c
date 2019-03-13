#include "eval.h"

char		**eval_genargv(t_command *command)
{
	int		i;
	char	**out;

	i = 0;
	if (!(out = ft_strarr_new(ft_strarr_len(command->arguments) + 1)))
		return (NULL);
	if (!(*out = ft_strdup(command->name)))
		return (NULL);
	if (command->arguments)
	{
		while (command->arguments[i])
		{
			if (!(out[1 + i] = ft_strdup(command->arguments[i])))
				return (NULL);
			i++;
		}
	}
	out[1 + i] = NULL;
	return (out);
}
