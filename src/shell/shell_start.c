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

static int	shell_loop(t_shell *shell)
{
	t_ret	ret;

	while (101)
	{
		if (shell_prompt(shell) != SUCCESS)
			return (FAIL);
		ret = shell_getline(shell);
		if (ret != RET_SUCCESS)
		{
			if (ret == RET_STOP)
				return (SUCCESS);
			if (ret == RET_FAIL)
				return (FAIL);
		}
		shell_processline(shell);
	}
	return (FAIL);
}

int			shell_start(t_shell *shell)
{
	term_row_start(shell);
	term_resize(shell);
	init_signal();
	term_row_stop(shell);
	return (shell_loop(shell));
}
