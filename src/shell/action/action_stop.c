/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_stop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:08:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:08:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret			action_stop(t_shell *shell)
{
	if (shell->line->size <= 0)
	{
		ft_putstr("\n");
		return (FAIL); // replace by exit
	}
	return (RET_EGAIN);
}
