/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_home.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:33:54 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:34:01 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_home(t_shell *shell)
{
	while (CURSOR > 1)
		action_arrow_left(shell);
	return (RET_EGAIN);
}
