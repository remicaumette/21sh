/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_hist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:24:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 12:57:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int					action_hist_up(t_shell *shell)
{
	t_histentry	*entry;
	char		*tmp;

	if ((entry = shell->history->curr ? shell->history->curr : shell->history->begin))
	{
		shell->history->curr = entry->next;
		if (!(tmp = tgetstr(TC_DEL_LINE, NULL)))
			return (FAIL);
		ft_putstr(tmp);
		ft_putstr("$ ");
		ft_putstr(entry->content);
		line_replace(shell->line, ft_strdup(entry->content));
	}
	return (SUCCESS);
}

int					action_hist_down(t_shell *shell)
{
	// char	*hist;
	// char	*tmp;

	// hist = NULL;
	// hist_getdown(&hist);
	// if ((tmp = tgetstr(TC_DEL_LINE, NULL)) == NULL)
	// 	return (FAIL);
	// ft_putstr(tmp);
	// ft_putstr("$ ");
	// ft_putstr(hist);
	// line_replace(shell->line, hist);
	(void)shell;
	return (SUCCESS);
}
