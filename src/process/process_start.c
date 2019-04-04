/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_start.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:35:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:48:25 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

static int	main_process(t_process *process)
{
	process_stdin_close(process);
	process_stdout_close(process);
	process_stderr_close(process);
	return (SUCCESS);
}

static void	child_process(t_process *process)
{
	if (process->std[STDIN] != -1 &&
			dup2(process->std[STDIN], STDIN_FILENO) == -1)
		close(STDIN_FILENO);
	if (process->std[STDOUT] != -1 &&
			dup2(process->std[STDOUT], STDOUT_FILENO) == -1)
		close(STDOUT_FILENO);
	if (process->std[STDERR] != -1 &&
			dup2(process->std[STDERR], STDERR_FILENO) == -1)
		close(STDERR_FILENO);
	process_stdin_close(process);
	process_stdout_close(process);
	process_stderr_close(process);
	if (execve(process->file, process->args, process->env) == -1)
		exit(1);
	exit(0);
}

int			process_start(t_process *process)
{
	if ((process->pid = fork()) == -1)
		return (FAIL);
	if (process->pid == 0)
		child_process(process);
	main_process(process);
	return (SUCCESS);
}

int			process_run(t_process *process)
{
	if (process_start(process) != SUCCESS)
		return (FAIL);
	if (process_wait(process) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}
