/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_utile.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/23 12:41:18 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 13:54:21 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int				action_isendline(t_line *line)
{
	if ((line->cursor + 2) == line->window.ws_col)
		return (TRUE);
	return (FALSE);
}

int				action_islastline(t_line *line)
{
	if (((line->cursor + 2) / line->window.ws_col) == line->window.ws_row)
		return (TRUE);
	return (FALSE);
}

int			action_str(char *str)
{
	char	*tmp;
	if (!(tmp = tgetstr(str, NULL)))
		return (FAIL);
	ft_putstr(tmp);
	return (SUCCESS);
}
