#include "shell.h"

static int	print_usage(void)
{
	ft_putstr_fd("21sh: setenv: Usage: setenv \"TOTO=tata\" | TOTO tata\n",
			STDERR_FILENO);
	return (FAIL);
}

int			builtin_setenv(int argc, char **argv, t_shell *shell)
{
	if (argc > 3)
	{
		ft_putstr_fd("21sh: setenv: Too many arguments\n", STDERR_FILENO);
		return (FAIL);
	}
	if (argc == 2)
	{
		if (ft_strchr(argv[1], '=') == NULL && ft_strchr(argv[1], ' ') == NULL)
			return (print_usage());
		if (env_setall(argv[1], shell) != SUCCESS)
			return (FAIL);
		return (SUCCESS);
	}
	else
	{
		if (ft_strchr(argv[1], '=') != NULL || ft_strchr(argv[1], ' ') != NULL)
			return (print_usage());
		if (ft_strchr(argv[2], '=') != NULL || ft_strchr(argv[2], ' ') != NULL)
			return (print_usage());
		if (!shell_setenv(shell, argv[1], argv[2]))
			return (FAIL);
		return (SUCCESS);
	}
}
