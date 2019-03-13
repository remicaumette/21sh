#include "process.h"

int		process_wait(t_process *process)
{
	if (wait(&process->pid) == -1)
		return (FAIL);
	process->status = WEXITSTATUS(process->pid);
	return (process->error);
}
