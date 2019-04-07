/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_dup.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:38:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:38:46 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_dup(int stdin, t_process *process)
{
	if (process->std[STDIN] == -1)
	{
		if ((process->std[STDIN] = dup(stdin)) == -1)
			return (FAIL);
	}
	else
	{
		if ((dup2(stdin, process->std[STDIN])) == -1)
			return (FAIL);
	}
	process->isset[STDIN] = 1;
	return (SUCCESS);
}

int		process_stdout_dup(int stdout, t_process *process)
{
	if (process->std[STDOUT] == -1)
	{
		if ((process->std[STDOUT] = dup(stdout)) == -1)
			return (FAIL);
	}
	else
	{
		if ((dup2(stdout, process->std[STDOUT])) == -1)
			return (FAIL);
	}
	process->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		process_stderr_dup(int stderr, t_process *process)
{
	if (process->std[STDERR] == -1)
	{
		if ((process->std[STDERR] = dup(stderr)) == -1)
			return (FAIL);
	}
	else
	{
		if ((dup2(stderr, process->std[STDERR])) == -1)
			return (FAIL);
	}
	process->isset[STDERR] = 1;
	return (SUCCESS);
}

int		process_stdall_dup(int std[3], t_process *process)
{
	if (process_stdin_dup(std[0], process) != SUCCESS)
		process_stdin_close(process);
	if (process_stdout_dup(std[1], process) != SUCCESS)
		process_stdout_close(process);
	if (process_stderr_dup(std[2], process) != SUCCESS)
		process_stderr_close(process);
	return (SUCCESS);
}
