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
#include "debug.h"

static int	putcharr(int c)
{
	return (write(1, &c, 1));
}

int			action_str(char *cap)
{
	char	*tmp;

	if (!(tmp = tgetstr(cap, NULL)))
		return (FAIL);
	ft_putstr(tmp);
	return (SUCCESS);
}

int			action_goto(t_line *line, int col, int row)
{
	char	*tmp;
	DEBUG_FD("goto.log")

	if (!(tmp = tgetstr(TC_GOTO, NULL)))
		return (FAIL);
	dprintf(fd_debug, "goto col=%d, row=%d\n", col, row);
	tputs(tgoto(tmp, col, row), 1, putcharr);
	line->cur_pos.ws_col = col;
	line->cur_pos.ws_row = row;
	return (SUCCESS);
}
