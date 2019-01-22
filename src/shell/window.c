/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 13:25:21 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:40:00 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		window_resize(t_shell *shell)
{
	static	t_shell		*shell_save = NULL;

	if (shell_save == NULL && shell)
		shell_save = shell;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &(shell_save->line->window));
}
