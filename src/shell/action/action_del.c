/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_del.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:27:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 14:40:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_backdel(t_shell *shell)
{
	if (shell->line->cursor > 1)
	{
		if (action_move_left(shell->line) != SUCCESS)
			return (FAIL);
		if (action_str(TC_DEL) != SUCCESS)
			return (FAIL);
		line_backdel(shell->line);
	}
	return (SUCCESS);
}
