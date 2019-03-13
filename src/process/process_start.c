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
	dprintf(g_fd_debug, "Child, process->stdin[0]:%d -> STDIN_FILENO\n", process->stdin[0]);
	dprintf(g_fd_debug, "Child, process->stdout[1]:%d -> STDOUT_FILENO\n", process->stdout[1]);
	dprintf(g_fd_debug, "Child, process->stderr[1]:%d -> STDERR_FILENO\n", process->stderr[1]);
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
