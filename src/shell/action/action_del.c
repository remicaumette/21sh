/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_del.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:27:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:24:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int		action_del(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_first > 0)
	{
		if ((tmp = tgetstr(TC_MOVE_LEFT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if ((tmp = tgetstr(TC_DEL, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		ft_cursordel_current(shell->cursor);
	}
	return (EGAIN);
}
