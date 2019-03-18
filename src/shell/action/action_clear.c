/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:14:21 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_clear(t_shell *shell)
{
	int		i;

	if (action_str(TC_CLEAR) != SUCCESS)
		return (RET_FAIL);
	if (shell_prompt(shell) != SUCCESS)
		return (RET_FAIL);
	if (term_getcurentpos(&(shell->line->cur_pos)) != SUCCESS)
		return (RET_FAIL);
	action_putstr(shell ,shell->line->content);
	i = shell->line->size + 1;
	if (CURSOR < i)
	{
		while (i > CURSOR)
		{
			if (action_move_left(shell) != SUCCESS)
				return (RET_FAIL);
			i--;
		}
		if (action_str(TC_INSER_START) != SUCCESS)
			return (RET_FAIL);
	}
	return (RET_EGAIN);
}

t_ret		action_clear_to_end(t_shell *shell)
{
	if (CURSOR < (shell->line->size + 1))
	{
		if (action_str(TC_CLEAR_TO_END) != SUCCESS)
			return (RET_FAIL);
		line_deltoend(shell->line);
	}
	return (RET_EGAIN);
}
