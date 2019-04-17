/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_std_dup.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:24 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:31:26 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		builtin_stdin_dup(int stdin, t_builtin *builtin)
{
	if (dup2(stdin, builtin->STDIN) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		builtin_stdout_dup(int stdout, t_builtin *builtin)
{
	if (dup2(stdout, builtin->STDOUT) == -1)
		return (FAIL);
	builtin->out_to_err = 0;
	return (SUCCESS);
}

int		builtin_stderr_dup(int stderr, t_builtin *builtin)
{
	if (dup2(stderr, builtin->STDERR) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		builtin_stdall_dup(int std[3], t_builtin *builtin)
{
	if (builtin_stdin_dup(std[0], builtin) != SUCCESS)
		builtin_stdin_close(builtin);
	if (builtin_stdout_dup(std[1], builtin) != SUCCESS)
		builtin_stdout_close(builtin);
	if (builtin_stderr_dup(std[2], builtin) != SUCCESS)
		builtin_stderr_close(builtin);
	return (SUCCESS);
}
