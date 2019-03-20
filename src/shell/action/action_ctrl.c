/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_ctrl.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:21:56 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:22:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_ctrl_up(t_shell *shell)
{
	int		i;

	i = MAX_COL;
	if ((CURSOR - MAX_COL) > 0)
	{
		while (i)
		{
			if (action_move_left(shell) != SUCCESS)
				return (RET_FAIL);
			i--;
		}
		CURSOR -= MAX_COL;
	}
	return (RET_SUCCESS);
}

t_ret		action_ctrl_down(t_shell *shell)
{
	int		i;

	i = MAX_COL;
	if ((CURSOR + MAX_COL) < (shell->line->size + 2))
	{
		while (i)
		{
			if (action_move_right(shell) != SUCCESS)
				return (RET_FAIL);
			i--;
		}
		CURSOR += MAX_COL;
	}
	return (RET_SUCCESS);
}
