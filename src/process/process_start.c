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
	close(process->stdin[1]);
	close(process->stdout[0]);
	close(process->stderr[0]);
	return (SUCCESS);
}

static void	child_process(t_process *process)
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

int			process_start(t_process *process)
{
	if ((process->pid = fork()) == -1)
		return (1);
	if (process->pid == 0)
		child_process(process);
	main_process(process);
	return (SUCCESS);
}
