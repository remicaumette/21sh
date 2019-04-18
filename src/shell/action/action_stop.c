/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_stop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:08:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:27:56 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret			action_stop(t_shell *shell)
{
	if (shell->line->size <= 0)
		return (RET_STOP);
	return(action_del(shell));
	return (RET_EGAIN);
}
