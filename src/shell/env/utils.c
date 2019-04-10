/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/10 21:30:49 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/10 22:40:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			env_default_path(char **path)
{
	int		fd;
	int		ret;
	char	buf[512 + 1];

	if ((fd = open("/etc/paths", O_RDONLY)) == -1)
		return (FAIL);
	while ((ret = read(fd, buf, 512)) > 0)
	{
		buf[ret] = '\0';
		if (*path != NULL)
		{
			if ((*path = ft_strjoinfree(path, (char **)&buf, 1)) == NULL)
				return (FAIL);
			continue;
		}
		if ((*path = ft_strdup(buf)) == NULL)
			return (FAIL);
	}
	close(fd);
	ft_sub('\n', ':', *path);
	return (SUCCESS);
}

int			env_getpw(t_passwd **pw)
{
	uid_t		uid;

	uid = getuid();
	if ((*pw = getpwuid(uid)) == NULL)
		return (FAIL);
	return (SUCCESS);
}
