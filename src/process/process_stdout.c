#include "shell.h"

int		process_stdout(const char *file, int flag, t_process *process)
{
	int		fd;

	if (file != NULL)
	{
		if ((fd = open(file, flag, 0755)) == -1)
			return (FAIL);
		dup2(fd, process->stdout[0]);
		close(fd);
		close(process->stdout[1]);
	}
	else
	{
		if (dup2(process->stdout[0], STDOUT_FILENO) == -1)
		{
			dprintf(1, "fail stdou");
			return (FAIL);
		}
		close(process->stdout[1]);
	}

	return (SUCCESS);
}
