/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_deltoend.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 14:17:32 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:23:19 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		line_deltoend(t_line *line)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = ft_strndup(line->content, (line->cursor - 1))))
		return (FAIL);
	ft_strdel(&line->content);
	line->content = tmp;
	line->size = line->cursor - 1;
	return (SUCCESS);
}
