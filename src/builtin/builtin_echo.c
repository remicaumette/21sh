/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_echo.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:29:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:13:25 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			builtin_echo(int argc, char **argv, int std[3], t_shell *shell)
{
	char		*tmp;

	(void)shell;
	if (argc == 1)
	{
		ft_putchar_fd('\n', STDOUT);
		return (SUCCESS);
	}
	if (ft_strequ(argv[1], "-n"))
	{
		if ((tmp = ft_strjoinspace_2d((const char **)&argv[2])) == NULL)
			return (FAIL);
		ft_putstr_fd(tmp, STDOUT);
	}
	else
	{
		if ((tmp = ft_strjoinspace_2d((const char **)&argv[1])) == NULL)
			return (FAIL);
		ft_putendl_fd(tmp, STDOUT);
	}
	ft_strdel(&tmp);
	return (SUCCESS);
}
