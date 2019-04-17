/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_env.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:55 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 14:54:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	save_env(t_shell *shell, int ret)
{
	static char		**env = NULL;

	if (env == NULL)
	{
		if (!(env = ft_strdup_2d((const char **)shell->environment)))
			return (FAIL);
		return (SUCCESS);
	}
	else
	{
		ft_strdel_2d(&shell->environment);
		shell->environment = env;
		env = NULL;
		return (ret);
	}
}

static int	check_iflag(char *s)
{
	int	ok;

	ok = *s == '-' && *(s + 1) == 'i';
	while (ok && *++s)
		if (*s != 'i')
			return (0);
	return (ok);
}

static int	parser(int *argc, char **argv, int std[3], t_shell *shell)
{
	int	i;

	(void)std;
	i = 0;
	while (argv[++i])
	{
		if (check_iflag(argv[i]))
			ft_strdel_2d(&shell->environment);
		else if (ft_strchr(argv[i], '='))
			env_setall(argv[i], shell);
		else
			break ;
	}
	*argc = i;
	return (SUCCESS);
}

static int	make_process(char **argv, t_process **process, int std[3],
		t_shell *shell)
{
	char	*bin;

	if (!(bin = eval_getbin(argv[0], shell)))
	{
		ft_putstr_fd("env: \'", STDERR);
		ft_putstr_fd(argv[0], STDERR);
		ft_putstr_fd("\': No such file or directory\n", STDERR);
		return (FAIL);
	}
	if (!(*process = process_create(bin, argv, shell->environment)))
		return (FAIL);
	ft_strdel(&bin);
	process_stdall_dup(std, *process);
	return (SUCCESS);
}

int			builtin_env(int argc, char **argv, int std[3], t_shell *shell)
{
	int			i;
	t_process	*process;

	(void)argc;
	i = 0;
	if (save_env(shell, 0) != SUCCESS)
		return (FAIL);
	if (parser(&i, argv, std, shell) != SUCCESS)
		return (save_env(shell, FAIL));
	if (!argv[i])
	{
		ft_putstr_2dfd(shell->environment, STDOUT);
		return (save_env(shell, SUCCESS));
	}
	if (make_process(&argv[i], &process, std, shell) != SUCCESS)
		return (save_env(shell, FAIL));
	if (process_run(process) != SUCCESS)
		return (save_env(shell, FAIL));
	process_destroy(&process);
	return (save_env(shell, SUCCESS));
}
