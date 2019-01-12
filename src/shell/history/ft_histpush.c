/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_histpush.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 18:47:04 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:47:47 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "history.h"
/*
static int			getsize_max(void)
{
	char	*tmp;

	if ((tmp = ft_getenv_valu("HIST_SIZE")) == NULL)
		return (HIST_SIZE_DEFAULT);
	return (ft_atoi(tmp));
}
*/
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

int					ft_histpush(const char *str)
{
	int				size_max;
	t_hist			*tmp;
	t_stackhist		*history;

	history = ft_hist();
	size_max = 100; /*getsize_max();*/
	if ((tmp = FT_HISTNEW(ft_strdup(str))) == NULL)
		return (FAIL);
	if (size_max != -1)
	{
		while (size_max <= history->size)
			del_first(history);
	}
	push(tmp, history);
	ft_histdebug();
	return (SUCCESS);
}
