/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 18:08:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_arrow_up(t_shell *shell)
{
	t_histentry *entry;

	if ((entry = shell->history->curr ? shell->history->curr : shell->history->begin))
	{
		shell->history->curr = entry->next;

		if (action_home(shell) != SUCCESS)
			return (FAIL);
		if (action_str(TC_CLEAR_TO_END) != SUCCESS)
			return (FAIL);
		line_replace(shell->line, ft_strdup(entry->content));
		action_putstr(shell, entry->content);
	}
	return (SUCCESS);
}
