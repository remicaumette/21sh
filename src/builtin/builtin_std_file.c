#include "shell.h"

int			builtin_stdin_file(const char *file, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ret = FAIL;
		error_access(file, O_RDONLY);
		close(builtin->std[STDIN]);
	}
	else
	{
		if ((builtin->std[STDIN] = dup(fd)) == -1)
			ret = FAIL;
	}
	builtin->isset[STDIN] = 1;
	return (ret);
}

int		builtin_stdout_file(const char *file, int flag, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
		close(builtin->std[STDOUT]);
	}
	else
	{
		if ((builtin->std[STDOUT] = dup(fd)) == -1)
			ret = FAIL;
	}
	builtin->isset[STDOUT] = 1;
	return (ret);
}

int		builtin_stderr_file(const char *file, int flag, t_builtin *builtin)
{
	int		ret;
	int		fd;

	ret = SUCCESS;
	if ((fd = open(file, flag | O_WRONLY | O_CREAT, 0644)) == -1)
	{
		ret = FAIL;
		error_access(file, O_WRONLY);
		close(builtin->std[STDERR]);
	}
	else
	{
		if ((builtin->std[STDERR] = dup(fd)) == -1)
			ret = FAIL;
	}
	builtin->isset[STDERR] = 1;
	return (ret);
}
