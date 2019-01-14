/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_hist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:24:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 11:44:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

static inline void	feed_cursor(t_shell *shell, const char *str)
{
	ft_cursor(CUR_RESET);
	while (*str)
	{
		ft_cursoradd((long)*str, shell->cursor);
		str++;
	}
}

int					action_hist_up(t_shell *shell)
{
	char	*hist;
	char	*tmp;

	if (ft_histget_up(&hist) == FAIL)
		return (FAIL);
	if ((tmp = tgetstr(TC_DEL_LINE, NULL)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
	ft_putstr("$ ");
	ft_putstr(hist);
	feed_cursor(shell, hist);
	ft_strdel(&hist);
	return(SUCCESS);
}

int					action_hist_down(t_shell *shell)
{
	char	*hist;
	char	*tmp;

	if (ft_histget_down(&hist) == FAIL)
		return (FAIL);
	if ((tmp = tgetstr(TC_DEL_LINE, NULL)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
	ft_putstr("$ ");
	ft_putstr(hist);
	feed_cursor(shell, hist);
	ft_strdel(&hist);
	return(SUCCESS);
}
