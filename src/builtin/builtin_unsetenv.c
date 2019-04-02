#include "shell.h"

int		builtin_unsetenv(int argc, char **argv, int std[3], t_shell *shell)
{
	int		i;

	(void)std;
	i = 0;
	while (++i < argc)
	{
		if (!shell_unsetenv(shell, argv[i]))
			return (FAIL);
	}
	return (SUCCESS);
}
