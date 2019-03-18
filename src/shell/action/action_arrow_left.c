/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_left.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/25 21:24:43 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_arrow_left(t_shell *shell)
{
	if (CURSOR > 1)
	{
		if (action_move_left(shell) != SUCCESS)
			return (RET_FAIL);
		if (CURSOR > shell->line->size)
		{
			if (action_str(TC_INSER_START) != SUCCESS)
				return (RET_FAIL);
		}
		CURSOR--;
	}
	return (RET_EGAIN);
}
