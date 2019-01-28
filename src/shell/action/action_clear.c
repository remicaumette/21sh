/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 14:32:14 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_clear(t_shell *shell)
{
	int		i;

	if (action_str(TC_CLEAR) != SUCCESS)
		return (FAIL);
	shell_prompt(shell);
	ft_putstr(shell->line->content);
	i = shell->line->size + 1;
	if (window_getcurentpos(&(shell->line->cur_pos)) != SUCCESS)
		return (FAIL);
	if (shell->line->cursor < i)
	{
		while (i > shell->line->cursor)
		{
			if (action_move_left(shell->line) != SUCCESS)
				return (FAIL);
			i--;
		}
		if (action_str(TC_INSER_START) != SUCCESS)
			return (FAIL);
	}
	return (SUCCESS);
}

int		action_clear_to_end(t_shell *shell)
{
	if (shell->line->cursor < (shell->line->size + 1))
	{
		if (action_str(TC_CLEAR_TO_END) != SUCCESS)
			return (FAIL);
		line_deltoend(shell->line);
	}
	return (SUCCESS);
}
