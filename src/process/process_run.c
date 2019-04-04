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
	close(process->std[STDIN]);
	close(process->std[STDOUT]);
	close(process->std[STDERR]);
	if (wait(&process->pid) == -1)
		return (1);
	process->status = WEXITSTATUS(process->pid);
	return (process->status);
}

static int	handle_child_process(t_process *process)
{
	if (dup2(process->std[STDIN], STDIN_FILENO) == -1)
		close(STDIN_FILENO);
	if (dup2(process->std[STDOUT], STDOUT_FILENO) == -1)
		close(STDOUT_FILENO);
	if (dup2(process->std[STDERR], STDERR_FILENO) == -1)
		close(STDERR_FILENO);
	close(process->std[STDIN]);
	close(process->std[STDOUT]);
	close(process->std[STDERR]);
	if (execve(process->file, process->args, process->env) == -1)
		exit(1);
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
