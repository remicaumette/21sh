#include "shell.h"

static int		print_error(char *path, char *err_msg, int std[3])
{
		ft_putstr_fd("cd: ", std[STDERR]);
		ft_putstr_fd(path, std[STDERR]);
		ft_putstr_fd(": ", std[STDERR]);
		ft_putstr_fd(err_msg, std[STDERR]);
		return (FAIL);
}

int				ft_chdir(char *path, int std[3])
{
	if (access(path, F_OK))
		return (print_error(path, "No such file or directory\n", std));
	if (chdir(path) == -1)
	{
		if (access(path, R_OK))
			print_error(path, "Permission denide\n", std);
		return (FAIL);
	}
	return (SUCCESS);
}

int				cd_home(t_shell *shell, int std[3])
{
	char		*home;

	if ((home = shell_getenv(shell, "HOME")) == NULL)
		return (FAIL);
	if (ft_chdir(home, std) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int				cd_tild(t_shell *shell, char *path, int std[3])
{
	char		*tmp;
	char		*home;

	if ((home = shell_getenv(shell, "HOME")) == NULL)
		return (FAIL);
	if (path[1] != '\0')
	{
		if (!(tmp = ft_strjoin(home, &path[1])))
			return (FAIL);
	}
	else
		tmp = home;
	if (ft_chdir(tmp, std) != SUCCESS)
		return (FAIL);
	ft_strdel(&tmp);
	return (SUCCESS);
}

int				cd_oldpwd(t_shell *shell, int std[3])
{
	char		*new_path;

	if ((new_path = shell_getenv(shell, "OLDPWD")) == NULL)
		return (FAIL);
	if (ft_chdir(new_path, std) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
