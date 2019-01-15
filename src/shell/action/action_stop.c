/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_stop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:08:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 15:37:40 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_stop(t_shell *shell)
{
	if (!shell->line->size)
		return (FAIL); // replace by exit
	return (SUCCESS);
}
