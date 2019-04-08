/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_getbin.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:22 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/08 15:27:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	is_indir(const char *name, const char *path)
{
	DIR					*fd_dir;
	struct dirent		*file;

	if ((fd_dir = opendir(path)) == NULL)
		return (FAIL);
	while ((file = readdir(fd_dir)) != NULL)
	{
		if (ft_strcmp(file->d_name, name) == 0)
		{
			closedir(fd_dir);
			return (SUCCESS);
		}
	}
	closedir(fd_dir);
	return (FAIL);
}

char		*eval_getbin(const char *name, t_shell *shell)
{
	int			i;
	char		*tmp;
	char		*out;
	char		**all_path;

	i = -1;
	out = NULL;
	if (*name == '.' || *name == '/')
		return (ft_strdup(name));
	if ((tmp = shell_getenv(shell, "PATH")) == NULL)
		return (NULL);
	all_path = ft_strsplit(tmp, ':');
	while (all_path && all_path[++i])
		if (is_indir(name, all_path[i]) == SUCCESS)
			break ;
	if (all_path[i] != NULL)
	{
		tmp = ft_strjoin(all_path[i], "/");
		out = ft_strjoinfree(&tmp, (char **)&name, 1);
	}
	ft_strarr_del(all_path);
	return (out == NULL) ? NULL : out;
}
