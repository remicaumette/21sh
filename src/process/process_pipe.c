#include "process.h"

int		process_pipe(t_process *src_out, t_process *dst_in)
{
	if (dup2(src_out->stdout[1], dst_in->stdin[0]) == -1)
		return (FAIL);
	dprintf(g_fd_debug, "stdout_pipe, src_out->stdout[1]:%d -> dst_in->stdin[0]:%d\n",  src_out->stdout[1], dst_in->stdin[0]);
	return (SUCCESS);
}
