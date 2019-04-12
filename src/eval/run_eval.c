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

static void	sighup_befor(t_eval *ref, t_eval *stop)
{
	while (ref != stop)
	{
		if (ref->process)
		{
			kill(ref->process->pid, SIGHUP);
			break ;
		}
		ref = ref->next;
	}
}

static int	wait_all(t_eval *eval)
{
	pid_t		ret_pid;
	t_eval		*tmp;

	ret_pid = 0;
	tmp = NULL;
	while ((ret_pid = wait(NULL)) > 0)
	{
		tmp = eval;
		while (tmp)
		{
			if (tmp->process)
			{
				if (tmp->process->pid == ret_pid)
				{
					process_destroy(&tmp->process);
					sighup_befor(eval, tmp);
					break ;
				}
			}
			tmp = tmp->next;
		}
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
