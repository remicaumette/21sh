#include "eval.h"

int			eval_line(t_shell *shell)
{
	t_process	*process1;
	t_process	*process2;
	char		**argv;
	char		*bin;

	if (!(bin = shell_getbin(shell->parser->root->command->name, shell)))
		return (FAIL);
	if (!(argv = eval_genargv(shell->parser->root->command)))
		return (FAIL);
	if (!(process1 = process_create("./write_test.bin", argv, shell->environment)))
		return (FAIL);
	if (!(process2 = process_create("./read_test.bin", argv, shell->environment)))
		return (FAIL);
	process_stdin_default(process1); // stdin[0] = FILENO
	if (process_stdout_pipe(process1, process2) != SUCCESS)
		return (FAIL);
	process_stdout_default(process2); // stdout[1] = FILENO
	ft_strdel(&bin);
	ft_strarr_del(argv);
	if (process_start(process1))
		return (FAIL);
	if (process_start(process2))
		return (FAIL);
	if (process_wait(process1) != SUCCESS)
		return (FAIL);
	if (process_wait(process2) != SUCCESS)
		return (FAIL);
	process_destroy(process1);
	process_destroy(process2);
	return (SUCCESS);
}
