/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_hist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:24:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:27:22 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int					action_hist_up(t_shell *shell)
{
	char	*hist;
	char	*tmp;

	hist = NULL;
	hist_getup(&hist);
	if ((tmp = tgetstr(TC_DEL_LINE, NULL)) == NULL)
	{
		dprintf(1, "success");
		return (FAIL);
	}
	ft_putstr(tmp);
	ft_putstr("$ ");
	ft_putstr(hist);
	line_replace(shell->line, hist);
	return (SUCCESS);
}

int					action_hist_down(t_shell *shell)
{
	char	*hist;
	char	*tmp;

	hist = NULL;
	hist_getdown(&hist);
	if ((tmp = tgetstr(TC_DEL_LINE, NULL)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
	ft_putstr("$ ");
	ft_putstr(hist);
	line_replace(shell->line, hist);
	return (SUCCESS);
}
