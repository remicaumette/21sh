/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_stop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/14 11:08:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 12:12:41 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "line_edit.h"

int		action_stop(t_shell *shell)
{
	if (shell->cursor->current == NULL)
		return (STOP);
	return (SUCCESS);
}
