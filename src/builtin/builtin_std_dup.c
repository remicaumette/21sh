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
	if (builtin->STDIN == -1)
	{
		if ((builtin->STDIN = dup(stdin)) == -1)
			return (FAIL);
	}
	else
	{
		if (dup2(stdin, builtin->STDIN) == -1)
			return (FAIL);
	}
	return (SUCCESS);
}

int		builtin_stdout_dup(int stdout, t_builtin *builtin)
{
	if (builtin->STDOUT == -1)
	{
		if ((builtin->STDOUT = dup(stdout)) == -1)
			return (FAIL);
	}
	else
	{
		if (dup2(builtin->STDOUT, stdout) == -1)
			return (FAIL);
	}
	return (SUCCESS);
}

int		builtin_stderr_dup(int stderr, t_builtin *builtin)
{
	if (builtin->STDERR == -1)
	{
		if ((builtin->STDERR = dup(stderr)) == -1)
			return (FAIL);
	}
	else
	{
		if (dup2(stderr, builtin->STDERR) == -1)
			return (FAIL);
	}
	return (SUCCESS);
}

int		builtin_stdall_dup(int std[3], t_builtin *builtin)
{
	if (builtin_stdin_dup(STDIN, builtin) != SUCCESS)
		builtin_stdin_close(builtin);
	if (builtin_stdout_dup(STDOUT, builtin) != SUCCESS)
		builtin_stdout_close(builtin);
	if (builtin_stderr_dup(STDERR, builtin) != SUCCESS)
		builtin_stderr_close(builtin);
	return (SUCCESS);
}
