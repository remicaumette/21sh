/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_cd.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:29:38 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 23:16:48 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*get_pwd(int buf_size)
{
	char	*buf;

	buf = NULL;
	if ((buf = ft_strnew(buf_size)) == NULL)
		return (NULL);
	if (getcwd(buf, buf_size) == NULL && buf_size < MAXNAMLEN)
	{
		ft_strdel(&buf);
		return (get_pwd(buf_size + 64));
	}
	return (buf);
}

static int		parser(int argc, char **argv, int std[3], t_shell *shell)
{
	if (argc == 1)
		return (cd_home(shell, std));
	if (argv[1][0] == '~')
		return (cd_tild(shell, argv[1], std));
	if (argv[1][0] == '-' && argv[1][1] == '\0')
		return (cd_oldpwd(shell, std));
	return (ft_chdir(argv[1], std));
}

int				builtin_cd(int argc, char **argv, int std[3], t_shell *shell)
{
	char	*pwd;

	if (argc > 2)
	{
		ft_putstr_fd("cd: Too many arguments\n", std[STDERR]);
		return (FAIL);
	}
	if (!(pwd = get_pwd(64)))
		return (FAIL);
	if (parser(argc, argv, std, shell) != SUCCESS)
	{
		ft_strdel(&pwd);
		return (FAIL);
	}
	shell_setenv(shell, "OLDPWD", pwd);
	ft_strdel(&pwd);
	if (!(pwd = get_pwd(64)))
		return (FAIL);
	shell_setenv(shell, "PWD", pwd);
	ft_strdel(&pwd);
	return (SUCCESS);
}
