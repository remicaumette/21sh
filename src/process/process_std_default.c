/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_default.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:35:25 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:58:35 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_default(t_process *process)
{
	if (dup2(STDIN_FILENO, process->stdin[0]) == -1)
		return (FAIL);
	process->isset[0] = 1;
	return (SUCCESS);
}

int		process_stdout_default(t_process *process)
{
	if (dup2(STDOUT_FILENO, process->stdout[1]) == -1)
		return (FAIL);
	process->isset[1] = 1;
	return (SUCCESS);
}

int		process_stderr_default(t_process *process)
{
	if (dup2(STDERR_FILENO, process->stderr[1]) == -1)
		return (FAIL);
	process->isset[2] = 1;
	return (SUCCESS);
}

int		process_stdall_default(t_process *process)
{
	if (process_stdin_default(process) != SUCCESS ||
		process_stdout_default(process) != SUCCESS ||
		process_stderr_default(process) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int		process_stdall_default_isset(t_process *process)
{
	if (!process->isset[0])
		process_stdin_default(process);
	if (!process->isset[1])
		process_stdout_default(process);
	if (!process->isset[2])
		process_stderr_default(process);
	return (SUCCESS);
}
