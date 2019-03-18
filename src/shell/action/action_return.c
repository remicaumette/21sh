/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_return.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 15:28:52 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 15:38:19 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_ret		action_return(t_shell *shell)
{
	(void)shell;
	write(1, "\n", 1);
	return (RET_SUCCESS);
}
