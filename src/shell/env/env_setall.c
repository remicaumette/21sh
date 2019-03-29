/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_envextract.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 16:41:05 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/12 16:41:05 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			env_setall(char *all, t_shell *shell)
{
	char		*tmp;
	char		*key;
	char		*valu;

	if ((tmp = ft_strchr(all, '=')) == NULL)
		if ((tmp = ft_strchr(all, ' ')) == NULL)
			return (FAIL);
	if ((key = ft_strndup(all, (tmp - all))) == NULL)
		return (FAIL);
	if ((valu = ft_strdup((tmp + 1))) == NULL)
		return (FAIL);
	if (!(shell_setenv(shell, key, valu)))
		return (FAIL);
	ft_strdel(&key);
	ft_strdel(&valu);
	return (SUCCESS);
}
