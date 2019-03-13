#include "shell.h"

int		process_stdin_file(const char *file, t_process *process)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FAIL);
	dup2(fd, process->stdin[0]);
	close(fd);
	return (SUCCESS);
}

int		process_stdout_file(const char *file, int flag, t_process *process)
{
	int		fd;

	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0755)) == -1)
		return (FAIL);
	dup2(fd, process->stdout[1]);
	close(fd);
	return (SUCCESS);
}

int		process_stderr_file(const char *file, int flag, t_process *process)
{
	int		fd;

	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0755)) == -1)
		return (FAIL);
	dup2(fd, process->stderr[1]);
	close(fd);
	return (SUCCESS);
}
