#include "shell.h"

static int		ft_chdir(char *path)
{
	if (access(path, F_OK))
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		return (FAIL);
	}
	if (chdir(path) == -1)
	{
		dprintf(1, "Fail todo whi\n");
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
	{
		dprintf(1, "fail chdir\n");
		return (FAIL);
	}
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
	{
		dprintf(1, "fail chdir\n");
		return (FAIL);
	}
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

int				cd_path(char *path)
{
	if (ft_chdir(path) != SUCCESS)
	{
		dprintf(1, "fail chdir\n");
		return (FAIL);
	}
	return (SUCCESS);
}
