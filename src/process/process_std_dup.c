#include "process.h"

int		process_stdin_dup(int stdin, t_process *process)
{
	if (dup2(stdin, process->stdin[0]) == -1)
		return (FAIL);
	process->isset[0] = 1;
	return (SUCCESS);
}

int		process_stdout_dup(int stdout, t_process *process)
{
	if (dup2(stdout, process->stdout[1]) == -1)
		return (FAIL);
	process->isset[1] = 1;
	return (SUCCESS);
}

int		process_stderr_dup(int stderr, t_process *process)
{
	if (dup2(stderr, process->stderr[1]) == -1)
		return (FAIL);
	process->isset[2] = 1;
	return (SUCCESS);
}

int		process_stdall_dup(int std[3], t_process *process)
{
	if (process_stdin_dup(std[0], process) != SUCCESS)
		process_stdin_close(process);
	if (process_stdout_dup(std[1], process) != SUCCESS)
		process_stdout_close(process);
	if (process_stderr_dup(std[2], process) != SUCCESS)
		process_stderr_close(process);
	return (SUCCESS);
}
