#include "shell.h"

int		process_iodefault(t_process *process)
{
	if (dup2(STDIN_FILENO ,process->stdin[0]) == -1)
		return (FAIL);
	if (dup2(STDOUT_FILENO, process->stdout[1]) == -1)
		return (FAIL);
	if (dup2(STDERR_FILENO, process->stderr[1]) == -1)
		return (FAIL);
	return (SUCCESS);
}
