
#include "shell.h"

int		builtin_stdin_close(t_builtin *builtin)
{
	if (builtin->STDIN != -1)
		close(builtin->STDIN);
	builtin->STDIN = -1;
	return (SUCCESS);
}

int		builtin_stdout_close(t_builtin *builtin)
{
	if (builtin->STDOUT != -1)
		close(builtin->STDOUT);
	builtin->STDOUT = -1;
	return (SUCCESS);
}

int		builtin_stderr_close(t_builtin *builtin)
{
	if (builtin->STDERR != -1)
		close(builtin->STDERR);
	builtin->STDERR = -1;
	return (SUCCESS);
}

int		builtin_stdall_close(t_builtin *builtin)
{
	builtin_stdin_close(builtin);
	builtin_stdout_close(builtin);
	builtin_stderr_close(builtin);
	return (SUCCESS);
}
