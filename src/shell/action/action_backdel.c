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

static t_ret		multi_line(t_shell *shell)
{
	int		i;

	i = -1;
	if (action_str(TC_INSER_STOP) != SUCCESS)
		return (RET_FAIL);
	if (action_str(TC_CLEAR_TO_END) != SUCCESS)
		return (RET_FAIL);
	action_putstr(shell, &(shell->line->content[CURSOR - 1]));
	while (++i <= (shell->line->size - CURSOR))
	{
		if (action_move_left(shell) != SUCCESS)
			return (RET_FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (RET_FAIL);
	return (RET_EGAIN);
}

t_ret				action_backdel(t_shell *shell)
{
	if (shell->line->cursor > 1)
	{
		line_backdel(shell->line);
		if (action_move_left(shell) != SUCCESS)
			return (RET_FAIL);
		if (CURENT_COL >= MAX_COL)
		{
			if (action_str(TC_CLEAR_END_LINE) != SUCCESS)
				return (RET_FAIL);
		}
		else
		{
			if (action_str(TC_DEL) != SUCCESS)
				return (RET_FAIL);
		}
		if (((shell->line->size + 2) / MAX_COL) > ((CURSOR + 2) / MAX_COL))
		{
			if (multi_line(shell) != RET_EGAIN)
				return (RET_FAIL);
		}
	}
	return (RET_EGAIN);
}
