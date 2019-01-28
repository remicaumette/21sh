/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_up.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:31:42 by rcaumett    ###    #+. /#+    ###.fr     */
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
		ft_putstr(entry->content);
		line_replace(shell->line, ft_strdup(entry->content));
		line_curpp(shell->line, shell->line->size);
	}
	return (SUCCESS);
}
