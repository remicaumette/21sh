/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_command.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:19:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 19:11:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_buil_tab		g_builtin_tab[] = {
	{"cd", builtin_cd},
	{"echo", builtin_echo},
	{"env", builtin_env},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{"exit", builtin_exit},
	{NULL, NULL}
};

static int	check_bin(char *path, char *name)
{
	t_stat		stat;

	if (!path)
		return (print_error(name, "Command not found"));
	if (access(path, F_OK))
		return (print_error(path, "Command not found"));
	if (access(path, X_OK))
		return (print_error(path, "Permission denide"));
	if (lstat(path, &stat) == -1 || S_ISDIR(stat.st_mode))
		return (print_error(path, "Is a directory"));
	return (SUCCESS);
}

static int	make_process(t_command *command, t_process **process,
		t_shell *shell)
{
	char	*bin;
	char	**argv;

	bin = eval_getbin(command->name, shell);
	if (check_bin(bin, command->name) != SUCCESS)
	{
		ft_strdel(&bin);
		return (FAIL);
	}
	if (!(argv = eval_genargv(command)))
		return (FAIL);
	if (!(*process = process_create(bin, argv, shell->environment)))
		return (FAIL);
	ft_strdel(&bin);
	ft_strarr_del(argv);
	if (eval_process_redirection(command, *process, shell) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

static int	make_builtin(t_command *command, t_builtin **builtin,
		t_shell *shell)
{
	char			**argv;
	t_buil_tab		*tab_buil;

	tab_buil = g_builtin_tab;
	while (tab_buil->str)
	{
		if (ft_strequ(tab_buil->str, command->name))
		{
			if (!(argv = eval_genargv(command)))
				return (-1);
			if (!(*builtin = builtin_create(argv, tab_buil->func)))
				return (-1);
			ft_strarr_del(argv);
			if (eval_builtin_redirection(command, *builtin, shell) != SUCCESS)
				return (-1);
			return (1);
		}
		tab_buil++;
	}
	return (0);
}

int			eval_command(t_node *node, t_eval **eval, t_shell *shell)
{
	int			ret;
	t_builtin	*builtin;
	t_process	*process;

	ret = 0;
	builtin = NULL;
	process = NULL;
	if (node->command == NULL)
		return (FAIL);
	if ((ret = make_builtin(node->command, &builtin, shell)) == -1)
		return (FAIL);
	if (!ret && make_process(node->command, &process, shell) != SUCCESS)
		return (FAIL);
	if (!(*eval = eval_create(builtin, process)))
		return (FAIL);
	return (SUCCESS);
}
