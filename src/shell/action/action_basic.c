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

static int		multi_line(t_shell *shell)
{
	int		i;

	i = -1;
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (FAIL);
	action_putstr(shell, &(shell->line->content[shell->line->cursor - 2]));
	while (++i <= (shell->line->size - shell->line->cursor))
	{
		if (action_move_left(shell) != SUCCESS)
			return (FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int				action_basic(t_shell *shell, long buf)
{
	if (line_inser(shell->line, (char)buf) != SUCCESS)
		return (FAIL);
	if ((((shell->line->size + 2) >= shell->line->window.ws_col) && (shell->line->size + 2 / shell->line->window.ws_col) > (shell->line->cursor + 2 / shell->line->window.ws_col)))
	{
		if (multi_line(shell) != SUCCESS)
			return (FAIL);
	}
	else
		action_putchar(shell, (char)buf);
	return (SUCCESS);
}

/*
int		action_basic(t_line *line, long buf, int readed)
{
	(void)line;
	dprintf(1, "buf:%ld\nreaded:%d\n", buf, readed);
	return (SUCCESS);
}*/
