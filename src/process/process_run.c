/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_run.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:37:58 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:54:53 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

static int	handle_main_process(t_process *process)
{
	close(process->stdin[1]);
	close(process->stdout[0]);
	close(process->stderr[0]);
	if (wait(&process->pid) == -1)
		return (1);
	process->status = WEXITSTATUS(process->pid);
	return (process->error);
}

static int	handle_child_process(t_process *process)
{
	if (dup2(process->stdin[0], STDIN_FILENO) == -1 ||
		dup2(process->stdout[1], STDOUT_FILENO) == -1 ||
		dup2(process->stderr[1], STDERR_FILENO) == -1)
	{
		process->error = 1;
		exit(1);
	}
	close(process->stdin[0]);
	close(process->stdout[1]);
	close(process->stderr[1]);
	if (execve(process->file, process->args, process->env) == -1)
	{
		process->error = 1;
		exit(1);
	}
	exit(0);
}

int			process_run(t_process *process)
{
	if ((process->pid = fork()) == -1)
		return (1);
	if (process->pid == 0)
		return (handle_child_process(process));
	return (handle_main_process(process));
}
