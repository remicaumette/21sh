#include "shell.h"

int		builtin_stdin_close(t_builtin *builtin)
{
	close(builtin->std[STDIN]);
	builtin->std[STDIN] = -1;
	builtin->isset[STDIN] = 1;
	return (SUCCESS);
}

int		builtin_stdout_close(t_builtin *builtin)
{
	close(builtin->std[STDOUT]);
	builtin->std[STDOUT] = -1;
	builtin->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		builtin_stderr_close(t_builtin *builtin)
{
	close(builtin->std[STDERR]);
	builtin->std[STDERR] = -1;
	builtin->isset[STDERR] = 1;
	return (SUCCESS);
}

int		builtin_stdall_close(t_builtin *builtin)
{
	builtin_stdin_close(builtin);
	builtin_stdout_close(builtin);
	builtin_stderr_close(builtin);
	return (SUCCESS);
}
