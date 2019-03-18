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

static int	shell_loop(t_shell *shell)
{
	t_ret	ret;

	while (101)
	{
		if (shell_prompt(shell) != SUCCESS)
			return (shell_stop(shell, FAIL));
		if (term_getcurentpos(&(shell->line->cur_pos)) != SUCCESS)
			return (shell_stop(shell, FAIL));
		ret = shell_getline(shell);
		if (ret != RET_SUCCESS)
		{
			if (ret == RET_STOP)
				return (shell_stop(shell, SUCCESS));
			if (ret == RET_FAIL)
				return (shell_stop(shell, FAIL));
		}
		shell_processline(shell);
	}
	return (shell_stop(shell, 3));
}

int			shell_start(t_shell *shell)
{
	if (term_row_start(shell) != SUCCESS)
		return(FAIL);
	term_resize(shell);
	init_signal();
	return (shell_loop(shell));
}
