/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_del.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:27:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 18:42:21 by timfuzea    ###    #+. /#+    ###.fr     */
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
	if (action_str(TC_CLEAR_TO_END) != SUCCESS)
		return (FAIL);
	action_putstr(line, &(line->content[line->cursor - 1]));
	while (++i <= (line->size - line->cursor))
	{
		if (action_move_left(line) != SUCCESS)
			return (FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int		action_backdel(t_shell *shell)
{
	if (shell->line->cursor > 1)
	{
		line_backdel(shell->line);
		if (action_move_left(shell->line) != SUCCESS)
			return (FAIL);
		if (shell->line->cur_pos.ws_col >= shell->line->window.ws_col)
		{
			if (action_str(TC_CLEAR_END_LINE) != SUCCESS)
				return (FAIL);
		}
		else
		{
			if (action_str(TC_DEL) != SUCCESS)
				return (FAIL);
		}
		if (((shell->line->size + 2) / shell->line->window.ws_col) > ((shell->line->cursor + 2) / shell->line->window.ws_col))
		{
			if (multi_line(shell->line) != SUCCESS)
				return (FAIL);
		}
	}
	return (SUCCESS);
}
