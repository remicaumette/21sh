/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_basic.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 00:26:38 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:11:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		multi_line(t_line *line)
{
	int		i;

	i = -1;
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (FAIL);
	action_putstr(line, &(line->content[line->cursor - 2]));
	while (++i <= (line->size - line->cursor))
	{
		if (action_move_left(line) != SUCCESS)
			return (FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int				action_basic(t_line *line, char *buf, int readed)
{
	if (line_inser(line, *buf) != SUCCESS)
		return (FAIL);
	if ((((line->size + 2) >= line->window.ws_col) && (line->size + 2 / line->window.ws_col) > (line->cursor + 2 / line->window.ws_col)))
	{
		if (multi_line(line) != SUCCESS)
			return (FAIL);
	}
	else
		action_putchar(line, buf, readed);
	return (SUCCESS);
}

/*
int		action_basic(t_shell *shell, char *buf, int readed)
{
	dprintf(1, "readed=%d\t{%d, %d, %d}, {%c, %c, %c}\n", readed, buf[0], buf[1], buf[2], buf[0], buf[1], buf[2]);
	if (line_inser(shell->line, *buf) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}*/
