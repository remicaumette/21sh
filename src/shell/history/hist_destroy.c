/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hist_destroy.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/20 16:29:28 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/20 16:29:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		hist_destroy(void)
{
	t_hist			*tmp;
	t_hist			*tmp_next;
	t_stackhist		*history;

	history = hist();
	if (history->size == 0)
		return ;
	history->first->prev = NULL;
	history->last->next = NULL;
	tmp = history->first;
	while (tmp)
	{
		tmp_next = tmp->next;
		FT_HISTDEL_ONE(&tmp, &free);
		tmp = tmp_next;
	}
	history->first = NULL;
	history->last = NULL;
	history->tmp = NULL;
	history->size = 0;
}
