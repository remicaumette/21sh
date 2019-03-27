/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_std_close.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 15:29:49 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 15:59:02 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_stdin_close(t_process *process)
{
	close(process->stdin[0]);
	process->isset[0] = 1;
	return (SUCCESS);
}

int		process_stdout_close(t_process *process)
{
	close(process->stdout[1]);
	process->isset[1] = 1;
	return (SUCCESS);
}

int		process_stderr_close(t_process *process)
{
	close(process->stderr[1]);
	process->isset[2] = 1;
	return (SUCCESS);
}
