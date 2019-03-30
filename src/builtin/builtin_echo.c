#include "shell.h"

int			builtin_echo(int argc, char **argv, t_shell *shell)
{
	char		*tmp;

	if (argc == 1)
	{
		ft_putchar('\n');
		return (SUCCESS);
	}
	if (!ft_strequ(argv[1], "-n"))
	{
		if ((tmp = ft_strjoinspace_2d(&argv[2])) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		return (SUCCESS);
	}
	else
	{
		if ((tmp = ft_strjoinspace_2d(&argv[1])) == NULL)
			return ;
		ft_putendl(tmp);
	}
	ft_strdel(&tmp);
	return (SUCCESS);
}
