/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_envinit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 21:33:31 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	set_path(t_shell *shell)
{
	char	*path;

	path = NULL;
	if (env_default_path(&path) != SUCCESS)
		return (FAIL);
	shell_setenv(shell, "PATH", path);
	ft_strdel(&path);
	return (SUCCESS);
}

int			shell_envinit(t_shell *shell, char **env)
{
	int	i;

	i = -1;
	if (env)
	{
		while (env[++i])
			if (!(shell->environment =
						ft_straddfree_2d(&shell->environment, &env[i], 1)))
				return (1);
	}
	if (!(shell_getenv(shell, "TERM")))
		shell_setenv(shell, "TERM", "xterm-256color");
	if (!shell_getenv(shell, "PATH"))
		set_path(shell);
	return (0);
}
