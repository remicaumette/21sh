#include "shell.h"

int		builtin_unsetenv(int argc, char **argv, t_shell *shell)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!shell_unsetenv(shell, argv[i]))
			return (FAIL);
	}
	return (SUCCESS);
}
