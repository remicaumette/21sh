/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 18:09:04 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	eval_pipe(t_eval *e1, t_eval *e2)
{
	int		fdpipe[2];

	if (pipe(fdpipe) == -1)
		return (FAIL);
	if (e1->process)
	{
		if (e1->process->err_to_out)
			process_stderr_dup(fdpipe[1], e1->process);
		if (!e1->process->out_to_err)
			process_stdout_dup(fdpipe[1], e1->process);
	}
	else if (e1->builtin)
	{
		if (e1->builtin->err_to_out)
			builtin_stderr_dup(fdpipe[1], e1->builtin);
		if (!e1->builtin->out_to_err)
			builtin_stdout_dup(fdpipe[1], e1->builtin);
	}
	if (e2->process)
		process_stdin_dup(fdpipe[0], e2->process);
	else
		builtin_stdin_dup(fdpipe[0], e2->builtin);
	close(fdpipe[0]);
	close(fdpipe[1]);
	return (SUCCESS);
}

int			eval_line(t_node *curr, t_shell *shell)
{
	int			pipe;
	t_eval		*tmp;

	pipe = 0;
	tmp = shell->eval;
	while (curr && curr->type != TOKEN_NEWLINE)
	{
		if (curr->type == TOKEN_WORD)
		{
			expand_command(shell, curr->command);
			if (eval_command(curr, &tmp->next, shell) != SUCCESS)
				return (eval_destroy(&shell->eval->next));
			if (pipe)
				eval_pipe(tmp, tmp->next);
			tmp = tmp->next;
		}
		else if (curr->type == TOKEN_PIPE)
			pipe = 1;
		curr = curr->next;
	}
	pipe = run_eval(shell->eval->next, shell);
	shell->eval->next = NULL;
	return (pipe);
}
