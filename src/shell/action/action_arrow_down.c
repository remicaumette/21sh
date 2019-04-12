/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_down.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:50:24 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		save_line(t_shell *shell)
{
	if (shell->line->content)
	{
		if (shell->history->tmp)
			ft_strdel(&shell->history->tmp);
		if ((shell->history->tmp = ft_strdup(shell->line->content)) == NULL)
			return (FAIL);
	}
	else
		shell->history->tmp = NULL;
	return (SUCCESS);
}

static t_ret	restor_line(t_shell *shell)
{
	if (shell->history->tmp)
	{
		line_replace(shell->line, ft_strdup(shell->history->tmp));
		action_putstr(shell, shell->history->tmp);
	}
	else
		line_replace(shell->line, NULL);
	return (RET_EGAIN);
}

t_ret	action_arrow_down(t_shell *shell)
{
	t_histentry *entry;

	if (action_home(shell) != RET_EGAIN)
		return (RET_FAIL);
	if (action_str(TC_CLEAR_TO_END) != SUCCESS)
		return (RET_FAIL);
	if (shell->history->curr == NULL)
	{
		save_line(shell);
		shell->history->curr = shell->history->end;
	}
	else
		shell->history->curr = shell->history->curr->prev;
	entry = shell->history->curr;
	if (entry == NULL)
		return (restor_line(shell));
	line_replace(shell->line, ft_strdup(entry->content));
	action_putstr(shell, entry->content);
	return (RET_EGAIN);
}
