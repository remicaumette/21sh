#include "eval.h"

static int	make_process(t_command *command, t_process **process, t_shell * shell)
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

int		eval_command(t_node *node, t_eval **eval, t_shell *shell)
{
	t_process	*process;

	process = NULL;
	if (node->command == NULL)
		return (FAIL);
	if (make_process(node->command, &process, shell) != SUCCESS)
		return (FAIL);
	if (eval_redirection(node->command, process) != SUCCESS)
		return (FAIL);
	if (!(*eval = eval_create(process)))
		return (FAIL);
	return (SUCCESS);
}
