/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_close.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 15:29:49 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 14:22:19 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_close(t_process *process)
{
	if (process->std[STDIN] != -1)
		close(process->std[STDIN]);
	process->isset[STDIN] = 1;
	return (SUCCESS);
}

int		process_stdout_close(t_process *process)
{
	if (process->std[STDOUT] != -1)
		close(process->std[STDOUT]);
	process->isset[STDOUT] = 1;
	return (SUCCESS);
}

int		process_stderr_close(t_process *process)
{
	if (process->std[STDERR] != -1)
		close(process->std[STDERR]);
	process->isset[STDERR] = 1;
	return (SUCCESS);
}
