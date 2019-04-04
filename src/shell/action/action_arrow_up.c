/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 15:50:39 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_arrow_up(t_shell *shell)
{
	t_histentry *entry;

	if ((entry = shell->history->curr
					? shell->history->curr
					: shell->history->begin) &&
		shell->missing_token == -1)
	{
		shell->history->curr = entry->next;
		if (action_home(shell) != RET_EGAIN)
			return (RET_FAIL);
		if (action_str(TC_CLEAR_TO_END) != SUCCESS)
			return (RET_FAIL);
		line_replace(shell->line, ft_strdup(entry->content));
		action_putstr(shell, entry->content);
	}
	return (RET_EGAIN);
}
