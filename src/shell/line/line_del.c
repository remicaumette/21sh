/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:39:37 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:39:39 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		line_del(t_line *line)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	if ((line->size - 1) != 0)
	{
		if (!(tmp = ft_strnew(line->size - 1)))
			return (FAIL);
		while (++i < (line->cursor - 1))
			tmp[i] = line->content[i];
		if (line->content[i] != '\0')
			while (line->content[++i])
				tmp[i - 1] = line->content[i];
		tmp[i - 1] = '\0';
	}
	ft_strdel(&(line->content));
	line->content = tmp;
	line->size--;
	return (SUCCESS);
}
