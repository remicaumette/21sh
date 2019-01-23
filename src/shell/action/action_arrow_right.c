/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_right.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/23 14:09:05 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_arrow_right(t_shell *shell)
{
	int		i;
	int		endline;

	i = 0;
	endline = action_isendline(shell->line);
	if (shell->line->cursor <= shell->line->size)
	{
		if (endline == TRUE)
			action_str(TC_MOVE_DOWN);
		else
			action_str(TC_MOVE_RIGHT);
		if (shell->line->cursor == shell->line->size)
			action_str(TC_INSER_STOP);
		shell->line->cursor++;
	}
	return (SUCCESS);
}
