/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_basic.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 00:26:38 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:23:32 by timfuzea    ###    #+. /#+    ###.fr     */
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
	action_putstr(shell, &(shell->line->content[CURSOR - 2]));
	while (++i <= (shell->line->size - CURSOR))
	{
		if (action_move_left(shell) != SUCCESS)
			return (RET_FAIL);
	}
	if (action_str(TC_INSER_START) != SUCCESS)
		return (RET_FAIL);
	return (RET_EGAIN);
}

t_ret				action_basic(t_shell *shell, long buf)
{
	if (MAX_COL == 0)
	{
		ft_putstr_fd("\n21sh: unexpeted error\n", STDERR_FILENO);
		return (RET_FAIL);
	}
	if (line_inser(shell->line, (char)buf) != SUCCESS)
		return (RET_FAIL);
	if ((((shell->line->size + 2) >= MAX_COL)
				&& (shell->line->size + 2 / MAX_COL)
				> (shell->line->cursor + 2 / MAX_COL)))
	{
		if (multi_line(shell) != RET_EGAIN)
			return (RET_FAIL);
	}
	else
		action_putchar(shell, (char)buf);
	return (RET_EGAIN);
}
