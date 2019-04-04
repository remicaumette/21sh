/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:41:55 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	eval_stddefault(t_eval *eval)
{
	while (eval)
	{
		if (eval->process)
			if (process_stdall_default_isset(eval->process) != SUCCESS)
				return (FAIL);
		if (eval->builtin)
			if (builtin_stdall_default_isset(eval->builtin) != SUCCESS)
				return (FAIL);
		eval = eval->next;
	}
	return (SUCCESS);
}

static int	eval_pipe(t_eval *e1, t_eval *e2)
{
	int		fdpipe[2];

	if (pipe(fdpipe) == -1)
		return (FAIL);
	if (e1->process)
		process_stdout_dup(fdpipe[1], e1->process);
	else
		builtin_stdout_dup(fdpipe[1], e1->builtin);
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
			if (eval_command(curr, &tmp->next, shell) != SUCCESS)
				return (FAIL);
			if (pipe)
				eval_pipe(tmp, tmp->next);
			tmp = tmp->next;
		}
		else if (curr->type == TOKEN_PIPE)
			pipe = 1;
		curr = curr->next;
	}
	tmp = shell->eval->next;
	shell->eval->next = NULL;
	eval_stddefault(tmp);
	return (run_eval(tmp, shell));
}
