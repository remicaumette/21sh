#include "eval.h"

int			eval_heredoc(t_redirection *redirection, t_process *process, t_shell *shell)
{
	t_line		*save;

	save = shell->line;
	if ((shell->line = line_create()) == NULL)
		return (FAIL);
	while (101)
	{
		ft_putstr("heredoc> ");
		if (shell_getline(shell) == RET_FAIL)
		{
			dprintf(1, "FAIL getline\n");
			return (FAIL);
		}
		if (ft_strequ(shell->line->content, redirection->file) == 1)
			break;
		ft_putendl_fd(shell->line->content, process->stdin[1]);
		line_reset(shell->line);
	}
	close(process->stdin[1]);
	line_destroy(&shell->line);
	shell->line = save;
	return (SUCCESS);
}
