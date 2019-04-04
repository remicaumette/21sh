/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   run_eval.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:31 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 14:24:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	wait_all(t_eval *eval)
{
	while (eval)
	{
		if (eval->process)
		{
			if (process_wait(eval->process) != SUCCESS)
				return (FAIL);
			process_destroy(&eval->process);
		}
		eval = eval->next;
	}
	return (SUCCESS);
}

static int	run_builtin(t_builtin *builtin, t_shell *shell)
{
	int		ret;

	ret = 0;
	ret = builtin->func(ft_strlen_2d((const char **)builtin->argv),
		builtin->argv, builtin->std, shell);
	builtin_stdall_close(builtin);
	return (ret);
}

int			run_eval(t_eval *eval, t_shell *shell)
{
	t_eval		*tmp;

	tmp = eval;
	while (tmp)
	{
		if (tmp->builtin)
			run_builtin(tmp->builtin, shell);
		else if (tmp->process)
		{
			if (process_start(tmp->process))
				return (eval_destroy(&eval));
		}
		tmp = tmp->next;
	}
	if (wait_all(eval) != SUCCESS)
		return (eval_destroy(&eval));
	eval_destroy(&eval);
	return (SUCCESS);
}
