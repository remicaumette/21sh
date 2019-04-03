#include "shell.h"

int		builtin_stdin_close(t_builtin *builtin)
{
	close(builtin->std[STDIN]);
	builtin->isset[STDIN] = 1;
	return (SUCCESS);
}

int		builtin_stdout_close(t_builtin *builtin)
{
	close(builtin->std[STDOUT]);
	builtin->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		builtin_stderr_close(t_builtin *builtin)
{
	close(builtin->std[STDERR]);
	builtin->isset[STDERR] = 1;
	return (SUCCESS);
}
