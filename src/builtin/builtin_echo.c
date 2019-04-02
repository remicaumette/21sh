#include "shell.h"

int			builtin_echo(int argc, char **argv, int std[3], t_shell *shell)
{
	char		*tmp;

	(void)shell;
	if (argc == 1)
	{
		ft_putchar_fd('\n', std[STDOUT]);
		return (SUCCESS);
	}
	if (ft_strequ(argv[1], "-n"))
	{
		if ((tmp = ft_strjoinspace_2d((const char **)&argv[2])) == NULL)
			return (FAIL);
		ft_putstr_fd(tmp, std[STDOUT]);
	}
	else
	{
		if ((tmp = ft_strjoinspace_2d((const char **)&argv[1])) == NULL)
			return (FAIL);
		ft_putendl_fd(tmp, std[STDOUT]);
	}
	ft_strdel(&tmp);
	return (SUCCESS);
}
