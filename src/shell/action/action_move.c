/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 20:03:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 15:37:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_move_left(t_line *line)
{
	int		i;

	i = -1;
	if (IS_BEGINLINE)
	{
		if (action_str(TC_MOVE_UP) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_row--;
		while (++i < line->window.ws_col)
		{
			if (action_str(TC_MOVE_RIGHT) != SUCCESS)
				return (FAIL);
		}
		line->cur_pos.ws_col = line->window.ws_col;
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
	int		i;

	i = 0;
	if (IS_ENDLINE)
	{
		if (action_str(TC_MOVE_DOWN) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_row++;
		while (LINUX && ++i < line->window.ws_col)
		{
			if (action_str(TC_MOVE_LEFT) != SUCCESS)
				return (FAIL);
		}
		line->cur_pos.ws_col = 1;
	}
	else
	{
		if (action_str(TC_MOVE_RIGHT) != SUCCESS)
			return (FAIL);
		line->cur_pos.ws_col++;
	}
	return (SUCCESS);
}
