/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 15:26:36 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	wait_all(t_eval *eval)
{
	while (eval)
	{
		if (process_wait(eval->process) != SUCCESS)
			return (FAIL);
		process_destroy(&eval->process);
		eval = eval->next;
	}
	return (SUCCESS);
}

static int	run_builtin(t_builtin *builtin, t_shell *shell)
{
	return (builtin->func(ft_strlen_2d((const char **)builtin->argv), builtin->argv, shell));
}

int			run_eval(t_eval *eval, t_shell *shell)
{
	t_eval		*tmp;

	tmp = eval;
	while (tmp)
	{
		if (tmp->builtin)
		{
			run_builtin(tmp->builtin, shell);
		}
		else if (tmp->process)
		{
			if (process_start(tmp->process))
				return (eval_reset(eval));
		}
		tmp = tmp->next;
	}
	if (wait_all(eval) != SUCCESS)
		return (eval_reset(eval));
	eval_reset(eval);
	return (SUCCESS);
}
