#include "shell.h"

# ifdef USE_DEBUG

static void	print_arr(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
	{
		dprintf(g_fd_debug, "\t{NULL}\n");
		return;
	}
	while (arr[i])
	{
		dprintf(g_fd_debug, "\t[%d]: %s\n", i, arr[i]);
		i++;
	}
}

void		process_debug(t_process *process, const char *str)
{
	dprintf(g_fd_debug, "%s\n", str);
	dprintf(g_fd_debug, "\n Process debug\n");
	dprintf(g_fd_debug, "<FILE>%s</FILE>\n", process->file);
	dprintf(g_fd_debug, "<CWD>%s</CWD>\n", process->cwd);
	dprintf(g_fd_debug, "<ARGS>\n");
	print_arr(process->args);
	dprintf(g_fd_debug, "</ARGS>\n");
//	dprintf(g_fd_debug, "<ENV>\n");
//	print_arr(process->env);
//	dprintf(g_fd_debug, "</ENV>\n");
	dprintf(g_fd_debug, "<STATUS>%d</STATUS>\n", process->status);
	dprintf(g_fd_debug, "<ERROR>%d</ERROR>\n", process->error);
	dprintf(g_fd_debug, "<STDIN>%d ; %d</STDIN>\n", process->stdin[0], process->stdin[1]);
	dprintf(g_fd_debug, "<STDOUT>%d ; %d</STDOUT>\n", process->stdout[0], process->stdout[1]);
	dprintf(g_fd_debug, "<STDERR>%d ; %d</STDERR>\n", process->stderr[0], process->stderr[1]);
}
#endif
