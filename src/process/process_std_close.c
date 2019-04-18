/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_close.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 15:29:49 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:33:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_close(t_process *process)
{
	if (process->STDIN != -1)
		close(process->STDIN);
	process->STDIN = -1;
	return (SUCCESS);
}

int		process_stdout_close(t_process *process)
{
	if (process->STDOUT != -1)
		close(process->STDOUT);
	process->STDOUT = -1;
	process->err_to_out = 0;
	return (SUCCESS);
}

int		process_stderr_close(t_process *process)
{
	if (process->STDERR != -1)
		close(process->STDERR);
	process->STDERR = -1;
	process->out_to_err = 0;
	return (SUCCESS);
}
