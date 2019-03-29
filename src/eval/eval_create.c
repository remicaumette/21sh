/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:17:56 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 16:41:18 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "eval.h"

t_eval		*eval_create(t_builtin *builtin, t_process *process)
{
	t_eval		*out;

	if (!(out = ft_memalloc(sizeof(t_eval))))
		return (NULL);
	if (builtin)
		out->builtin = builtin;
	else
		out->builtin = NULL;
	if (process)
		out->process = process;
	else
		out->process = NULL;
	out->next = NULL;
	return (out);
}
