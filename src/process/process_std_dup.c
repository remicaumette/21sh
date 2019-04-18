/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_dup.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 11:38:45 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/18 13:59:20 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_dup(int stdin, t_process *process)
{
	if (dup2(stdin, process->STDIN) == -1)
		return (FAIL);
	return (SUCCESS);
}

int		process_stdout_dup(int stdout, t_process *process)
{
	if (dup2(stdout, process->STDOUT) == -1)
		return (FAIL);
	process->out_to_err = 0;
	return (SUCCESS);
}

int		process_stderr_dup(int stderr, t_process *process)
{
	if (dup2(stderr, process->STDERR) == -1)
		return (FAIL);
	process->err_to_out = 0;
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
