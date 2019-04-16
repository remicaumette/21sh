/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtin_std_default.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:31:05 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:31:07 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		builtin_stdin_default(t_builtin *builtin)
{
	if ((builtin_stdin_dup(STDIN_FILENO, builtin)) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		builtin_stdout_default(t_builtin *builtin)
{
	if ((builtin_stdout_dup(STDOUT_FILENO, builtin)) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		builtin_stderr_default(t_builtin *builtin)
{
	if ((builtin_stderr_dup(STDERR_FILENO, builtin)) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		builtin_stdall_default(t_builtin *builtin)
{
	if (builtin_stdin_default(builtin) != SUCCESS ||
		builtin_stdout_default(builtin) != SUCCESS ||
		builtin_stderr_default(builtin) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
