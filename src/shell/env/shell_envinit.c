/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_envinit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:53:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 17:00:59 by timfuzea    ###    #+. /#+    ###.fr     */
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

static int	set_default(t_shell *shell)
{
	char	*tmp;

	tmp = NULL;
	setvar_shell(shell);
	if (!shell_getenv(shell, "USER"))
		setvar_user(shell);
	if (!shell_getenv(shell, "HOME"))
		setvar_home(shell);
	if ((tmp = shell_getenv(shell, "SHLVL")) == NULL)
		setvar_shlvl(shell);
	else
	{
		tmp = ft_strdup(tmp);
		tmp = ft_strpp(&tmp);
		shell_setenv(shell, "SHLVL", tmp);
		ft_strdel(&tmp);
	}
	if (!shell_getenv(shell, "PATH"))
		set_path(shell);
	if (!(shell_getenv(shell, "TERM")))
		shell_setenv(shell, "TERM", "xterm-256color");
	if (!(shell_getenv(shell, "PWD")))
		setvar_pwd(shell);
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
	set_default(shell);
	return (0);
}
