/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_start.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:15:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 17:14:57 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	shell_stop(t_shell *shell, int status)
{
	term_row_stop(shell);
	return (status);
}

static int	shell_readline(t_shell *shell)
{
	int		readed;
	long	buf;

	buf = 0;
	if (shell_prompt(shell) != SUCCESS)
		return (shell_stop(shell, 1));
	if (term_getcurentpos(&(shell->line->cur_pos)) != SUCCESS)
		return (shell_stop(shell, 1));
	while ((readed = read(0, &buf, sizeof(buf))) > 0)
	{
		if (shell_actiondispatcher(shell, buf))
			return (shell_stop(shell, 1));
		buf = 0;
	}
	return (shell_stop(shell, 0));
}

int			shell_start(t_shell *shell)
{
	if (term_row_start(shell) != SUCCESS)
		return(FAIL);
	term_resize(shell);
	init_signal();
	return (shell_readline(shell));
}
