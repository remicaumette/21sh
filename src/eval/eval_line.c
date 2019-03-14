#include "shell.h"

t_process	*eval_make_process(t_command *command, t_shell *shell)
{
	t_process	*process;
	char		*bin;
	char		**argv;

	if (!(bin = eval_getbin(command->name, shell)))
		return (NULL);
	if (!(argv = eval_genargv(command)))
		return (NULL);
	if (!(process = process_create(bin, argv, shell->environment)))
		return (NULL);
	ft_strdel(&bin);
	ft_strarr_del(argv);
	return (process);
}

int			eval_line(t_shell *shell)
{
	t_process	*process;

	if (!(process = eval_make_process(shell->parser->root->command, shell)))
		return (FAIL);
	process_stdall_default(process);
	if (process_start(process))
		return (FAIL);
	if (process_wait(process) != SUCCESS)
		return (FAIL);
	process_destroy(process);
	return (SUCCESS);
}
