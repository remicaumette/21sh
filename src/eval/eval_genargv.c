/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_genargv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 16:09:11 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static size_t	len_argv(char **argv)
{
	size_t		out;

	out = 0;
	if (!argv)
		return (0);
	while (*argv)
	{
		if (**argv == '\0')
			out--;
		out++;
		argv++;
	}
	return (out);
}

char			**eval_genargv(t_command *command)
{
	int		i;
	int		j;
	char	**out;

	j = 1;
	i = 0;
	if (!(out = ft_strnew_2d(len_argv(command->arguments) + 1)))
		return (NULL);
	if (!(*out = ft_strdup(command->name)))
		return (NULL);
	if (command->arguments)
	{
		while (command->arguments[i])
		{
			if (command->arguments[i][0] != '\0')
			{
				if (!(out[j] = ft_strdup(command->arguments[i])))
					return (NULL);
				j++;
			}
			i++;
		}
	}
	out[j] = NULL;
	return (out);
}
