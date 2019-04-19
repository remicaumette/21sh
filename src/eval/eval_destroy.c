/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:18:02 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/19 18:13:53 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			eval_destroy(t_eval **eval)
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
	return (FAIL);
}
