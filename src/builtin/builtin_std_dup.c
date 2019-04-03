#include "shell.h"

int		builtin_stdin_dup(int stdin, t_builtin *builtin)
{
	if (dup2(stdin, builtin->std[STDIN]) == -1)
		return (FAIL);
	builtin->isset[STDIN] = 1;
	return (SUCCESS);
}

int		builtin_stdout_dup(int stdout, t_builtin *builtin)
{
	if (dup2(stdout, builtin->std[STDOUT]) == -1)
		return (FAIL);
	builtin->isset[1] = 1;
	return (SUCCESS);
}

int		builtin_stderr_dup(int stderr, t_builtin *builtin)
{
	if (dup2(stderr, builtin->std[STDERR]) == -1)
		return (FAIL);
	builtin->isset[STDERR] = 1;
	return (SUCCESS);
}

int		builtin_stdall_dup(int std[3], t_builtin *builtin)
{
	if (builtin_stdin_dup(std[STDIN], builtin) != SUCCESS)
		builtin_stdin_close(builtin);
	if (builtin_stdout_dup(std[STDOUT], builtin) != SUCCESS)
		builtin_stdout_close(builtin);
	if (builtin_stderr_dup(std[STDERR], builtin) != SUCCESS)
		builtin_stderr_close(builtin);
	return (SUCCESS);
}