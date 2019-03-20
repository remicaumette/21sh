/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:20:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_arrow_up(t_shell *shell)
{
	t_histentry *entry;

	if ((entry = shell->history->curr
				? shell->history->curr : shell->history->begin))
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
