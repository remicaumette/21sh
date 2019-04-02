#include "shell.h"

static int		print_error(char *path, char *err_msg)
{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(err_msg, STDERR_FILENO);
		return (FAIL);
}

int				ft_chdir(char *path)
{
	if (access(path, F_OK))
		return (print_error(path, "No such file or directory\n"));
	if (chdir(path) == -1)
	{
		if (access(path, R_OK))
			print_error(path, "Permission denide\n");
		return (FAIL);
	}
	return (SUCCESS);
}

int				cd_home(t_shell *shell)
{
	char		*home;

	if ((home = shell_getenv(shell, "HOME")) == NULL)
		return (FAIL);
	if (ft_chdir(home) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int				cd_tild(t_shell *shell, char *path)
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
	if (ft_chdir(tmp) != SUCCESS)
		return (FAIL);
	ft_strdel(&tmp);
	return (SUCCESS);
}

int				cd_oldpwd(t_shell *shell)
{
	char		*new_path;

	if ((new_path = shell_getenv(shell, "OLDPWD")) == NULL)
		return (FAIL);
	if (ft_chdir(new_path) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
