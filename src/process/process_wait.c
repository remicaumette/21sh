/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_wait.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:35:53 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/04 11:38:35 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_wait(t_process *process)
{
	if (wait(&process->pid) == -1)
		return (FAIL);
	process->status = WEXITSTATUS(process->pid);
	return (process->status == 0) ? SUCCESS : FAIL;
}
