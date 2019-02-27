/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/12 14:27:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_move_next_word(t_shell *shell)
{
	char	*tmp;

	tmp = shell->line->content;
	if (shell->line->size > 0 && (shell->line->size > CURSOR))
	{
		while (tmp[CURSOR - 1] && tmp[CURSOR - 1] != ' ')
			action_arrow_right(shell);
		while (tmp[CURSOR - 1] && tmp[CURSOR - 1] == ' ')
			action_arrow_right(shell);
	}
	return (SUCCESS);
}

int		action_move_prev_word(t_shell *shell)
{
	char	*tmp;

	tmp = shell->line->content;
	if (CURSOR > 1)
	{
		action_arrow_left(shell);
		while (CURSOR > 1 && tmp[CURSOR - 1] == ' ')
			action_arrow_left(shell);
		while (CURSOR > 1 && tmp[CURSOR - 2] != ' ')
			action_arrow_left(shell);
	}
	return (SUCCESS);
}
