/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setvar_name1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:41:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 23:33:32 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		setvar_shell(t_shell *shell)
{
	shell_setenv(shell, "SHELL", "21sh");
	return (SUCCESS);
}

int		setvar_user(t_shell *shell)
{
	t_passwd	*pw;

	pw = NULL;
	if (env_getpw(&pw) != SUCCESS)
		return (FAIL);
	shell_setenv(shell, "USER", pw->pw_name);
	return (SUCCESS);
}

int		setvar_home(t_shell *shell)
{
	t_passwd	*pw;

	pw = NULL;
	if (env_getpw(&pw) != SUCCESS)
		return (FAIL);
	shell_setenv(shell, "HOME", pw->pw_dir);
	return (SUCCESS);
}

int		setvar_shlvl(t_shell *shell)
{
	shell_setenv(shell, "SHLVL", "1");
	return (SUCCESS);
}

int		setvar_path(t_shell *shell)
{
	char		*path;

	path = NULL;
	if (env_default_path(&path) != SUCCESS)
		return (FAIL);
	shell_setenv(shell, "PATH", path);
	ft_strdel(&path);
	return (SUCCESS);
}
