/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_default.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:35:25 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:24:50 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_default(t_process *process)
{
	if ((process_stdin_dup(STDIN_FILENO, process)) != SUCCESS)
		return (FAIL);
	process->isset[STDIN] = 1;
	return (SUCCESS);
}

int		process_stdout_default(t_process *process)
{
	if ((process_stdout_dup(STDOUT_FILENO, process)) != SUCCESS)
		return (FAIL);
	process->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		process_stderr_default(t_process *process)
{
	if ((process_stderr_dup(STDERR_FILENO, process)) == -1)
		return (FAIL);
	process->isset[STDERR] = 1;
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
	if (!process->isset[STDIN])
		process_stdin_default(process);
	if (!process->isset[STDOUT])
		process_stdout_default(process);
	if (!process->isset[STDERR])
	{
		dprintf(1, "dup stderr\n");
		process_stderr_default(process);
	}
	return (SUCCESS);
}
