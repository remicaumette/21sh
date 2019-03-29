/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_command.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:19:14 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 15:26:21 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_buil_tab		g_builtin_tab[] = {
	{"exit", builtin_exit},
	{"setenv", builtin_setenv},
	{"unsetenv", builtin_unsetenv},
	{NULL, NULL}
};

static int	make_process(t_command *command, t_process **process,
		t_shell *shell)
{
	char	*bin;
	char	**argv;

	if (!(bin = eval_getbin(command->name, shell)))
	{
		printf("%s: command not found: %s\n", SHELL_NAME, command->name);
		return (FAIL);
	}
	if (!(argv = eval_genargv(command)))
		return (FAIL);
	if (!(*process = process_create(bin, argv, shell->environment)))
		return (FAIL);
	ft_strdel(&bin);
	ft_strarr_del(argv);
	return (SUCCESS);
}

static int	make_builtin(t_command *command, t_builtin **builtin)
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
	if ((ret = make_builtin(node->command, &builtin)) == -1)
		return (FAIL);
	if (!ret && make_process(node->command, &process, shell) != SUCCESS)
		return (FAIL);
	if (!ret && eval_redirection(node->command, process, shell) != SUCCESS)
		return (FAIL);
	if (!(*eval = eval_create(builtin, process)))
		return (FAIL);
	return (SUCCESS);
}
