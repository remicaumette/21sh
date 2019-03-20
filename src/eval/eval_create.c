/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_create.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 18:17:56 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 18:17:58 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "eval.h"

t_eval		*eval_create(t_process *process)
{
	t_eval		*out;

	if (!(out = ft_memalloc(sizeof(t_eval))))
		return (NULL);
	out->process = process;
	out->next = NULL;
	return (out);
}
