/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_right.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 21:51:23 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_arrow_right(t_shell *shell)
{
	if (CURSOR <= shell->line->size)
	{
		if (action_move_right(shell) != SUCCESS)
			return (RET_FAIL);
		if (CURSOR == shell->line->size)
		{
			if (action_str(TC_INSER_STOP) != SUCCESS)
				return (RET_FAIL);
		}
		CURSOR++;
	}
	return (RET_EGAIN);
}
