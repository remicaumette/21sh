#include "shell.h"

int		builtin_stdin_file(const char *file, t_builtin *builtin)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FAIL);
	dup2(fd, builtin->std[STDIN]);
	close(fd);
	builtin->isset[STDIN] = 1;
	return (SUCCESS);
}

int		builtin_stdout_file(const char *file, int flag, t_builtin *builtin)
{
	int		fd;

	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
		return (FAIL);
	dup2(fd, builtin->std[STDOUT]);
	close(fd);
	builtin->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		builtin_stderr_file(const char *file, int flag, t_builtin *builtin)
{
	int		fd;

	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
		return (FAIL);
	dup2(fd, builtin->std[STDERR]);
	close(fd);
	builtin->isset[STDERR] = 1;
	return (SUCCESS);
}
