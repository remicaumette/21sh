/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 11:43:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int		action_clear(t_shell *shell)
{
	char	*tmp;

	if ((tmp = tgetstr(TC_CLEAR, NULL)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
//	ft_prompt();
	if ((tmp = ft_lCharto_str(shell->cursor->first)) == NULL)
		return (FAIL);
	ft_putstr(tmp);
	ft_strdel(&tmp);
	ft_cursor(CUR_SET_ALL);
	return (SUCCESS);
}

int		action_clear_to_end(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_last > -1)
	{
		if ((tmp = tgetstr(TC_CLEAR_TO_END, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		ft_cursordel_toend(shell->cursor);
	}
	return (SUCCESS);
}
