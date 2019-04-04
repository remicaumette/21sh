/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_kill.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:41:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:41:19 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		shell_kill(t_shell *shell)
{
	static t_shell *save = NULL;

	if (shell)
		save = shell;
	else
	{
		if (save)
			save->kill = 1;
	}
}
