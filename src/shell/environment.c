/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   environment.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:44:32 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:06:40 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		shell_envinit(t_shell *shell, char **env)
{
	int		i;
	int		fd;
	char	*line;
	char	*path;
	char	*tmp;

	i = -1;
	path = NULL;
	while (env[++i])
		if (!(shell->environment = ft_strarr_add(shell->environment, env[i])))
			return (1);
	if (!(shell_getenv(shell, "PATH")))
	{
		if ((fd = open("/etc/paths", O_RDONLY)) == -1)
			return (1);
		while (get_next_line(fd, &line) > 0)
		{

		}
	}
	return (0);
}

char	*shell_getenv(t_shell *shell, char *name)
{
	int		i;
	char	*delimiter;

	i = -1;
	while (shell->environment[++i])
		if (!(delimiter = ft_strchr(shell->environment[i], '=')))
			continue ;
		else if (ft_strnequ(shell->environment[i], name,
			delimiter - shell->environment[i]))
			return (delimiter + 1);
	return (NULL);
}

char	**shell_setenv(t_shell *shell, char *name, char *value)
{
	char	len;
	char	tmp[ft_strlen(name) + ft_strlen(value) + 1];
	char	**env;
	int		i;

	len = ft_strlen(name);
	ft_strcpy(tmp, name);
	*(tmp + len) = '=';
	ft_strcat(tmp, value);
	env = NULL;
	i = -1;
	while (shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	if (!(env = ft_strarr_add(env, tmp)))
		return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}

char	**shell_unsetenv(t_shell *shell, char *name)
{
	char	len;
	char	**env;
	int		i;

	len = ft_strlen(name);
	env = NULL;
	i = -1;
	while (shell->environment[++i])
		if (ft_strncmp(name, shell->environment[i], len) &&
			!(env = ft_strarr_add(env, shell->environment[i])))
			return (NULL);
	ft_strarr_del(shell->environment);
	return (shell->environment = env);
}

char	*shell_gethome(t_shell *shell)
{
	char	*home;

	home = shell_getenv(shell, "HOME");
	return (home ? home : "/");
}
