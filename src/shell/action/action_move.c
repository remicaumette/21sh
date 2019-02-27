/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_move.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/25 20:03:19 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 15:37:03 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_move_left(t_shell *shell)
{
	int		i;

	i = -1;
	if (CURENT_COL == 1)
	{
		if (action_str(TC_MOVE_UP) != SUCCESS)
			return (FAIL);
		CURENT_ROW--;
		while (++i < MAX_COL)
		{
			if (action_str(TC_MOVE_RIGHT) != SUCCESS)
				return (FAIL);
		}
		CURENT_COL = MAX_COL;
	}
	else
	{
		if (action_str(TC_MOVE_LEFT) != SUCCESS)
			return (FAIL);
		CURENT_COL--;
	}
	return (SUCCESS);
}

int		action_move_right(t_shell *shell)
{
	int		i;

	i = 0;
	if (IS_ENDLINE)
	{
		if (action_str(TC_MOVE_DOWN) != SUCCESS)
			return (FAIL);
		CURENT_ROW++;
		while (LINUX && ++i < MAX_COL)
		{
			if (action_str(TC_MOVE_LEFT) != SUCCESS)
				return (FAIL);
		}
		CURENT_COL = 1;
	}
	else
	{
		if (action_str(TC_MOVE_RIGHT) != SUCCESS)
			return (FAIL);
		CURENT_COL++;
	}
	return (SUCCESS);
}
