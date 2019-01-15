/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 11:02:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"


int			action_move_up(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_first > shell->cursor->winsize.ws_row)
	{
		if ((tmp = tgetstr(TC_MOVE_UP, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		shell->cursor->pos.y--;
	}
	return (SUCCESS);
}

int			action_move_down(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_last > shell->cursor->winsize.ws_row)
	{
		if ((tmp = tgetstr(TC_MOVE_DOWN, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		shell->cursor->pos.y++;
	}
	return (SUCCESS);
}

/*
**	<-
*/
int			action_move_left(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_first > 0)
	{
		if ((tmp = tgetstr(TC_MOVE_LEFT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if (shell->cursor->dist_last == -1)
		{
			if ((tmp = tgetstr(TC_INSER_START, NULL)) == NULL)
				return (FAIL);
			ft_putstr(tmp);
			shell->cursor->current = shell->cursor->last;
		}
		else if (shell->cursor->current->prev)
			shell->cursor->current = shell->cursor->current->prev;
		shell->cursor->dist_first--;
		shell->cursor->dist_last++;
	}
	return (SUCCESS);
}

/*
**	->
*/
int			action_move_right(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_last >= 0)
	{
		if ((tmp = tgetstr(TC_MOVE_RIGHT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if (shell->cursor->dist_last == 0)
		{
			if ((tmp = tgetstr(TC_INSER_STOP, NULL)) == NULL)
				return (FAIL);
			ft_putstr(tmp);
		}
		shell->cursor->current = shell->cursor->current->next;
		shell->cursor->dist_first++;
		shell->cursor->dist_last--;
	}
	return (SUCCESS);
}
