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
		eval = eval->next;
	}
	return (SUCCESS);
}

static int	eval_pipe(t_eval *e1, t_eval *e2)
{
	if (e1->process && e2->process)
		process_pipe(e1->process, e2->process);
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
	eval_stddefault(shell->eval->next);
	return (run_eval(shell->eval, shell));
}
