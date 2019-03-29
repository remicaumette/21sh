/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:02 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:56:06 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		eval_destroy(t_eval **eval)
{
	t_eval		*tmp;
	t_eval		*tmp_next;

	tmp = *eval;
	while (tmp)
	{
		builtin_destroy(&tmp->builtin);
		process_destroy(&tmp->process);
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
	*eval = NULL;
}

int			eval_reset(t_eval *eval)
{
	t_eval		*tmp;

	tmp = eval->next;
	eval_destroy(&tmp);
	eval->next = NULL;
	return (FAIL);
}
