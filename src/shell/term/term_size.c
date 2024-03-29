/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term_size.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:40:50 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:40:54 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		term_resize(t_shell *shell)
{
	static	t_shell		*shell_save = NULL;
	static int			lock = 0;

	if (lock == 1)
	{
		while (lock)
			continue;
	}
	lock = 1;
	if (shell_save == NULL && shell)
	{
		shell_save = shell;
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &(shell->line->window));
	}
	if (!shell)
		action_clear(shell_save);
	lock = 0;
}
