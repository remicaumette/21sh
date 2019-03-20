/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_debug.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:21:09 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:21:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#ifdef USE_DEBUG

t_ret		action_debug(t_shell *shell)
{
	line_debug(shell->line);
	return (RET_EGAIN);
}
#endif
