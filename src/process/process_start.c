/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_start.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:35:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:35:13 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

static int	main_process(t_process *process)
{
	close(process->std[STDIN]);
	close(process->std[STDOUT]);
	close(process->std[STDERR]);
	return (SUCCESS);
}

static void	child_process(t_process *process)
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

int			process_start(t_process *process)
{
	if ((process->pid = fork()) == -1)
		return (FAIL);
	if (process->pid == 0)
		child_process(process);
	main_process(process);
	return (SUCCESS);
}
