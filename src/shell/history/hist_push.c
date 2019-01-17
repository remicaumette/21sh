/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hist_push.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 15:26:08 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 14:11:29 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void			del_first(t_stackhist *history)
{
	t_hist		*tmp;

	tmp = history->first;
	history->first = tmp->next;
	FT_HISTDEL_ONE(&tmp, &free);
	history->first->prev = history->last;
	history->size--;
}

static inline void	push(t_hist *new, t_stackhist *history)
{
	if (history->first)
	{
		history->first->prev = new;
		history->last->next = new;
	}
	else
	{
		history->first = new;
	}
	new->next = history->first;
	new->prev = history->last;
	history->last = new;
	history->tmp = NULL;
	history->size++;
}

int					hist_push(const char *str)
{
	int				size_max;
	t_hist			*tmp;
	t_stackhist		*history;

	history = hist();
	size_max = HIST_MAX_SIZE;
	if ((tmp = FT_HISTNEW(ft_strdup(str))) == NULL)
		return (FAIL);
	if (size_max != -1)
	{
		while (size_max <= history->size)
			del_first(history);
	}
	push(tmp, history);
	return (SUCCESS);
}
