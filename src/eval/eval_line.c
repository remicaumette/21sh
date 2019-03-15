#include "shell.h"

static int	run_eval(t_eval *eval)
{
	t_eval		*tmp;

	tmp = eval;
	while (tmp)
	{
		if (process_start(tmp->process))
			return (FAIL);
		tmp = tmp->next;
	}
	tmp = eval;
	while (tmp)
	{
		if (process_wait(tmp->process) != SUCCESS)
			return (FAIL);
		process_destroy(&tmp->process);
		tmp = tmp->next;
	}
	eval_destroy(&eval);
	return (SUCCESS);
}

int			eval_line(t_node *curr, t_shell *shell)
{
	int			pipe;
	t_eval		*tmp;
	t_eval		*line;

	pipe = 0;
	line = NULL;
	if (eval_command(curr, &line, shell) != SUCCESS)
		return (FAIL);
	tmp = line;
	curr = curr->next;
	while (curr && curr->type != TOKEN_NEWLINE)
	{
		if (curr->type == TOKEN_WORD)
		{
			if (eval_command(curr, &tmp->next, shell) != SUCCESS)
				return (FAIL);
			if (pipe)
				process_pipe(tmp->process, tmp->next->process);
			tmp = tmp->next;
		}
		else if (curr->type == TOKEN_PIPE)
			pipe = 1;
		curr = curr->next;
	}
	return (run_eval(line));
}
