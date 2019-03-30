#include "shell.h"

static char		*get_pwd(int buf_size)
{
	char	*buf;

	buf = NULL;
	if ((buf = ft_strnew(buf_size)) == NULL)
		return (NULL);
	if (getcwd(buf, buf_size) == NULL && buf_size < MAXNAMLEN)
	{
		ft_strdel(&buf);
		return (get_pwd(buf_size + 64));
	}
	return (buf);
}

static int		parser(int argc, char **argv, t_shell *shell)
{
	if (argc == 1)
		return (cd_home(shell));
	if (argv[1][0] == '~')
		return (cd_tild(shell, argv[1]));
	if (argv[1][0] == '-' && argv[1][1] == '\0')
		return (cd_oldpwd(shell));
	return (cd_path(argv[1]));
}

int				builtin_cd(int argc, char **argv, t_shell *shell)
{
	char	*pwd;

	if (argc > 2)
	{
		ft_putstr_fd("cd: Too many arguments\n", STDERR_FILENO);
		return (FAIL);
	}
	if (!(pwd = get_pwd(64)))
		return (FAIL);
	if (parser(argc, argv, shell) != SUCCESS)
		return (FAIL);
	shell_setenv(shell, "OLDPWD", pwd);
	if (!(pwd = get_pwd(64)))
		return (FAIL);
	shell_setenv(shell, "PWD", pwd);
	return (SUCCESS);
}
