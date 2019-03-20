/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   term_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:39:41 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:39:43 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		term_destroy(t_term **term)
{
	t_term		*tmp;

	tmp = *term;
	if (tmp != NULL)
	{
		if (tmp->save)
		{
			free(tmp->save);
			tmp->save = NULL;
		}
		if (tmp->my)
		{
			free(tmp->my);
			tmp->my = NULL;
		}
		free(tmp);
	}
	*term = NULL;
}
