/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 20:03:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 21:52:43 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_move_left(t_line *line)
{
	if (IS_BEGINLINE)
	{
		if (action_goto(line, line->window.ws_col,
					line->cur_pos.ws_row - 2) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_col = line->window.ws_col;
		line->cur_pos.ws_row--;
	}
	else
	{
		if (action_str(TC_MOVE_LEFT) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_col--;
	}
	return (SUCCESS);
}

int		action_move_right(t_line *line)
{
	if (IS_ENDLINE)
	{
		if (action_goto(line, 0, line->cur_pos.ws_row + 2) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_row++;
		line->cur_pos.ws_col = 0;
	}
	else
	{
		if (action_str(TC_MOVE_RIGHT) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_col++;
	}
	return (SUCCESS);
}
