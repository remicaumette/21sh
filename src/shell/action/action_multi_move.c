/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:26:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int		action_move_first(t_shell *shell)
{
	while (shell->cursor->dist_first > 0)
		action_move_left(shell);
	return (EGAIN);
}

int		action_move_end(t_shell *shell)
{
	while (shell->cursor->dist_last != -1)
		action_move_right(shell);
	return (EGAIN);
}

int		action_move_next_word(t_shell *shell)
{
	if (shell->cursor->dist_last >= 0)
	{
		while (shell->cursor->current && shell->cursor->current->c != ' ')
			action_move_right(shell);
		while (shell->cursor->current && shell->cursor->current->c == ' ')
			action_move_right(shell);
	}
	return (EGAIN);
}

int		action_move_prev_word(t_shell *shell)
{
	if (shell->cursor->dist_first > 0)
	{
		action_move_left(shell);
		while (shell->cursor->current->c == ' ')
			action_move_left(shell);
		while (shell->cursor->dist_first != 0
				&& shell->cursor->current->prev->c != ' ')
			action_move_left(shell);
	}
	return (EGAIN);
}
