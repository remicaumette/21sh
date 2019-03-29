/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_tab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/29 10:10:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 10:10:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_tab(t_shell *shell)
{
	int		i;

	i = 5;
	while (--i)
	{
		if (line_inser(shell->line, ' ') != SUCCESS)
			return (RET_FAIL);
		action_putchar(shell, ' ');
	}
	return (RET_EGAIN);
}
