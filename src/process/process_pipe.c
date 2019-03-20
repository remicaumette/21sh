/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_pipe.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:33:49 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:34:01 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "process.h"

int		process_pipe(t_process *src_out, t_process *dst_in)
{
	if (dup2(src_out->stdout[1], dst_in->stdin[0]) == -1)
		return (FAIL);
//	dprintf(g_fd_debug, "stdout_pipe, src_out->stdout[1]:%d -> dst_in->stdin[0]:%d\n",  src_out->stdout[1], dst_in->stdin[0]);
	return (SUCCESS);
}
