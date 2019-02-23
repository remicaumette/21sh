/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_right.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 21:51:23 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_arrow_right(t_shell *shell)
{
	if (shell->line->cursor <= shell->line->size)
	{
		if (action_move_right(shell) != SUCCESS)
			return (FAIL);
		if (shell->line->cursor == shell->line->size)
		{
			if (action_str(TC_INSER_STOP) != SUCCESS)
				return (FAIL);
		}
		shell->line->cursor++;
	}
	return (SUCCESS);
}
